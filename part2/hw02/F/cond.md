
F. Производство деталей
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Предприятие «Авто-2010» выпускает двигатели для известных во всём мире автомобилей. Двигатель состоит ровно из n деталей, пронумерованных от 1 до n, при этом деталь с номером i изготавливается за pi секунд. Специфика предприятия «Авто-2010» заключается в том, что там одновременно может изготавливаться лишь одна деталь двигателя. Для производства некоторых деталей необходимо иметь предварительно изготовленный набор других деталей.

Генеральный директор «Авто-2010» поставил перед предприятием амбициозную задачу — за наименьшее время изготовить деталь с номером 1, чтобы представить её на выставке.

Требуется написать программу, которая по заданным зависимостям порядка производства между деталями найдёт наименьшее время, за которое можно произвести деталь с номером 1.
Формат ввода

Первая строка входного файла содержит число n (1 ≤ n ≤ 100000) — количество деталей двигателя. Вторая строка содержит n натуральных чисел p1, p2, pn, определяющих время изготовления каждой детали в секундах. Время для изготовления каждой детали не превосходит 109 секунд.

Каждая из последующих n строк входного файла описывает характеристики производства деталей. Здесь i-я строка содержит число деталей ki, которые требуются для производства детали с номером i, а также их номера. В i-й строке нет повторяющихся номеров деталей. Сумма всех чисел ki не превосходит 200000.

Известно, что не существует циклических зависимостей в производстве деталей.
Формат вывода

В первой строке выходного файла должны содержаться два числа: минимальное время (в секундах), необходимое для скорейшего производства детали с номером 1 и число k деталей, которые необходимо для этого произвести. Во второй строке требуется вывести через пробел k чисел — номера деталей в том порядке, в котором следует их производить для скорейшего производства детали с номером 1.

Пример 1
Ввод
Вывод

3
100 200 300
1 2
0
2 2 1

	

300 2
2 1

Пример 2
Ввод
Вывод

2
2 3
1 2
0

	

5 2
2 1

Пример 3
Ввод
Вывод

4
2 3 4 5
2 3 2
1 3
0
2 1 3

	

9 3
3 2 1