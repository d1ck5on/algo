from collections import Counter

n = int(input())
letters = [0 for i in range(26)]

s = input()
for i in range(n):
    letters[ord(s[i]) - ord('A')] += 1

odd_letter = ''
left_part = ''
for i in range(26):
    left_part += chr(ord('A') + i) * (letters[i] // 2)
    if odd_letter == '':
        odd_letter = chr(ord('A') + i) * (letters[i] % 2)

print(left_part + odd_letter + left_part[::-1])
