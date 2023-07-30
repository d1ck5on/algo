from collections import deque


first = deque(list(map(int, input().split())))
second = deque(list(map(int, input().split())))
count = 0
winner = None

while count < 10**6:
    if len(first) == 0:
        winner = 'second'
        break

    if len(second) == 0:
        winner = 'first'
        break

    count += 1

    first_card = first.popleft()
    second_card = second.popleft()

    if (first_card > second_card and (first_card != 9 or second_card != 0) or
            first_card == 0 and second_card == 9):
        first.append(first_card)
        first.append(second_card)
    else:
        second.append(first_card)
        second.append(second_card)

if winner is None:
    print('botva')
else:
    print(winner, count)
