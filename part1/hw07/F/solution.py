n, m = map(int, input().split())
dp = [[0 for i in range(m)] for i in range(n)]
dp[0][0] = 1
for d in range(m + n):
    y = 0
    x = d
    while y <= d and x >= 0:
        if y < n and x < m:
            if y + 1 < n and x - 2 >= 0:
                dp[y][x] += dp[y + 1][x - 2]
            if y - 1 >= 0 and x - 2 >= 0:
                dp[y][x] += dp[y - 1][x - 2]
            if y - 2 >= 0 and x - 1 >= 0:
                dp[y][x] += dp[y - 2][x - 1]
            if y - 2 >= 0 and x + 1 < m:
                dp[y][x] += dp[y - 2][x + 1]
        y += 1
        x -= 1
print(dp[-1][-1])
