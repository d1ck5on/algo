class Stack:
    def __init__(self):
        self.items = []

    def push(self, value):
        self.items.append(value)
        return 'ok'

    def pop(self):
        if len(self.items) == 0:
            return 'error'
        return self.items.pop()

    def back(self):
        if len(self.items) == 0:
            return 'error'
        return self.items[-1]

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []
        return 'ok'


stack = Stack()
while True:
    cmd = input().split()

    if len(cmd) == 2:
        print(stack.push(int(cmd[1])))
    elif cmd[0] == 'pop':
        print(stack.pop())
    elif cmd[0] == 'back':
        print(stack.back())
    elif cmd[0] == 'size':
        print(stack.size())
    elif cmd[0] == 'clear':
        print(stack.clear())
    elif cmd[0] == 'exit':
        print('bye')
        break
