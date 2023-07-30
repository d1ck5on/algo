def bin_search(arr, x, start, end):
    while start < end:
        middle = (end + start) // 2
        if arr[middle] < x:
            start = middle + 1
        elif arr[middle] > x:
            end = middle - 1
        else:
            return 'YES'
    if arr[start] == x:
        return 'YES'
    return 'NO'


n, k = map(int, input().split())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
for i in arr2:
    print(bin_search(arr1, i, 0, n - 1))
