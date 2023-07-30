from collections import deque


class Queue:
    def __init__(self):
        self.items = deque()

    def push(self, value):
        self.items.append(value)
        return 'ok'

    def pop(self):
        if self.size() == 0:
            return 'error'
        return self.items.popleft()

    def front(self):
        if self.size() == 0:
            return 'error'
        value = self.items.popleft()
        self.items.appendleft(value)
        return value

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = deque()
        return 'ok'


queue = Queue()
while True:
    cmd = input().split()

    if len(cmd) == 2:
        print(queue.push(int(cmd[1])))
    elif cmd[0] == 'pop':
        print(queue.pop())
    elif cmd[0] == 'front':
        print(queue.front())
    elif cmd[0] == 'size':
        print(queue.size())
    elif cmd[0] == 'clear':
        print(queue.clear())
    elif cmd[0] == 'exit':
        print('bye')
        break
