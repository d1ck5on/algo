def solution(a, b, x, y):
    a, b = max(a, b), min(a, b)
    x, y = max(x, y), min(x, y)

    s = [((b + y) * max(a, x), b + y, max(a, x)),
         ((b + x) * max(a, y), b + x, max(a, y)),
         ((a + x) * max(b, y), a + x, max(b, y)),
         ((a + y) * max(b, x), a + y, max(b, x))]

    s.sort()

    return (s[0][1], s[0][2])


a, b, x, y = map(int, input().split())
print(*solution(a, b, x, y))
