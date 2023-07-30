def solution(x, y, z):
    if x == y or x > 12 or y > 12:
        return 1
    return 0


x, y, z = map(int, input().split())
print(solution(x, y, z))
