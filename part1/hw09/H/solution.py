n, m = map(int, input().split())
mass = list(map(int, input().split()))
cost = list(map(int, input().split()))

dp = [[-1 for i in range(m + 1)] for i in range(n + 1)]
dp[0][0] = 0

for i in range(1, n + 1):
    dp[i] = dp[i - 1].copy()
    for j in range(m - mass[i - 1], -1, -1):
        if dp[i][j] != -1:
            dp[i][j + mass[i - 1]] = max(dp[i][j + mass[i - 1]], dp[i][j] +
                                         cost[i - 1])

i = n
j = 0
for k in range(m + 1):
    if dp[i][j] < dp[i][k]:
        j = k

while i != 0:
    if dp[i][j] == dp[i - 1][j]:
        i -= 1
    else:
        print(i)
        j -= mass[i - 1]
        i -= 1
