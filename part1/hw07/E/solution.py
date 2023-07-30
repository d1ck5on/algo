n, m = map(int, input().split())
dp = [[0 for i in range(m)] for i in range(n)]
dp[0][0] = 1
for y in range(1, n):
    for x in range(1, m):
        if x - 2 >= 0 and y - 1 >= 0:
            dp[y][x] += dp[y - 1][x - 2]
        if x - 1 >= 0 and y - 2 >= 0:
            dp[y][x] += dp[y - 2][x - 1]
print(dp[-1][-1])
