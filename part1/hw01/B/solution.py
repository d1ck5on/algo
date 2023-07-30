def solution(a, b, c):
    if c < 0:
        return 'NO SOLUTION'
    elif a == 0:
        if c * c == b:
            return 'MANY SOLUTIONS'
        else:
            return 'NO SOLUTION'
    elif (c * c - b) % a != 0:
        return 'NO SOLUTION'
    else:
        return (c * c - b) // a


a = int(input())
b = int(input())
c = int(input())

print(solution(a, b, c))
