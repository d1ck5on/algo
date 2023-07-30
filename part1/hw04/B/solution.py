from operator import gt
from functools import partial
from random import randint


def partition(arr, start, end):
    x = randint(start, end)
    predicate = partial(gt, arr[x])
    arr[x], arr[end] = arr[end], arr[x]
    i = start
    for j in range(start, end):
        if predicate(arr[j]):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[end] = arr[end], arr[i]
    return i


def quick_sort(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)
        quick_sort(arr, start, pivot - 1)
        quick_sort(arr, pivot + 1, end)


n = int(input())
arr = list(map(int, input().split()))
quick_sort(arr, 0, n - 1)
print(*tuple(arr))
