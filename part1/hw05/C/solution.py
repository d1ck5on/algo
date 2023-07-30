from collections import Counter
n, m = map(int, input().split())
rebus = ''
for i in range(n):
    rebus += input()

letters = Counter(rebus)

for i in range(m):
    word = Counter(input())
    letters -= word

print(''.join(sorted(letters.elements())))
