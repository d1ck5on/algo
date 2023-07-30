n, m = map(int, input().split())

mass = list(map(int, input().split()))
cost = list(map(int, input().split()))

dp = [-1 for i in range(m + 1)]
dp[0] = 0

for i in range(n):
    for j in range(m - mass[i], -1, -1):
        if dp[j] != -1:
            dp[j + mass[i]] = max(dp[j + mass[i]], dp[j] + cost[i])

print(max(dp))
