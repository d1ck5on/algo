n = int(input())
dp = [[1, 1], [2, 2]]
for i in range(2, n):
    dp.append([dp[i - 1][0] + dp[i - 1][1], dp[i - 1][0] + dp[i - 2][0]])
print(dp[n - 1][0] + dp[n - 1][1])
