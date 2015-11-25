/* 
   pcap dump analyser
   for bittorrent handshakes
   2013
   $Id$
   gcc -g -o captorrents -lpcap captorrents.c
*/

#include <stdio.h>
#include <pcap.h>

#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

#include <sys/types.h>
#include <dirent.h>

#include <sys/stat.h>
#include <unistd.h>

#define MAX_HASH	41
#define MAX_IP		16
#define MAX_FNAME	512
#define MAX_TRANSFER	100
#define MAX_NAMECACHE	100
struct { char hash[MAX_HASH]; char userip[MAX_IP]; int dumped; } transfer[MAX_TRANSFER];
struct { char hash[MAX_HASH]; char filename[MAX_FNAME]; } namecache[MAX_NAMECACHE];
int ntransfer=0;
int ncache=0;

char* Monitored_ip_prefix=NULL; int mip_len=0;
int Dump_interval=60;	// sec
char* Dump_directory=NULL;
int Opt_verbose=0;
int Opt_resolve=0;
int Opt_purge_interval=50;


/* 
	cache_index_by_hash()
	returns hash index in namecache or 0 (unknown)
*/
int 
cache_index_by_hash(char* h)
{
int ci;
for (ci=1; ci<ncache; ci++) {
	if (strncmp(h, namecache[ci].hash, MAX_HASH)==0) {
		return ci;
	}
}
return 0;
}


/*
	get_torrent_info_by_hash()
	Вносит в buf строку информации о хеше с публичного поисковика
	Возвращает 0 при успехе, -1 иначе
*/
int
get_torrent_info_by_hash( char* hash, char* buf, int maxlen ) {
	FILE* lfile;
	char* res;
	char cmd[1024];
	char* n;

	snprintf (cmd,1023, "lynx -dump -width=1024 \"https://btdigg.org/search?q&info_hash=%s&hl=ru\" | awk '/Имя:/ {$1=\"\"; printf \"%%s \", $_} /Размер:/ {$1=\"\"; printf \"&nbsp;&nbsp;%%s\", $_} /Torrent not found/ {printf \"+++unknown+++\"} END {printf \"\\n\"}'", hash);
//	fputs (cmd, stderr); fputc('\n',stderr);
	lfile = popen (cmd, "r");
	res = fgets (buf, maxlen, lfile);
	n=index(buf, '\n'); if (n!=NULL) { *n='\0'; }
	fclose (lfile);
	n=strstr(buf, "+++unknown+++");
	if (res!=NULL && n==NULL) {
		return 0;
	} else {
		snprintf (cmd,1023, "lynx -source \"http://www.torrentreactor.net/torrent-search/?words=%s\" | awk '/<h1 class=blockheader>/ {gsub(\"<[^>]*>|\\r\",\"\"); printf (\"%%s \", $_)} /Total size:/ {gsub(\"(<[^>]*>)|(Total size:)|,|\\r\",\"\"); printf (\"&nbsp;&nbsp;%%s \", $_)} /(No results|not) found/ {printf \"+++unknown+++\"} END {printf \"\\n\";}'", hash);
//	fputs (cmd, stderr); fputc('\n',stderr);
		lfile = popen (cmd, "r");
		res = fgets (buf, maxlen, lfile);
		n=index(buf, '\n'); if (n!=NULL) { *n='\0'; }
		fclose (lfile);
		n=strstr(buf, "+++unknown+++");
		if (res!=NULL && n==NULL) {
			return 0;
		} else {
			snprintf (buf, maxlen, "Unknown: %s", hash);
			return 1;
		}
	}
}


/*
 * Function:    process_packet()
 *
 *		Сортирует хэндшейки, заполняет таблицы transfer и namehash
 *
 *              for simplification, in this sample, assume the
 *              following about the captured packet data:
 *                      - the addresses are IPv4 addresses
 *                      - the data link type is ethernet
 *                      - ethernet encapsulation, according to RFC 894, is used.
 *
 * Return:      0 upon success
 *              -1 on failure (if packet data was cut off before IP addresses).
 */
