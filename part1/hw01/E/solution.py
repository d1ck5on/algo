def solution(a, b, n, m):
    min_r = max(n + a * (n - 1), m + b * (m - 1))
    max_r = min(n + a * (n - 1) + 2 * a, m + b * (m - 1) + 2 * b)

    if min_r > max_r:
        return (-1,)
    return (min_r, max_r)


a = int(input())
b = int(input())
c = int(input())
d = int(input())

print(*solution(a, b, c, d))
