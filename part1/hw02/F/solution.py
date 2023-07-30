d = []
while(True):
    c = input()
    if c == 'exit':
        print('bye')
        break
    elif c[0:10] == 'push_front':
        d.insert(0, int(c[11:]))
        print('ok')
    elif c[0:9] == 'push_back':
        d.append(int(c[10:]))
        print('ok')
    elif c == 'pop_front':
        if len(d) == 0:
            print('error')
        else:
            print(d.pop(0))
    elif c == 'pop_back':
        if len(d) == 0:
            print('error')
        else:
            print(d.pop())
    elif c == 'front':
        if len(d) == 0:
            print('error')
        else:
            print(d[0])
    elif c == 'back':
        if len(d) == 0:
            print('error')
        else:
            print(d[-1])
    elif c == 'size':
        print(len(d))
    elif c == 'clear':
        d = []
        print('ok')
