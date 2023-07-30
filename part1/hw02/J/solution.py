from collections import deque

n = int(input())
arr = list(map(int, input().split()))
queue = deque(arr)

max_team = max(arr)
res = []
k = 0
curr_team = queue.popleft()
for i in range(n - 1):
    if curr_team == max_team:
        break

    next_team = queue.popleft()

    res.append([curr_team, next_team])
    k += 1

    queue.append(min(curr_team, next_team))
    curr_team = max(curr_team, next_team)

q = int(input())
for i in range(q):
    req = int(input())
    if req <= k:
        print(res[req-1][0], res[req-1][1])
    else:
        print(max_team, queue[(req - k - 1) % (n - 1)])
