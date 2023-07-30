indexes = {'N': 0, 'S': 1, 'W': 2, 'E': 3, 'U': 4, 'D': 5}
rules = {'N': input(), 'S': input(), 'W': input(),
         'E': input(), 'U': input(), 'D': input()}
command, param = input().split()
param = int(param)

dp = [[0 for i in range(6)] for i in range(param + 1)]
for s in range(1, param + 1):
    for dir in indexes:
        if s == 1:
            dp[s][indexes[dir]] = 1
        else:
            rule = rules[dir]
            for comm in rule:
                dp[s][indexes[dir]] += dp[s - 1][indexes[comm]]
            dp[s][indexes[dir]] += 1

print(dp[param][indexes[command]])
