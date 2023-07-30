def solution(brackets):
    stack = []

    for i in brackets:
        if i in ['(', '{', '[']:
            stack.append(i)

        elif i == ')':
            if stack == [] or stack[-1] != '(':
                return 'no'
            stack.pop()

        elif i == ']':
            if stack == [] or stack[-1] != '[':
                return 'no'
            stack.pop()

        elif i == '}':
            if stack == [] or stack[-1] != '{':
                return 'no'
            stack.pop()

    if stack != []:
        return 'no'

    return 'yes'


brackets = input()
print(solution(brackets))
