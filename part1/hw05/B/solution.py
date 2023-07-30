n = int(input())
replies_count = dict()

messages = []
max_theme = ''
replies_count[max_theme] = -1
for i in range(n):
    k = int(input())
    if k == 0:
        name_theme = input()
        replies_count[name_theme] = 0
        replies_count[name_theme] += 1
        if replies_count[name_theme] > replies_count[max_theme]:
            max_theme = name_theme
        messages.append([i + 1, name_theme])
        input()
    else:
        input()
        theme_id = messages[k - 1][0]
        name_theme = messages[theme_id - 1][1]
        messages.append([theme_id, name_theme])
        replies_count[name_theme] += 1
        if replies_count[name_theme] > replies_count[max_theme]:
            max_theme = name_theme

print(max_theme)
