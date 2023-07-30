
H. Кассы
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

На одном из московских вокзалов билеты продают N касс. Каждая касса работает без перерыва определенный промежуток времени по фиксированному расписанию (одному и тому же каждый день). Требуется определить, на протяжении какого времени в течение суток работают все кассы одновременно.

Формат ввода

Сначала вводится одно целое число N (0 < N ≤ 1000).

В каждой из следующих N строк через пробел расположены 4 целых числа, первые два из которых обозначают время открытия кассы в часах и минутах (часы — целое число от 0 до 23, минуты — целое число от 0 до 59), оставшиеся два — время закрытия в том же формате. Числа разделены пробелами.

Время открытия означает, что в соответствующую ему минуту касса уже работает, а время закрытия — что в соответствующую минуту касса уже не работает. Например, касса, открытая с 10 ч. 30 мин. до 18 ч. 30 мин., ежесуточно работает 480 минут.

Если время открытия совпадает с временем закрытия, то касса работает круглосуточно. Если первое время больше второго, то касса начинает работу до полуночи, а заканчивает — на следующий день.
Формат вывода

Требуется вывести одно число — суммарное время за сутки (в минутах), на протяжении которого работают все N касс.

Пример 1
Ввод
Вывод

3
1 0 23 0
12 0 12 0
22 0 2 0

	

120

Пример 2
Ввод
Вывод

2
9 30 14 0
14 15 21 0

	

0

Пример 3
Ввод
Вывод

2
14 00 18 00
10 00 14 01

	

1

Примечания

1) Первая касса работает с часу до 23 часов, вторая – круглосуточно, третья – с 22 часов до 2 часов ночи следующего дня. Таким образом, все три кассы одновременно работают с 22 до 23 часов и с часу до двух часов, то есть 120 минут.

2) Первая касса работает до 14 часов, а вторая начинает работать в 14 часов 15 минут, то есть одновременно кассы не работают.

3) Вместе кассы работают лишь одну минуту – с 14:00 до 14:01 (в 14:01 вторая касса уже не работает).