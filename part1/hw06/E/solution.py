k = int(input())
s = input()

options_cnt = 0
now_cnt = 0

for i in range(len(s) - k):
    if s[i] == s[i + k]:
        now_cnt += 1
    else:
        now_cnt = 0
    options_cnt += now_cnt

print(options_cnt)
