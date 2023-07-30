n = int(input())
A = list(map(int, input().split()))

max_sum = A[0]

for i in range(1, n):
    A[i] = max(A[i], A[i - 1] + A[i])
    max_sum = max(A[i], max_sum)

print(max_sum)
