n = int(input())
sequence1 = list(map(int, input().split()))
m = int(input())
sequence2 = list(map(int, input().split()))

dp = [[0 for i in range(m + 1)] for i in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if sequence1[i - 1] == sequence2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

out = []
i, j = n, m

while i > 0 and j > 0:
    if sequence1[i - 1] == sequence2[j - 1]:
        out.append(sequence1[i - 1])
        i, j = i - 1, j - 1
    else:
        if dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

for i in reversed(out):
    print(i, end=' ')
