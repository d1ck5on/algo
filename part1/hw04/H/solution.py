def is_correct(x, w, h, n):
    sum = (x // w) * (x // h)
    if sum >= n:
        return True
    else:
        return False


def bin_search(start, end, w, h, n):
    while start < end:
        middle = (start + end) // 2
        if is_correct(middle, w, h, n):
            end = middle
        else:
            start = middle + 1
    return start


w, h, n = map(int, input().split())
print(bin_search(1, 10**18, w, h, n))
