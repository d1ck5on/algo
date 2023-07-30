def is_true(l, r):
    if l == '(' and r == ')':
        return True
    if l == '[' and r == ']':
        return True
    if l == '{' and r == '}':
        return True


s = input()
dp = [['' for i in range(len(s))] for i in range(len(s))]

for diag in range(1, len(s)):
    for l in range(0, len(s) - diag):
        r = l + diag
        best_res = ''
        if is_true(s[l], s[r]):
            best_res = s[l] + dp[l + 1][r - 1] + s[r]
        for m in range(l, r):
            curr_res = dp[l][m] + dp[m + 1][r]
            if len(curr_res) > len(best_res):
                best_res = curr_res
        dp[l][r] = best_res
print(dp[0][len(s) - 1])
