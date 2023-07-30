n, z = map(int, input().split())
d = list(map(int, input().split()))

r = 0
option_count = 0
for l in range(n):
    while r < n and d[r] - d[l] <= z:
        r += 1
    if r < n and d[r] - d[l] > z:
        option_count += n - r

print(option_count)
