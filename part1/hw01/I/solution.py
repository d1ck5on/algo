def solution(arr):
    arr.sort()
    if (arr[1][0] - arr[0][0] == arr[3][0] - arr[2][0] and
            arr[1][1] - arr[0][1] == arr[3][1] - arr[2][1] and
            arr[0][0] - arr[2][0] == arr[1][0] - arr[3][0] and
            arr[0][1] - arr[2][1] == arr[1][1] - arr[3][1]):
        return 'YES'
    return 'NO'


n = int(input())
while n:
    n -= 1
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    arr = [(x1, y1), (x2, y2), (x3, y3), (x4, y4)]
    print(solution(arr))
