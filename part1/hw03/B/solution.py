def swap_max(arr, start, end):
    max_index = start
    for i in range(1, end):
        if arr[i] > arr[max_index]:
            max_index = i
    arr[end - 1], arr[max_index] = arr[max_index], arr[end - 1]


def selection_sort(arr):
    end = len(arr)
    while end != 1:
        swap_max(arr, 0, end)
        end -= 1


n = int(input())
if n != 0:
    arr = list(map(int, input().split()))
    selection_sort(arr)
    print(*tuple(arr))
