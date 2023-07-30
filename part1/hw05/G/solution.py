A = [0 for i in range(10)]
B = [0 for i in range(10)]

a = input()
for i in a:
    A[int(i)] += 1
b = input()
for i in b:
    B[int(i)] += 1

out = ''

for i in range(10):
    out += min(A[9-i], B[9-i]) * str(9-i)

if out == '':
    print(-1)
elif out[0] == '0':
    print(0)
else:
    print(out)