void
process_packet(u_char *user, const struct pcap_pkthdr *hdr, const u_char *data)
{
        int ipaddr_offset = 26; /* 14 bytes for MAC header +
                          * 12 byte offset into IP header for IP addresses
                          */
	char src_ip[16]; char dst_ip[16];
	int bt_offset = 0x36;
	int bt_protolength;
	u_char* BT_SIGNATURE="BitTorrent"; const int BT_SIGN_LEN=10;
	int bt_filehash_offset;
	char bt_filehash[41];
	int pt;

	if (ntransfer>=MAX_TRANSFER-1 || ncache>=MAX_NAMECACHE-1) {
		return;
	}

/*        if (hdr->caplen < 30) {
                // captured data is not long enough to extract IP address
                fprintf(stderr,
                        "Error: not enough captured packet data present to extract IP addresses.\n");
                return;
        }
*/              

	// torrents
	if (hdr->caplen < bt_offset+1+BT_SIGN_LEN) {
		//not enough captured packet data
		return;
	}

	if ( strncmp (&(data[bt_offset+1]), BT_SIGNATURE, BT_SIGN_LEN)!=0 ) {
		//fprintf(stderr, "bt proto not detected!\n");
		return;
	}

        if (snprintf (src_ip, sizeof(src_ip), "%d.%d.%d.%d", data[ipaddr_offset], data[ipaddr_offset+1], data[ipaddr_offset+2], data[ipaddr_offset+3]) < 0 ) {
		return;
	}
        if (snprintf (dst_ip, sizeof(dst_ip), "%d.%d.%d.%d", data[ipaddr_offset+4], data[ipaddr_offset+5], data[ipaddr_offset+6], data[ipaddr_offset+7]) < 0 ) {
		return;
	}

	bt_protolength = data[bt_offset];
	bt_filehash_offset = bt_offset+1+bt_protolength+8; // 8 "reserved extension bytes"
	if (hdr->caplen < bt_filehash_offset+20) {
		//not enough captured packet data
		return;
	}
	if (snprintf (bt_filehash, sizeof(bt_filehash), "%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx%.2hhx", 
		data[bt_filehash_offset], data[bt_filehash_offset+1],
		data[bt_filehash_offset+2], data[bt_filehash_offset+3],
		data[bt_filehash_offset+4], data[bt_filehash_offset+5],
		data[bt_filehash_offset+6], data[bt_filehash_offset+7],
		data[bt_filehash_offset+8], data[bt_filehash_offset+9],
		data[bt_filehash_offset+10], data[bt_filehash_offset+11],
		data[bt_filehash_offset+12], data[bt_filehash_offset+13],
		data[bt_filehash_offset+14], data[bt_filehash_offset+15],
		data[bt_filehash_offset+16], data[bt_filehash_offset+17],
		data[bt_filehash_offset+18], data[bt_filehash_offset+19] ) < 0 ) {
			return;
	}

	for (pt=0; pt<ntransfer; pt++) {
		if ( (strncmp (transfer[pt].hash, bt_filehash, MAX_HASH)==0) &&
		 ((strncmp (transfer[pt].userip, src_ip, MAX_IP)==0) || 
		  (strncmp (transfer[pt].userip, dst_ip, MAX_IP)==0)) ) {
//			fprintf (stderr, "transfer already in table\n");
			return;
		}
	}
//	fprintf (stderr, "new userip-hash combination\n");
	strncpy (transfer[ntransfer].hash, bt_filehash, MAX_HASH);
	transfer[ntransfer].hash[MAX_HASH-1]='\0';
	if (strncmp (src_ip, Monitored_ip_prefix, mip_len)==0 ) {
		strncpy (transfer[ntransfer].userip, src_ip, MAX_IP);
	} else
	 if (strncmp (dst_ip, Monitored_ip_prefix, mip_len)==0 ) {
		strncpy (transfer[ntransfer].userip, dst_ip, MAX_IP);
	} else return;
	transfer[ntransfer].userip[MAX_IP-1]='\0';
	transfer[ntransfer].dumped=0;
	ntransfer++;

	if ((Opt_resolve==1) && (cache_index_by_hash (bt_filehash)==0) ) {
	  // new hash value
	  strncpy (namecache[ncache].hash, bt_filehash, MAX_HASH);
	  get_torrent_info_by_hash (bt_filehash, namecache[ncache].filename, MAX_FNAME);
	  ncache++;

	}

        //packets++; /* keep a running total of number of packets processed */
}


