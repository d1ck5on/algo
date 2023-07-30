from collections import deque


deq = deque()

n, k = map(int, input().split())
arr = list(map(int, input().split()))

for i in range(k):
    if len(deq) == 0:
        deq.append(arr[i])
        continue

    while (len(deq) > 0 and deq[-1] > arr[i]):
        deq.pop()

    deq.append(arr[i])

print(deq[0])

ptr = 1
while ptr + k - 1 < n:
    if arr[ptr - 1] == deq[0]:
        deq.popleft()

    while (len(deq) > 0 and deq[-1] > arr[ptr + k - 1]):
        deq.pop()

    deq.append(arr[ptr + k - 1])

    print(deq[0])
    ptr += 1
