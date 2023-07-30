n, k = map(int, input().split())
s = input()

out = 0
for m in range(0, n):
    i = 0
    is_poly = 0
    while m - i >= 0 and m + i < n and is_poly <= k:
        l = m - i
        r = m + i
        if s[l] != s[r]:
            is_poly += 1
        if is_poly <= k:
            out += 1
        i += 1

for m in range(0, n - 1):
    i = 1
    is_poly = 0
    if s[m] != s[m + 1]:
        is_poly += 1
    if is_poly <= k:
        out += 1
    while m - i >= 0 and m + i + 1 < n and is_poly <= k:
        l = m - i
        r = m + i + 1
        if s[l] != s[r]:
            is_poly += 1
        if is_poly <= k:
            out += 1
        i += 1

print(out)
