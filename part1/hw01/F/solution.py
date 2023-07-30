def solution(n, i, j):
    i, j = max(i, j), min(i, j)
    return min(n - (i - j), i - j) - 1


n, i, j = map(int, input().split())
print(solution(n, i, j))
