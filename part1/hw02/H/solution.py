from collections import deque


def solution(k, arr):
    arr = deque(arr)
    stack = []
    b = []

    while k > 0:
        k -= 1
        curr = arr.popleft()

        while len(stack) != 0 and stack[-1] < curr:
            curr_stack = stack.pop()
            if len(b) > 0 and curr_stack < b[-1]:
                return 0
            b.append(curr_stack)
        stack.append(curr)

    while len(stack) != 0:
        curr_stack = stack.pop()
        if len(b) > 0 and curr_stack < b[-1]:
            return 0
        b.append(curr_stack)

    return 1


n = int(input())
for i in range(n):
    inp = list(map(float, input().split()))
    print(solution(inp[0], inp[1:]))
