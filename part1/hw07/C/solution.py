n = int(input())
A = [0 for i in range(n + 1)]
B = [0 for i in range(n + 1)]


for i in range(2, n + 1):
    min_cnt = A[i - 1] + 1
    B[i] = i - 1
    if i % 2 == 0 and A[i // 2] + 1 < min_cnt:
        min_cnt = A[i // 2] + 1
        B[i] = i // 2
    if i % 3 == 0 and A[i // 3] + 1 < min_cnt:
        min_cnt = A[i // 3] + 1
        B[i] = i // 3
    A[i] = min_cnt

print(A[n])

out = [str(n)]
i = n
while i != 1:
    i = B[i]
    out.append(str(i))

print(' '.join(reversed(out)))
