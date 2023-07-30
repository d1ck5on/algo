n, m = map(int, input().split())
events = []

for i in range(n):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    events.append([a, -1])
    events.append([b, 1])

points = list(map(int, input().split()))
for i in range(m):
    events.append([points[i], 0])

points_cnt = dict()
events.sort()
segments_cnt = 0
for i in range(len(events)):
    if events[i][1] == 0:
        points_cnt[events[i][0]] = segments_cnt
    segments_cnt -= events[i][1]

for i in range(m):
    print(points_cnt[points[i]], end=' ')
