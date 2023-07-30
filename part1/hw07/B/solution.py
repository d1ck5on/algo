n, k = map(int, input().split())
dp = [0 for i in range(k)]
dp[-1] = 1
for i in range(2, n + 1):
    ind = k - 2 + i
    dp.append(0)
    for j in range(1, k + 1):
        dp[-1] += dp[ind - j]
print(dp[-1])
