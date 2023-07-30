n, m = map(int, input().split())
events = []
for i in range(m):
    s, f = map(int, input().split())
    events.append((s, -1))
    events.append((f, 1))
events.sort()

students_cnt = 0

observers_cnt = 0
observers_end = 0
for i in range(len(events)):
    observers_cnt -= events[i][1]

    if observers_cnt == 0:
        observers_end = events[i][0] + 1

    if observers_cnt == 1 and events[i][1] < 0:
        students_cnt += events[i][0] - observers_end

if observers_end < n:
    students_cnt += n - observers_end
print(students_cnt)
