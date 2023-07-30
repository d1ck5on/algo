n, m = map(int, input().split())
gold = list(map(int, input().split()))

dp = [False for i in range(m + 1)]
dp[0] = True

for i in range(n):
    for j in range(m - gold[i], -1, -1):
        if dp[j]:
            dp[j + gold[i]] = True

for i in range(m, -1, -1):
    if dp[i]:
        print(i)
        break
