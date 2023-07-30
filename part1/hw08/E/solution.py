length, n = map(int, input().split())
C = [0] + list(map(int, input().split())) + [length]
n += 2

dp = [[0 for i in range(n)] for i in range(n)]
for diag in range(1, n):
    for l in range(n - diag):
        r = l + diag
        min_amount = length * n
        if r - l == 1:
            min_amount = 0
        for m in range(l + 1, r):
            min_amount = min(min_amount, dp[l][m] + dp[m][r] + C[r] - C[l])
        dp[l][r] = min_amount
print(dp[0][n - 1])
