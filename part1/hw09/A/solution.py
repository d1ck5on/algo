n, m = map(int, input().split())
groups = list(map(int, input().split()))
for i in range(n):
    groups[i] = [groups[i], i + 1]
rooms = list(map(int, input().split()))
for i in range(m):
    rooms[i] = [rooms[i], i + 1]

groups.sort()
rooms.sort()

p = 0
distrib = []
g = 0
r = 0
while g < n and r < m:
    if groups[g][0] + 1 <= rooms[r][0]:
        p += 1
        distrib.append([groups[g][1], rooms[r][1]])
        g += 1
        r += 1
    else:
        r += 1
while g < n:
    distrib.append([groups[g][1], 0])
    g += 1
print(p)
distrib.sort()
for i in distrib:
    print(i[1], end=' ')
