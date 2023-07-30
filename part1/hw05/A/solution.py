n = int(input())
press_counts = list(map(int, input().split()))
k = int(input())
pressed_buttons = list(map(int, input().split()))

for i in range(k):
    press_counts[pressed_buttons[i]-1] -= 1

for i in range(n):
    if press_counts[i] < 0:
        print('yes')
    else:
        print('no')
