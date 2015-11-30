/*
Title: Мой робот, что сделано (My Robot progress)
*/

Робота я начал делать с глаз.
Сначала нашел подходящую веб камеру, раскурочил ее и вытянул
из нее платку.

> I started to build robot from eyes. For the beginning I'd found appropriate
web-cam and extracted PCB from it.

Потом выточил карданов шарнир и приделал моторчики.
Я принципиально не использовал сервомоторы, из-за звука, который я ненавижу.
Для поворота глаз не требуется большое усилие и обычные моторчики постоянного тока
хорошо работают.

> After that I did cardan joint and attached motors to the frame.
I didn't use standard servo motors because I have the noise they produce.
To turn the eye there is not so much force needed and usual DC motors works
just fine.

Контроллер для управления глазом сделан на базе Arduino Micro 32u4, 
драйвер для управления моторами, ваял сам на базе TC4424.
Для определения положения глаза используется оптический сенсор, A9800,
управляющийся с Ардуино по SPI.
В дальнейшем были добавлены датчики Холла для определения нулевого положения
глаза.

> The controller for eyes was done on the base of Arduino Micro 32u4, the
morot's driver is on the base of TC4424. To read the eye position A9800
sensor was used. Later, Hall sensors were added to detect (0,0) position.

Вот как это выглядело в разобранном виде

