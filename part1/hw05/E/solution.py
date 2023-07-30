from collections import Counter

message = ''
with open('input.txt') as f:
    message = ''.join(f.readlines())

message = Counter(message)
if ' ' in message:
    message.pop(' ')
if '\n' in message:
    message.pop('\n')
coords = sorted(message.keys())
max_cnt = message.most_common(1)[0][1]

for i in range(max_cnt):
    out = ''
    current_height = max_cnt - i
    for letter in coords:
        if message[letter] >= current_height:
            out += '#'
        else:
            out += ' '
    print(out)
print(''.join(coords))
