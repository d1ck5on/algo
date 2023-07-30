from collections import deque
n = int(input())
data = []
for i in range(n):
    data.append(input())

buckets = [deque() for i in range(10)]

digits_cnt = len(data[0])

print('Initial array:')
print(', '.join(data))
print('**********')

for i in range(digits_cnt):
    for elem in data:
        buckets[int(elem[-i - 1])].append(elem)
    index = 0

    print(f'Phase {i + 1}')
    for k in range(10):
        print(f'Bucket {k}: ', end='')
        if len(buckets[k]) == 0:
            print('empty')
        else:
            print(', '.join(list(buckets[k])))
    print('**********')

    for k in range(10):
        while len(buckets[k]) != 0:
            data[index] = buckets[k].popleft()
            index += 1

print('Sorted array:')
print(', '.join(data))
