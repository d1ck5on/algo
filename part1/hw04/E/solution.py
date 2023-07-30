class Heap:
    def __init__(self):
        self.items = []

    def insert(self, k):
        self.items.append(k)
        self.sift_up(len(self.items) - 1)

    def extract(self):
        self.items[0], self.items[-1] = self.items[-1], self.items[0]
        res = self.items.pop()
        self.sift_down(0, len(self.items))
        return res

    def sift_up(self, i):
        while i != 0 and self.items[i] > self.items[(i - 1) // 2]:
            self.items[i], self.items[(i - 1) // 2] = \
                self.items[(i - 1) // 2], self.items[i]
            i = (i - 1) // 2

    def sift_down(self, i, end):
        while True:
            if 2 * i + 2 < end:
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
            elif 2 * i + 1 < end:
                if self.items[i] < self.items[2*i+1]:
                    self.items[i], self.items[2*i+1] = \
                        self.items[2*i+1], self.items[i]
                    i = 2 * i + 1
                else:
                    return
            else:
                return

    def heapsort(self):
        arr = self.items.copy()
        i = len(arr) - 1
        while i > 0:
            self.items[0], self.items[i] = self.items[i], self.items[0]
            self.sift_down(0, i)
            i -= 1
        arr, self.items = self.items, arr
        return arr


heap = Heap()
n = int(input())
arr = list(map(int, input().split()))
for i in arr:
    heap.insert(i)
arr = heap.heapsort()
print(*tuple(arr))
