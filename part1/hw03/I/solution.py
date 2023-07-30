i1, i2, i3, i4 = 0, 0, 0, 0
n1 = int(input())
a1 = list(map(int, input().split()))
n2 = int(input())
a2 = list(map(int, input().split()))
n3 = int(input())
a3 = list(map(int, input().split()))
n4 = int(input())
a4 = list(map(int, input().split()))
a1.sort()
a2.sort()
a3.sort()
a4.sort()
min_main = min(a1[0], a2[0], a3[0], a4[0])
max_main = max(a1[0], a2[0], a3[0], a4[0])
diff = abs(max_main - min_main)
first_min = i1
second_min = i2
third_min = i3
fourth_min = i4
while i1 < n1 and i2 < n2 and i3 < n3 and i4 < n4:
    min_main = min(a1[i1], a2[i2], a3[i3], a4[i4])
    max_main = max(a1[i1], a2[i2], a3[i3], a4[i4])
    diffR = abs(max_main - min_main)
    if diffR < diff:
        diff = diffR
        first_min = i1
        second_min = i2
        third_min = i3
        fourth_min = i4
    if diffR < 1:
        break
    while i1 < len(a1) and min_main == a1[i1]:
        i1 += 1
    while i2 < len(a2) and min_main == a2[i2]:
        i2 += 1
    while i3 < len(a3) and min_main == a3[i3]:
        i3 += 1
    while i4 < len(a4) and min_main == a4[i4]:
        i4 += 1
print(a1[first_min], a2[second_min], a3[third_min], a4[fourth_min])
