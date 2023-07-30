def solution(n, arr):
    return arr[n // 2]


n = int(input())
arr = list(map(int, input().split()))
print(solution(n, arr))
