def solution(n, k, m):
    if n < k:
        return 0
    if k // m == 0:
        return 0

    amount_k = n // k
    n %= k

    amount_m = (k // m) * amount_k

    n += amount_k * (k % m)

    return amount_m + solution(n, k, m)


n, k, m = map(int, input().split())
print(solution(n, k, m))
