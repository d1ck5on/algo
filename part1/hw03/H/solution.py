n = int(input())
arr = list(map(int, input().split()))

uniq = set()
res = []
for i in reversed(arr):
    if i not in uniq:
        res.append(i)
        uniq.add(i)

print(len(res))
for i in reversed(res):
    print(i, end=' ')
