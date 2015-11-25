/*
Title: Веб-поиск повышенной объективности
*/

Допустим, хочется делать поиск в вебе,
не [автозацикленный](http://lab.platfor.ma/puzyr-filtrov/) на предыдущем поведении пользователя.

Для этого есть [специальные поисковики](https://duckduckgo.com),
но на начало 2015 это частично возможно и в Google Search.

Cookie и DOM Storage
--------------------

Очевидно, надо запретить, _удалить_ и никогда не разрешать куки и Web (DOM) Storage 
для всех доменов Google ([addon](https://addons.mozilla.org/en-US/firefox/addon/cookie-controller/)).

Если человек уже заключил именной контракт с Гуглом, где обязался принимать cookies и DOM Storage 
для перепродажи Гуглом лично этого человека,
то Гугл выдал ему контрольные идентификаторы (бирка, "единый экаунт Google").
После чистки не стоит никуда вводить эти идентификаторы без принуждения.

Вместо gmail удобно использовать [openmailbox](https://openmailbox.org).
/*
Остальные "сервисы" вроде магазина игрушечных программ для микрокомпьютеров вообще не стоят упоминания для психически здорового человека.
*/

Без cookies и DOM Storage не работают настройки поиска, 
но некоторые из них до сих пор можно запрашивать параметром HTTP запроса вместо cookie:

* safe=off - не "оберегать" от порнографии (по умолчанию оберегать)
* hl=en&gws_rd=cr - главный язык английский и не перенаправляться на google.страна_моего_ip
* gbv=1 - какие-то мелочи будут работать без джаваскрипта

/*
https://www.google.com/search?safe=off&hl=en&gws_rd=cr&gbv=1&q=let_me_alone
*/

Поскольку браузеры свободно используют поиск во многих случаях, вроде просто набирания 
не-адреса в строке адреса, удобно познакомить с этими параметрами firefox:

Поиск с параметрами и выключенными куками в Firefox
---------------------------------------------------

Найти директорию searchplugins.

"%APPDATA%\Mozilla\Firefox\Profiles\XXXXXXX.default\searchplugins"

"%PROGRAM_FILES%\Mozilla Firefox\searchplugins"

Составить файл в формате [opensearch](http://www.opensearch.org/Specifications/OpenSearch/1.1#OpenSearch_description_document):


    <SearchPlugin xmlns="http://www.mozilla.org/2006/browser/search/">
    <ShortName>Clean Google</ShortName>
    <Description>Google Clean Search</Description>
    <InputEncoding>UTF-8</InputEncoding>
    <Image width="16" height="16">data:image/x-icon;base64,AAABAAEAEBAQAAEABAAoAQAAFgAAACgAAAAQAAAAIAAAAAEABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBREIAR0pIAExOTABcX10Ac3Z0AH+CgACUl5UAqayqALu+vADFyMYAztHPANXY1gDj5uQA7vHvAPz//QAAAAAAIiIiIiIiIiIiIiEAASIiIiIiKOyYMiIiIiGtIhCzIiIiINciImgSIiIibSAi2CIiIiIUh37jIiIiIiIQ7CIiIiIiIUfmIiIiIiIX5BpSIiIiIi5yJOIiIiIiLlIm4iIiIiIZYQzBIiIiIiB3zqUiIiIiIiAAACIiIiIiIiIiIiIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA</Image>
    <Url type="text/html" method="GET" template="https://www.google.com/search?safe=off&amp;hl=en&amp;gws_rd=cr&amp;gbv=1&amp;q={searchTerms}"/>
    <SearchForm>https://www.google.com/search?safe=off&amp;hl=en&amp;gws_rd=cr&amp;gbv=1</SearchForm> 
    </SearchPlugin>


Сохранить ([скачать](content/google-clean.xml)) его в searchplugins/название.xml.

Удалить оттуда все ненужные файлы.

Сохранность этой конструкции, ясно, низкая, ее надо [держать](content/cfe2-sa-searchplugins__snippet.cf) под cfengine, но можно немного отсрочить изменения и так:

Запретить апдейт Search Engines в браузере,
или вписать в xml инструкцию для обновлений с вашего сервера:

    <Url type="application/opensearchdescription+xml"
         rel="self"
         template="http://www.foo.com/mysearchdescription.xml" />

причем апдейты надо отдавать с нестандартным mime типом application/opensearchdescription+xml.

Если используется pentadactyl, vimperator или подобные,
то чтобы правильно работали команды группы open, 
можно также удалить лишние keywords типа bing и google, прячущиеся в _закладках_,
назначить свежесозданному engine в Manage Search Engines ключевое слово, например то же "google",
и выполнить :set defsearch=google

JS
--

Видимо, полезно, хоть и необязательно, не выполнять у себя обфусцированный javascript Гугла.

Для [одобряемых SEO](http://encosia.com/3-reasons-why-you-should-let-google-host-jquery-for-you/)
(неполноценных) веб-сайтов, не способных работать без Гугла, 
чаще всего достаточно разрешения googleapis.com и apis.google.com (по умолчанию в noscript).

Для "сервисов" Гугла понадобится разрешение для всего google.com, gstatic.com и тд, 
весь этот код, очевидно, надо запускать с теми же предосторожностями, как и любое другое adware.


Полностью и бесплатно избежать корреляции Гуглом нельзя, т.к. анонимные IP адреса Гугл 
расценивает как врагов бизнеса и пресекает обязательной капчей. 
Поэтому на 2015 анонимный поиск доступен только владельцам множества IP адресов, 
либо является платным (сервисы по автоматическому разгадке капчи индусами, 
однако они принимают чистую картинку, а Гугл направляет 
все усилия по усложнению выдирания этой картинки из капчи (недавняя recaptcha v2).
В обоих случаях анонимный поиск Гуглом доступен не массово
и в ближайшем будущем может стать невозможен совсем.

\- End of article -

