/*
Title: Тесла (Tesla coil)
*/

Катушка тесла (Tesla coil)
=============

У всех кто когда-либо занимался более-менее серьезно электроникой наверняка есть высоковольтный трансформатор или катушка Тесла.
Вот и я в качестве эксперимента с электричеством решил сделать одну.
>Everyone who ever did ham radio probably built or planned to build hi voltage 
transformer of Tesla coil. I also decided to build one.

Катушку намотал на трубе из ABS внешним диаметром 110 мм.
Использовал провод 0.20мм. Длина намотки 60 см. Количество витков - порядка 3000.
>Pipe is 91 cm length 11 cm in diameter, ABS. Wire is 0.2mm, the length of
winding is 60 cm. The number of turns is about 3000.

<img src="http://i.imgur.com/M4tjPG4.jpg" alt="Катушка, заготовка" height="600"/>

Тор сделан из алюминиевого рукава для вентиляции, диаметром 4 дюйма.
Никакие расчеты по емкости и индуктивости я не делал, резонансные частоты находил
экспериментально.
>Torus is made of aluminum flexible hose for ventilation. No calculations were made,
I find all resonances experimentally. For future experiments probably I'll do
adjustments of parameters.

Заземление у меня смешное, но какое есть, представляет собой лист жести 40 на 80 см,
закопанный в клумбу на глубину 20 см. Естественно, никакой серьезной нагрузки повесить
на него нельзя.
>I have funny grounding, it's a piece of iron 40 by 80 cm, put under the soil for about 20 cm. I can not put any serious load on it.

/*
![Тор](http://i.imgur.com/OcBUEB6.jpg)
*/
<img src="http://i.imgur.com/OcBUEB6.jpg" alt="Тор" width="600"/>

Крепление для тора - напечатано на принтере.
>Torus holder is 3d printed.

/*
![Первичка](http://i.imgur.com/of9lW4H.jpg)
*/
<img src="http://i.imgur.com/of9lW4H.jpg" alt="Первичка" width="600"/>

Барабан для первичной катушки тоже печатал на принтере, диаметр 20 см.
Количество витков намотал от балды. Тесла везде писал, что наилучший результат
получается с 1 витком, но мне пока не надо большое напряжение.
>The mount for primary coil is also 3d printed, 20 cm in diameter. The number
of turns is 10, but Tesla wrote that the best result should be with 1 turn only.

/*
![Крепление](http://i.imgur.com/uCFAvKC.jpg)
*/
<img src="http://i.imgur.com/uCFAvKC.jpg" alt="Крепление" width="600"/>

Крепления напечатаны из PLA.
Для основания использовал обычные кухонные доски из полиэтилена, толщиной около 1 см.
>Base plate is done from plastic cutting board of 1 cm thikness.

/*
![Под теслой](http://i.imgur.com/xrndGTy.jpg)
*/
<img src="http://i.imgur.com/xrndGTy.jpg" alt="Под теслой" width="600"/>

Доски разделены пластиковыми трубками, и стянуты болтами.
/*
![Вид в трубе](http://i.imgur.com/gF3PRtr.jpg)
*/
<img src="http://i.imgur.com/gF3PRtr.jpg" alt="Вид в трубе" width="600"/>

Генератор для накачки сначала паял сам, потом отказался, и решил просто накачивать от 
стандартного генератора.
>The first version of electronics was made by myself, but after I desided to use standard
signal generator.

Накачка осуществлялась пачками, резонансная частота теслы порядка 68кГц, частота следования
импульсов 500 Гц. Напряжение питания транзистора 24 вольта.
>The resonant frequency is about 68kHz, the frequency of pulses is 500Hz. Voltage is 24V.
/*
[![Моя Катушка](http://img.youtube.com/vi/mwR_t2aTmpA/0.jpg)](https://www.youtube.com/watch?v=mwR_t2aTmpA)
*/

<embed src="http://www.youtube.com/v/mwR_t2aTmpA" type="application/x-shockwave-flash" allowscriptaccess="always" width="640" height="480"></embed>


На теслу я подавал всего лишь 24 Ватта при скважности импульсов в пачке 50%, потом увеличил до 30 Ватт, скважностью до 75%.
>I put 24 watts only with 50% duty cycle, after increased to 30 watts, 
with 75% duty cycle.

Уже при 24 Ваттах все в радиусе 1.5 метра поляризовалось, отвертка-пробник светилась на расстоянии 1 метр в руке. При касании до заземления разряд уже ощущался прилично.
>At 24 watts everything was polarized in 1.5 m from the coil, the tester was lit in 1 m from the coil. If to touch ground - the shock is quite sensitive.

Искра получилась всего 2 см при 30 ваттах, но пока это не так важно.
Мой друг подсказал мне как можно получить при 30 ваттах искру в 20 см, но дома запускать
такой агрегат я бы побоялся. Тем более что он попалил свой осциллограф.
> At 30 watts the spark length was about 2 cm.
My friend advised me how to get 20 cm spark at this power. But most probably I'll not repeat his experiment at home, because he already burned his oscilloscope :).

Вот его видео.
>Here is his video

<embed src="http://www.youtube.com/v/KPrYUpmuhaI" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" width="640" height="480"></embed>

Следующим летом планирую провести несколько экспериментов с катушкой.
>Next summer plan to do some experiments with high voltage.
- - -
\- End of page -