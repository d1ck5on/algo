n, k = map(int, input().split())
text = input()

max_length = 1
max_ind = 0
errors_cnt = 0
letters = dict()

r = 0
for l in range(n):
    while errors_cnt == 0 and r < n:
        if text[r] in letters:
            letters[text[r]] += 1
            if letters[text[r]] > k:
                errors_cnt += 1
        else:
            letters[text[r]] = 1
        if errors_cnt == 0:
            r += 1
    if r - l > max_length:
        max_length = r - l
        max_ind = l
    if letters[text[l]] == k + 1:
        errors_cnt -= 1
        if errors_cnt == 0:
            r += 1
    letters[text[l]] -= 1

print(max_length, max_ind + 1)
