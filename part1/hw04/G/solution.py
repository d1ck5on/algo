def bin_search_left(arr, x):
    start = 0
    end = len(arr) - 1
    while start < end:
        middle = (start + end) // 2
        if arr[middle] >= x:
            end = middle
        else:
            start = middle + 1
    if arr[start] == x:
        return start + 1
    else:
        return 0


def bin_search_right(arr, x):
    start = 0
    end = len(arr)
    while start < end:
        middle = (start + end) // 2
        if arr[middle] > x:
            end = middle
        else:
            start = middle + 1
    if arr[start - 1] == x:
        return start
    else:
        return 0


n = int(input())
arr = list(map(int, input().split()))
m = int(input())
inp = list(map(int, input().split()))
for i in inp:
    print(bin_search_left(arr, i), bin_search_right(arr, i))
