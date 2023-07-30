
D. Кратчайший путь
Ограничение времени 	3 секунды
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Дан взвешенный неориентированный граф.

Определите кратчайший путь между заданной парой вершин и выведите его.
Формат ввода

Первая строка содержит целые числа N и M (1 ≤ N ≤ 105, 1 ≤ M ≤ 3 ⋅ 105) — соответственно количество вершин и количество рёбер графа.

Следующие N строк описывают рёбра графа. Каждая из них содержит целые числа Ai, Bi и Wi (1 ≤ Ai, Bi ≤ N, 1 ≤ Wi ≤ 106) — соответственно номера вершин, соединённых ребром, и вес ребра.

Следующая строка содержит целые числа S и T (1 ≤ S, T ≤ N) — номера вершин, между которыми требуется найти кратчайший путь.
Формат вывода

В первой строке выведите одно целое число — длину кратчайшего пути между вершинами S и T.

Во второй строке выведите одно целое число K — количество вершин в кратчайшем пути.

В третьей строке выведите K целых чисел — номера вершин, составляющих кратчайший путь, в порядке следования от S к T.

Если кратчайших путей несколько, выведите любой из них.

Если кратчайшего пути не существует, выведите одно число -1.
Пример 1
Ввод
Вывод

6 4
1 2 7
2 4 8
4 5 1
4 3 100
3 1

	

115
4
3 4 2 1 

Пример 2
Ввод
Вывод

5 4
1 2 10
2 3 15
3 1 20
4 5 20
1 5

	

-1