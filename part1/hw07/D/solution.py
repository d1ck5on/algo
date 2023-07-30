n, m = map(int, input().split())
penalty = []
for i in range(n):
    penalty.append(list(map(int, input().split())))

dp = [[0 for i in range(m)] for j in range(n)]
dp[0][0] = penalty[0][0]
way = [[[0, 0] for i in range(m)] for j in range(n)]
for i in range(1, m):
    dp[0][i] = dp[0][i - 1] + penalty[0][i]
    way[0][i] = [0, i - 1]
for i in range(1, n):
    dp[i][0] = dp[i - 1][0] + penalty[i][0]
    way[i][0] = [i - 1, 0]

for y in range(1, n):
    for x in range(1, m):
        way[y][x] = [y, x - 1]
        if dp[y - 1][x] < dp[y][x - 1]:
            way[y][x] = [y - 1, x]
        dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]) + penalty[y][x]

print(dp[n - 1][m - 1])

out = [[n, m]]
y, x = n - 1, m - 1
while y != 0 or x != 0:
    y, x = way[y][x]
    out.append([y + 1, x + 1])

print(len(out))
for i in reversed(out):
    print(i[0], i[1])