/*
	cleandir()
	deletes files matching prefix* from the directory
*/
int cleandir(const char *directory, const char *prefix) {
  struct dirent *entry;
  struct stat ds; time_t now;
  DIR *dp;
  char fn[1024];

  dp = opendir(directory);
  if (dp == NULL) {
    perror(directory);
    return -1;
  }

  time(&now);
  while ((entry = readdir(dp))) {
    if (strncmp (entry->d_name, prefix, strlen(prefix))==0) {
      snprintf (fn, 1023, "%s/%s", directory, entry->d_name);
      if (stat(fn, &ds) ==-1) {
	fprintf (stderr, "Can't stat %s\n", fn);
	return -1;
      }
//      fprintf (stderr, "purge diff %d max %d\n", now-ds.st_mtime, Opt_purge_interval);
      if ((now-ds.st_mtime) < Opt_purge_interval)
	continue;
      if (unlink( fn )==-1) {
	fprintf (stderr, "Can't remove %s\n", fn);
	return -1;
      }
    }
  }
  closedir(dp);
  return 0;
}


/*  
	dump()
	Выводит таблицу transfer, обнуляет ее
*/
void 
dump() {
	int mp; int np;
	int cache_index;

	FILE* ipfile; char ipfilename[1024];

/*	for (mp=0; mp<ncache; mp++) {
		fprintf(stderr, "%d: hash %s filename %s\n", mp, namecache[mp].hash, namecache[mp].filename);
	}
*/
	if (cleandir(Dump_directory, Monitored_ip_prefix)==-1)
	    exit(2);
	for (mp=0; mp<ntransfer; mp++) {
	 if (transfer[mp].dumped==0) {
		if (Opt_verbose==1)
			fprintf(stdout, "client %s:\n", transfer[mp].userip);
		snprintf (ipfilename, 1023, "%s/%s.html", Dump_directory, transfer[mp].userip);
		ipfile=fopen(ipfilename, "w");
		for (np=mp; np<ntransfer; np++) {
			if (strncmp(transfer[mp].userip, transfer[np].userip, MAX_IP)==0) {
				cache_index = cache_index_by_hash(transfer[np].hash);
				if (Opt_verbose==1)
					fprintf( stdout, "  hash %s name %s\n", transfer[np].hash, namecache[cache_index].filename );
				fprintf( ipfile, "<a href=\"https://btdigg.org/search?q&info_hash=%s&hl=ru\" class=\"torrents\">%s</a><br>\n", transfer[np].hash, namecache[cache_index].filename);
				transfer[np].dumped=1;
			}
		}
		fclose(ipfile);
	 }
	}
	for (mp=0; mp<ntransfer; mp++) {   // на всякий случай
		transfer[mp].userip[0]='\0';
		transfer[mp].hash[0]='\0';
		transfer[mp].dumped=0;
	}
	ntransfer=0;
}