![Глаза по частям](http://ic.pics.livejournal.com/maholet/24765393/16835/16835_600.jpg)
![Собранная рамка](http://ic.pics.livejournal.com/maholet/24765393/17146/17146_600.jpg)
![Камера установлена](http://ic.pics.livejournal.com/maholet/24765393/17392/17392_600.jpg)
![Камера, повернута](http://ic.pics.livejournal.com/maholet/24765393/17641/17641_600.jpg)

Потом я подумал, что неплохо бы иметь защиту для камеры и ограничитель хода рамки,
и он был также изготовлен.
> After, the protection of camera and the frame movement limiter was added.

![Платка с моторчиками](http://ic.pics.livejournal.com/maholet/24765393/25392/25392_600.jpg)
![Вид сбоку](http://ic.pics.livejournal.com/maholet/24765393/25120/25120_600.jpg)
![Поворот](http://ic.pics.livejournal.com/maholet/24765393/25811/25811_600.jpg)

В результате, глаз был собран и протестирован
> Finally the eye was assembled and tested.

<embed src="http://www.youtube.com/v/Hld-6YdsHQY" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Вторым шагом было проектирование черепа. Основной идеей было иметь голову, похожую 
на человеческую, но чтобы при этом в ней было достаточно места для установки плат.
Прототип черепа был выпилен сначала из обычного экструдированного пенополистирола,
причем тут он продается оклеенный бумагой с 2 сторон, и толщиной 6 мм - то что доктор
прописал.

> The second step was to make a head. The main idea were to make it human-like
and to have enough of space for electronics to put inside. EPP was used to
make first prototype, which is on the video below.

Белый череп на видео как раз сделан из пенополистирола, это просто модель.

<embed src="http://www.youtube.com/v/2QREt8x-ogc" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Потом я повторил процедуру и выпилил каркас черепа уже из поликарбоната.
В дальнейшем, я планирую сделать подобие черепа и закрепить на этом каркасе.
Потом, по быструхе, выпилил второй глаз, что заняло около 2 недель.
Установил их на череп и вот что получилось:
> Then, I did the frame from polycarbonate. Later I plan to make an outer part of skull
and mount it on this frame.

<embed src="http://www.youtube.com/v/_HABjn7qLSY" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Тут я тестировал механику, запустил случайные движения на целый день. Ничего таки 
не сломалось :)
> I tested the mechanics for the whole day - nothing had broken :)

- - -
Далее стал проектировать шею, торс и все что ниже. Так как я решил делать робота
человекоподобным, то я постарался сохранять пропорции человеческого тела.
>Then, I designed the neck, torso and everything below torso. As soon as I decided to 
build numanoid robot I tried to keep human body proportions.

<img src="http://i.imgur.com/foMxbFG.jpg" alt="Вид спереди" width="600"/>
<img src="http://i.imgur.com/9gwrIrD.jpg" alt="Вид сбоку" width="600"/>

Внутренняя часть торса напечатана из PLA, а внешняя из ABS но он мне не нравится, 
придется с ним что-то делать, очень уж ABS хрупкий. Может быть заменю его потом на PLA.
> Backbode is printed in PLA, and exterior of torso is done in ABS. ABS part is
too cracky, probably I remake it in the future.

Естественно, я разработал робота с ногами, однако, в силу того, что для программирования 
и испытания бипеда может понадбится больше места, чем у меня есть, поэтому,
я решил упростить задачу для первой итерации и вместо ног приделать телегу.
>Of cause, I designed the robot with legs but it's too hard to program and test biped
robot in limited space in my appartment. That's why I decided to simplify my task and
to make a wheeled platform instead of legs.

Телега была выбрана по нескольким причинам:

+ Она является сама по себе опорой для всего робота и никакого подвеса не надо 
будет делать.
+ Пол в квартире ровный, без порогов, так что для перемещения на колесах
будет тратиться меньше энергии чем у бипеда (зависит от ситуации, сложный вопрос).
+ В ящик можно засунуть батареи достаточно большой емкости, чтобы обеспечить
работу робота в течение, например, 10 часов без подзарядки.

>The wheeled base was chosen by some of reasons.
>
> +It's a support for all robot during all development time by itself.
> +The floor in appartment is flat, no doorsteps, one level, and wheeled base will spend 
>less energy for locomotion
> +The box is a storage for batteries.

Еще раз скажу, что телега - это всего лишь вариант нижней части, которая может быть 
в будущем заменена на ноги. Но переход на ноги это огромная часть работы, пока я бы хотел
сфокусироваться на бинокулярном зрении и манипуляторах.
>One more time, the wheeled base is one variant of lower robot's part, which might be replaced to legs in the future. But for now I would like to focus on vision and arms.

Телегу решил делать из стандартных частей, которых можно купить в магазине, если что.
Колеса обычные, 10 дюймовые, они имеют встроенные подшипники. 
Все крепится на клееном щите, недостающие пластмассовые кронштейны придуманы мной
и напечатаны на принтере.
>The base is made of standard parts which could be bought in any hardware store.
Wheels are of 10" size. Everything is mounted on one plane. All plastic parts are
designed and printed myself.

<img src="http://i.imgur.com/y0zaRo0.jpg" alt="Заготовки" width="600"/>
<img src="http://i.imgur.com/0rYZpvU.jpg" alt="Кронштейн" width="600"/>

<img src="http://i.imgur.com/g0c9y1k.jpg" alt="Кронштейн2" width="600"/>

<img src="http://i.imgur.com/8e73hzo.jpg" alt="Телега" width="600"/>

Дети, естественно, не могли пройти мимо телеги и катались на ней несколько дней.
>Kids were running on it couple of days.

Передавать вращение я решил с помощью зубчатых ремней, с шагом 5мм, для этого 
напечатал шкивы.
>The torque from motor to wheel is transmitted by timing belt.

<img src="http://i.imgur.com/HOfAO00.jpg" alt="Шкив" width="600"/>

Шкив надевается на колесо и зажимается хомутом. Держится за счет трения
и никаких дополнительных изменений в колесах я не делал.
> Pulley is mounted on the wheel with the ring clamp.

<img src="http://i.imgur.com/mqnAdpb.jpg" alt="Шкив на колесе" width="600"/>

Моторчик с редуктором выдает максимум 150 rpm, закрепляется в таком вот кронштейне
>Motors with reductor give 15 rpm, mounted in the holder.

<img src="http://i.imgur.com/iH1dG2F.jpg" alt="Кронштейн для мотора" width="600"/>

Так как ось выходит не по центру, то это позволяет довольно легко регулировать натяжение
зубчатого ремня, просто поворачивая мотор в кронштейне.
>Reductor exit shaft is offcentered and this permits to tighten the belt by turining
the motor in the mount.

Все распечатано в нужном количестве

<img src="http://i.imgur.com/79BTHVI.jpg" alt="Кронштейны для мотора" width="600"/>
<img src="http://i.imgur.com/eRvMYhN.jpg" alt="Шкивы" width="600"/>

/*
![Кронштейны](http://i.imgur.com/79BTHVI.jpg)
![Шкивы](http://i.imgur.com/eRvMYhN.jpg)
*/

Все смонтировано и сделан предварительный тест от аккумулятора
>The test of the base.

<embed src="http://www.youtube.com/v/CTTV3OHJAmU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Максимальная скорость телеги получилась порядка 1 метр в секунду.
С шумом моторов надо что-то делать, но не сейчас.
>Max speed of the base is 1m/s. It's a bit noisy, but I'll fix it later.

- - -
Согласно проекту, нижняя часть робота - от телеги до грудной клетки будет иметь некоторое
число сочленений, в которых я собирался использовать редукторы. 
У меня было несколько вариантов редукторов, но для старта я решил спроектировать 
циклоидальный редуктор, который похож принципом работы на гармоник драйв.
>Lower part has some reductors, and I'd built a harmonic-like one.

Сначала, я изготовил пробные шестеренки, чтобы посмотреть, как оно работает.
>First try.

<img src="http://i.imgur.com/qLU0frh.jpg" alt="Циклодрайв" width="600"/>
 
Распечатал несколько штук с различным понижающим числом.
Для работы выбрал редуктор с понижением 1:84.

Редуктор получился простой, до безобразия
>Cycloidal drive is very simple inside.

<img src="http://i.imgur.com/GbzoJjB.jpg" alt="Циклодрайв2" width="600"/>
<img src="http://i.imgur.com/akaebS5.jpg" alt="Циклодрайв3" width="600"/>

<embed src="http://www.youtube.com/v/POSKD3lSD8E" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Единственное, что меня смущает, какой момент сил выдержат пластиковые шестерни.
Но в любом случае, заменить пластик на металл я смогу всегда. Это будет запасной вариант.
>The only thing I bother about is the strength of plastic thees. Anyway I can make them 
in metal.

- - -
Пока я строил телегу, пришла идея как можно сделать руки робота.
И я быстренько бросился делать кисть. В общей сложности я провозился 3 недели
прежде, чем у меня получилось вот это
>While I was building the wheeled base I got some idea how to make the palm 
of robot. I spent about 3 weeks to get this:

<img src="http://i.imgur.com/4dKP2Dq.jpg" alt="Рука" width="600"/>
<img src="http://i.imgur.com/Rkbuxti.jpg" alt="Рука2" width="600"/>

Убедившись, что рука шевелится нормально, я отложил ее в сторону и вернулся
обратно к телеге.
>After I made sure everything works fine - I put aside the hand and came back to 
the base.
- - -
Продолжение следует...
>To be continued...

\- End of article -

