def merge(arr1, start1, end1, arr2, start2, end2, arr_final):
    i = 0
    curr1 = start1
    curr2 = start2
    while curr1 < end1 or curr2 < end2:
        if curr1 >= end1:
            arr_final[i] = arr2[curr2]
            curr2 += 1
        elif curr2 >= end2:
            arr_final[i] = arr1[curr1]
            curr1 += 1
        elif arr1[curr1] > arr2[curr2]:
            arr_final[i] = arr2[curr2]
            curr2 += 1
        else:
            arr_final[i] = arr1[curr1]
            curr1 += 1
        i += 1


def merge_sort(arr, begin, end):
    if end - begin == 1:
        return 0

    middle = (end - begin)//2
    arr1 = arr[begin:middle]
    arr2 = arr[middle:end]
    merge_sort(arr1, 0, len(arr1))
    merge_sort(arr2, 0, len(arr2))
    merge(arr1, 0, len(arr1), arr2, 0, len(arr2), arr)


n = int(input())
if n != 0:
    arr = list(map(int, input().split()))
    merge_sort(arr, 0, len(arr))
    print(*tuple(arr))
