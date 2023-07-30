
D. Опасный маршрут
Ограничение времени 	1 секунда
Ограничение памяти 	64Mb
Ввод 	стандартный ввод или input.txt
Вывод 	стандартный вывод или output.txt

Профессор Флойд живёт в очень опасном районе города. Ежедневно бандиты грабят на улицах прохожих. Читая криминальную хронику, профессор Флойд вычислил вероятность быть ограбленным при проходе по каждой улице города.

Теперь он хочет найти наиболее безопасный путь от дома до университета, в котором он преподаёт. Иными словами, он хочет найти путь от дома до университета, для которого вероятность быть ограбленным минимальна.
Формат ввода

В первой строке находятся два числа N и M — количество зданий и количество улиц, соединяющих здания (1 ≤ N ≤ 100, 1 ≤ M ≤ (N × (N−1)) / 2). В следующей строке находятся числа S и E — номер дома, в котором живёт профессор и номер дома, в котором находится университет соответственно. Далее в M строках расположены описания дорог: 3 целых числа si, ei, pi — здания, в которых начинается и заканчивается дорога и вероятность в процентах быть ограбленным, пройдя по дороге соответственно (1 ≤ si, ei ≤ N, 0 ≤ pi ≤ 100, дороги двунаправленные). Гарантируется, что существует хотя бы один путь от дома профессора до университета.
Формат вывода

Необходимо вывести одно число - минимальную возможную вероятность быть ограбленным. Абсолютная погрешность ответа не должна превышать 10-3.

Пример 1
Ввод
Вывод

3 3
1 3
1 2 20
1 3 50
2 3 20

	

0.36

Пример 2
Ввод
Вывод

2 1
1 2
1 2 100

	

1.0