n = int(input())
seq = list(map(int, input().split()))
prev_elems = [-1 for i in range(n)]
dp = [1 for i in range(n)]

ans = 0
for i in range(1, n):
    max_len = 1
    prev_elem = -1
    for j in range(i - 1, -1, -1):
        if seq[j] < seq[i] and dp[j] + 1 > max_len:
            max_len = dp[j] + 1
            prev_elem = j
    dp[i] = max_len
    prev_elems[i] = prev_elem

    if dp[i] > dp[ans]:
        ans = i

out = []
i = ans
while i != -1:
    out.append(seq[i])
    i = prev_elems[i]

for i in reversed(out):
    print(i, end=' ')
