m = int(input())
secs = list(map(int, input().split()))

for i in range(31):
    secs[i] = [2**i / secs[i], i, secs[i]]
secs.sort()

amount = 0
amounts = []
for i in range(31):
    before_barrier_cnt = m // secs[i][2]
    before_barrier_cost = before_barrier_cnt * 2 ** secs[i][1]

    amount += before_barrier_cost
    m -= before_barrier_cnt * secs[i][2]

    if m != 0:
        amounts.append(amount + 2 ** secs[i][1])
    else:
        amounts.append(amount)
        break

print(min(amounts))