static void
usage(void)
{
	fprintf(stderr,"Usage:\n");
	fprintf(stderr,"  captorrents -a prefix -d directory [-i dump interval] [-p purge interval] [-v] [-r] [file]\n");
	fprintf(stderr,"Finds BitTorrent TCP handshakes of <prefix> IPs in pcap <file> or stdin, \n");
	fprintf(stderr,"dumps html files to <directory> every <dump interval> seconds (default 60).\n");
	fprintf(stderr,"  -p  maximum age for expired html dump (default 50 sec)\n");
	fprintf(stderr,"  -v  dump results to stdout too\n");
	fprintf(stderr,"  -r  resolve hash names using btdigg.org and torrentreactor.net (lynx, awk required)\n");
	fprintf(stderr,"Examples:\n");
	fprintf(stderr,"  sudo tcpdump -n -i eth0 -w - -U 'tcp[21:4]==0x42697454 and tcp[25:4]==0x6f727265' | captorrents -a 192.168. -d ./torrdump -i 60 -p 300 -r -v\n");
	fprintf(stderr,"  captorrents -a 10. -d ./torrdump -v pcap.dump\n");
	exit(1);
}


int
main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c;

	FILE *infile; int infd;
	int cnr;
        pcap_t *p;               /* packet capture descriptor */
        char errbuf[PCAP_ERRBUF_SIZE];  /* buffer to hold error text */
        char prestr[80];         /* prefix string for errors from pcap_perror */

	time_t nextdump, now;

        fd_set rfds;
	int nfds;
        struct timeval tv;
        int retval;

	int disp_res;


	while ((c = getopt(argc, argv, "a:d:i:vrp:h?")) != -1) {
		switch (c) {
		case 'a':
			Monitored_ip_prefix = optarg;
			break;
		case 'd':
			Dump_directory = optarg;
			break;
		case 'i':
			Dump_interval = atoi(optarg);
			break;
		case 'v':
			Opt_verbose = 1;
			break;
		case 'r':
			Opt_resolve = 1;
			break;
		case 'p':
			Opt_purge_interval = atoi(optarg);
			break;
		default:
			usage();
		}
	}
	argc -= optind;
	argv += optind;

	if (Monitored_ip_prefix==NULL || Dump_directory==NULL) {
		fprintf (stderr, "Parameters required\n");
		usage();
	}
	mip_len = strlen (Monitored_ip_prefix)-1;

        if (argc==1) {
		infile=fopen(argv[0], "r");
		if (infile==NULL) {
			perror("Error opening file for reading");
			exit (2);
		}
	} else if (argc==0) {
                infile=stdin;
	} else {
		fprintf (stderr, "Too much arguments\n");
		usage();
	}

	infd = fileno(infile);
//	fprintf(stderr, "using fd %d for select()\n", infd);
	nfds = infd+1;

	if (ncache==0) {
		namecache[0].hash[0]='\0';
		strncpy (namecache[0].filename, "unknown", 7);
		ncache=1;
	}

        if (!(p = pcap_fopen_offline(infile, errbuf))) {
                fprintf(stderr, "Error in opening file for reading: %s\n", errbuf);
                exit(2);
        }

	time (&now);
	nextdump = now + Dump_interval;

	do {
	  time (&now);
	  if (nextdump <= now) {
		dump();
	  	time (&now);
		nextdump = now + Dump_interval;
	  }
          /* Watch infd to see when it has input. */
          FD_ZERO(&rfds);
          FD_SET(infd, &rfds);
          /* Wait up to x sec */
          tv.tv_sec = nextdump - now;
          tv.tv_usec = 0;
          retval = select(nfds, &rfds, NULL, NULL, &tv);
          /* Don't rely on the value of tv now! */
          if (retval == -1) {
                perror("select()");
		break;
	  }
          else if (retval) {
             	/* "Data is available now.\n"); */
            	/* FD_ISSET(0, &rfds) will be true. */
	        //if (pcap_dispatch(p, 0, &print_packet, (char *)0) < 0) {
	        disp_res=pcap_dispatch(p, 1, &process_packet, (char *)0);
		if (disp_res<0) {
	                sprintf(prestr,"Error reading packets");
	                pcap_perror(p,prestr);
	                exit(4);
	        }
  	  } else {
		//No data within timeout
		dump();
		time (&now);
		nextdump = now + Dump_interval;
  	  }

//	} while (disp_res>0);	// select()
	} while (1);	// select()

	dump();
        pcap_close(p);
}

