/*
Title: Мой робот (My Robot)
*/

У меня есть "костыльная" теория, которая гласит, что все вещи, созданые людьми
являются костылями, нужными для эффективного ничегонеделания.

>I have a theory of "crutchs", which says that everything ever being done by humans are
crutches, created for humans to be as lazy as possible.

Предельным костылем который бы позволил ничего не делать является "костыль человека",
или человекоподобный робот.

>The ultimate crutch that could permit to be completly lazy I call "the crutch of human"
or human like robot :)

Поэтому РОБОТ:

>And that's why the ROBOT:

ТА-ДА-ААА!

>TA-DA!

![Робот, скетч](http://i.imgur.com/xZEKXIT.png)

Этот набросок был сделан только для определения основных пропорций, на рисунке не отображены
мышцы, а окончательные сочленения могут иметь другую форму или устройство.

> This sketch was done just to adjust main proportions of body, there is no muscles on the
sketch. All joint might have other shape or construction.

## Основные характеристики, которые хотелось бы релизовать:

1. Бинокулярное зрения, со всеми вытекающими достоинствами
2. Локомоция по горизонтальному полу в пределах одной квартиры.
3. Максимальная потребляемая мощность всех актуаторов и электроники не более 200 Ватт
4. Общее число степеней свободы около 100.
5. Запас хода батареи 10 часов.
6. Максимальный вес 50 кг

> ## Main characteristics to be implemented:
>
> 1. Binocular vision
> 2. Flat flor locomotion in one level appartment.
> 3. Max power is less than 200 Watt
> 4. The number of DOF is about 100.
> 5. Batery capacity work - up to 10 hours.
> 6. Max weight is 50 kg.

## Габариты

1. Рост в *стоячем* положении 140-150 см.
2. Длина шасси - 55 см.
3. Ширина по колесам 52 см.
4. Диметр колеса 25 см (стандартное 10 дюймовое колесо)
5. Длина руки от плеча до кончиков пацев - 80 см.
6. Ширина по плечам 36 см.
7. Бинокуляраня база 90 мм.

> ## Sizes
>
> 1. Max height is about 140-150 cm.
> 2. The length of the base box - 55 cm.
> 3. Width by wheels - 52 cm.
> 4. Wheel diameter 25 cm (10 inches)
> 5. Arm length - 80 cm.
> 6. Shoulders width - 36 cm.
> 7. Binocular vision base is 90 mm.

/*
![Предплечье](http://i.imgur.com/nR9ImuW.png)
*/
<img src="http://i.imgur.com/nR9ImuW.png" alt="Предплечье" width="600"/>

/*
![Плечо](http://i.imgur.com/T1xMFvn.png)
*/
<img src="http://i.imgur.com/T1xMFvn.png" alt="Плечо" width="600"/>


Планируется создание верхнего плечевого пояса аналогичное человеческому.
Теретически кисть руки имеет порядка 30 степеней свободы, однако не все они будут независимыми.

>Robot's arms are planned to be similar to human's.
Theoretically the palm of robot has about 30 DOF, but not all of them will be independent.

/*
![Кисть](http://i.imgur.com/c201ilj.png)
![Кисть внешняя сторона](http://i.imgur.com/AkFaPqZ.png)
*/
<img src="http://i.imgur.com/c201ilj.png" alt="Кисть" width="600"/>
<img src="http://i.imgur.com/AkFaPqZ.png" alt="Кисть внешняя сторона" width="600"/>


Робот будет иметь возможность приседать на базу, выглядеть это будет как-то так:

>The robot will have posibility to sit down on the base, it will look like following:

![Робот сидит](http://i.imgur.com/1eI12M3.png)

База сделана из обычного клеенного щита, их хвойных пород, толщиной 18мм.
Я посчитал что, дерево более удобно в обработке чем пластик, да и стоит дешевле.

>The base is made from usual wooden furinture pannels, of standard thickness.
The wood is chipper than plastic and easier to process.

/*
![База](http://i.imgur.com/Bd5Wybf.png)
*/
<img src="http://i.imgur.com/Bd5Wybf.png" alt="База" width="600"/>


База состоит из 2 половинок, на каждой половине установлена одна ось.
Две половинки соеденены продольной осью. Передняя ось может качаться относительно оси корпуса на небольшой
угол. При такой конструкции все 4 колеса касаются пола. Изначально предполагалось не разрезать доску, однако
неровности колес и кривизна пола приводят к тому, что иногда колеса проскальзывают.

>Tha base consists of 2 separate pieces, each piece have one axis.
Front and back pieces are connected with shaft and it permits to front panel to tilt.
With such construction all 4 wheels touch the ground.

/*
[![Base test](http://img.youtube.com/vi/CTTV3OHJAmU/0.jpg)](http://www.youtube.com/watch?v=CTTV3OHJAmU "Platform mechanics test")
*/
<embed src="http://www.youtube.com/v/CTTV3OHJAmU?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Этот редуктор я буду использовать в суставах робота.
>This drive will be used in the robot's joints.

/*
[![Cycloidal drive test](http://img.youtube.com/vi/POSKD3lSD8E/0.jpg)](http://www.youtube.com/watch?v=POSKD3lSD8E "Harmonic-like drive")
*/

<embed src="http://www.youtube.com/v/POSKD3lSD8E?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

/*
[![Калибровка и синхронное движение глаз робота](http://img.youtube.com/vi/om_hhY21Tbg/0.jpg)](http://www.youtube.com/watch?v=om_hhY21Tbg "Глаза робота")
*/

<embed src="http://www.youtube.com/v/om_hhY21Tbg?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

/*
[![Предыдущая калибровка глаз робота](http://img.youtube.com/vi/ExeVTvKDxZs/0.jpg)](http://www.youtube.com/watch?v=ExeVTvKDxZs "Глазы")
*/

<embed src="http://www.youtube.com/v/ExeVTvKDxZs?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>
/*
[![Хамелеон](http://img.youtube.com/vi/_HABjn7qLSY/0.jpg)](http://www.youtube.com/watch?v=_HABjn7qLSY "Глазы")
*/

<embed src="http://www.youtube.com/v/_HABjn7qLSY?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

/*
[![Проверка механики](http://img.youtube.com/vi/Hld-6YdsHQY/0.jpg)](http://www.youtube.com/watch?v=Hld-6YdsHQY "Глазы еще")
*/

<embed src="http://www.youtube.com/v/Hld-6YdsHQY?fs=1&amp;hl=ru_RU" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>


\- End of article -

