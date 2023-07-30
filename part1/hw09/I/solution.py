n = int(input())
a, b, c = map(int, input().split())
lcm = n
dp = [0 for i in range(lcm)]
dp[0] = 1
for i in range(lcm):
    if dp[i] == 1:
        if i + a < lcm:
            dp[i + a] = 1
        if i + b < lcm:
            dp[i + b] = 1
        if i + c < lcm:
            dp[i + c] = 1
print(sum(dp))
