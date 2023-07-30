m, n = map(int, input().split())
dp = [[0 for i in range(n)] for i in range(m)]
for i in range(n):
    dp[0][i] = 1
for i in range(m):
    dp[i][0] = 1
for i in range(1, m):
    for j in range(1, n):
        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j]
print(dp[m - 1][n - 1])
