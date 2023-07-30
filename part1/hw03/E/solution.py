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


n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

arr_merge = [0 for i in range(n + m)]
merge(arr1, 0, n, arr2, 0, m, arr_merge)
print(*tuple(arr_merge))
