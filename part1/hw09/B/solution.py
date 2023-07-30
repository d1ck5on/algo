n, k, s = map(int, input().split())

table_kk = [[0 for i in range(k)] for i in range(k)]
for i in range(k):
    for j in range(k):
        if s != 0:
            table_kk[i][j] = 1
            s -= 1

for i in range(k):
    table_kk[i] = table_kk[i] * (n // k) + table_kk[i][:n % k]

table_kk = table_kk * (n // k) + table_kk[:n % k]

for i in table_kk:
    for j in i:
        print(j, end=' ')
    print()
