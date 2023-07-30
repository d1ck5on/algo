n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split())))
points.sort()

left = [0 for i in range(n)]
right = [0 for i in range(n)]
for i in range(1, n):
    diff = points[i][1] - points[i - 1][1]

    if diff >= 0:
        left[i] = left[i - 1] + diff
    else:
        left[i] = left[i - 1]

for i in range(n - 2, -1, -1):
    diff = points[i][1] - points[i + 1][1]

    if diff >= 0:
        right[i] = right[i + 1] + diff
    else:
        right[i] = right[i + 1]

m = int(input())
for i in range(m):
    s, f = map(int, input().split())
    if s < f:
        print(left[f - 1] - left[s - 1])
    else:
        print(right[f - 1] - right[s - 1])
