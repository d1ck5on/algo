def swap_max(arr, start, end):
    max_index = start
    for i in range(1, end):
        if arr[i] > arr[max_index]:
            max_index = i
    arr[end - 1], arr[max_index] = arr[max_index], arr[end - 1]


n = int(input())
if n != 0:
    arr = list(map(int, input().split()))
    swap_max(arr, 0, n)
    print(*tuple(arr))
