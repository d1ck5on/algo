n = int(input())
events = []
offices_cnt = 0
for i in range(n):
    start_h, start_m, fin_h, fin_m = map(int, input().split())
    if start_h * 60 + start_m >= fin_h * 60 + fin_m:
        events.append([start_h, start_m, 1])
        events.append([23, 60, -1])
        events.append([0, 0, 1])
        events.append([fin_h, fin_m, -1])
    else:
        events.append([start_h, start_m, 1])
        events.append([fin_h, fin_m, -1])

max_offices_cnt_start = 0
sum_time = 0

events.sort()
for i in range(len(events)):
    offices_cnt += events[i][2]

    if offices_cnt == n:
        max_offices_cnt_start = events[i][0] * 60 + events[i][1]
    elif offices_cnt == n - 1 and events[i][2] < 0:
        sum_time += events[i][0] * 60 + events[i][1] - max_offices_cnt_start

print(sum_time)
