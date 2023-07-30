
D. Конденсация графа
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Вам задан ориентированный граф с N вершинами и M ребрами (1 ≤ N ≤ 20000, 1 ≤ M ≤ 200000). Найдите компоненты сильной связности заданного графа и топологически отсортируйте его конденсацию.

Формат ввода

Граф задан во входном файле следующим образом: первая строка содержит числа N и M. Каждая из следующих M строк содержит описание ребра — два целых числа из диапазона от 1 до N — номера начала и конца ребра.

Формат вывода

На первой строке выведите число K — количество компонент сильной связности в заданном графе. На следующей строке выведите N чисел — для каждой вершины выведите номер компоненты сильной связности, которой принадлежит эта вершина. Компоненты сильной связности должны быть занумерованы таким образом, чтобы для любого ребра номер компоненты сильной связности его начала не превышал номера компоненты сильной связности его конца.

Пример 1
Ввод
Вывод

10 19
1 4
7 8
5 10
8 9
9 6
2 6
6 2
3 8
9 2
7 2
9 7
4 5
3 6
7 3
6 7
10 8
10 1
2 9
2 7

	

2
1 2 2 1 1 2 2 2 2 1 

Пример 2
Ввод
Вывод

10 20
7 3
2 6
7 1
10 9
6 10
5 1
2 4
5 4
10 4
1 7
5 2
7 5
8 6
10 8
1 6
3 8
4 3
1 8
10 1
8 2

	

2
1 1 1 1 1 1 1 1 2 1 