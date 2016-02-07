/*
Title: Мой робот, что сделано, часть 2 (My Robot progress, part 2)
*/

[2016.02.06]

[DIY Humanoid Robot Assistant](http://igg.me/to/diyrobot)

Я начал камапанию по сбору средств на ускорение строительства прототипа домашнего робота,
который может оказаться полезен другим людям.

Основные причины по которым я это сделал:

1. Отсутсвие китов для строительства полноразмерных роботов (не игрушек).
2. Стоимость готовых роботов, способных хоть что-то сделать в доме - от $10k и выше.
3. Даже если бы была возможность купить такого робота, то огромным минусом была бы
невозможность его программировать так как я хочу. 


> I have started the campaign to speed up the creation of household robot prototype
> because this could be useful for other people.
>
> The main reasons why I started it are:
>
> 1. There is no DIY kit for adult sized humanoid robots (not toys).
> 2. The cost of existing robot, which could do something as household robot, is starting from $10k+
> 3. Even if I can buy adult size robot - I'm not sure that I'll be able to program it myself.


[2016.01.25]

На выходных выпилил платки для драйверов моторчиков, начал их паять.

<img src="http://i.imgur.com/Ns04f03.jpg" alt="Hand_drv" width="600"/>
<img src="http://i.imgur.com/6KELyUf.jpg" alt="Hand_drv1" width="600"/>

Далее нужно убедиться что они не сгорят при том варианте, в котором я собираюсь
их использовать.


[2016.01.22]

Выпилил платку для гироскопа, перепаял его, упростил схему. Питается 9 DOF сенсор от USB порта,
3.3 вольта я получаю просто через 2 диода. И сглаживаю пульсации конденсатором.

Надо заметить, что когда я использовал 2 DC-DC конвертора, на 5.0 и 3.3 вольта, то из-за
 пульсаций I2C шина работала со сбоями и сенсор подвисал через случайные интервалы времени. 
А с диодами работает как часы. Ни единого сбоя за двое суток.

<img src="http://i.imgur.com/hqFsh3L.jpg" alt="Gyro_top" width="600"/>
<img src="http://i.imgur.com/4HIFfGw.jpg" alt="Gyro_bot" width="600"/>

Конечно, еше придется повозится с кодом и калибровками, но в целом, девайс получился рабочий.
Следующий шаг - установить это счастье на платформу.



\- End of article -

