from operator import gt
from functools import partial


def partition(arr, start, end, predicate):
    i = start
    for j in range(end + 1):
        if predicate(arr[j]):
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    return i


n = int(input())
arr = list(map(int, input().split()))
x = int(input())
ltx = partial(gt, x)
pivot = partition(arr, 0, n-1, ltx)
print(pivot)
print(n - pivot)
