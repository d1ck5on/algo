def sift(arr, end):
    swap_count = 0
    for i in range(end - 1):
        if arr[i] > arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
            swap_count += 1
    return swap_count


def bubble_sort(arr):
    end = len(arr)
    swap_count = 0
    while end > 1:
        swap_count += sift(arr, end)
        end -= 1
    return swap_count


n = int(input())
arr = list(map(int, input().split()))
print(bubble_sort(arr))
