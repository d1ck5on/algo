class Heap:
    def __init__(self):
        self.items = []

    def insert(self, k):
        self.items.append(k)
        self.sift_up(len(self.items) - 1)

    def extract(self):
        self.items[0], self.items[-1] = self.items[-1], self.items[0]
        res = self.items.pop()
        self.sift_down(0)
        return res

    def sift_up(self, i):
        while i != 0 and self.items[i] > self.items[(i - 1) // 2]:
            self.items[i], self.items[(i - 1) // 2] = \
                self.items[(i - 1) // 2], self.items[i]
            i = (i - 1) // 2

    def sift_down(self, i):
        while True:
            if 2 * i + 2 < len(self.items):
                if self.items[2*i+2] > self.items[2*i+1]:
                    if self.items[i] < self.items[2*i+2]:
                        self.items[i], self.items[2*i+2] = \
                            self.items[2*i+2], self.items[i]
                        i = 2 * i + 2
                    else:
                        return
                else:
                    if self.items[i] < self.items[2*i+1]:
                        self.items[i], self.items[2*i+1] = \
                            self.items[2*i+1], self.items[i]
                        i = 2 * i + 1
                    else:
                        return
            elif 2 * i + 1 < len(self.items):
                if self.items[i] < self.items[2*i+1]:
                    self.items[i], self.items[2*i+1] = \
                        self.items[2*i+1], self.items[i]
                    i = 2 * i + 1
                else:
                    return
            else:
                return


heap = Heap()
n = int(input())
for i in range(n):
    inp = input().split()
    if int(inp[0]) == 1:
        print(heap.extract())
    else:
        heap.insert(int(inp[1]))
