def insert(arr, end):
    while end - 1 >= 0 and arr[end] < arr[end - 1]:
        arr[end], arr[end - 1] = arr[end - 1], arr[end]
        end -= 1
    return end


def insertion_sort(arr):
    sorted_end = 1
    while sorted_end != len(arr):
        end = insert(arr, sorted_end)
        if end != sorted_end:
            print(*tuple(arr))
        sorted_end += 1


n = int(input())
arr = list(map(int, input().split()))
insertion_sort(arr)
