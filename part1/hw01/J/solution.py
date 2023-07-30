def solution(field):
    o_amount = field[0].count(2) + field[1].count(2) + field[2].count(2)
    x_amount = field[0].count(1) + field[1].count(1) + field[2].count(1)

    if x_amount != o_amount and x_amount != o_amount + 1:
        return 'NO'

    is_x_wins = (field[0][0] == 1 and field[0][1] == 1 and field[0][2] == 1 or
                 field[1][0] == 1 and field[1][1] == 1 and field[1][2] == 1 or
                 field[2][0] == 1 and field[2][1] == 1 and field[2][2] == 1 or
                 field[0][0] == 1 and field[1][0] == 1 and field[2][0] == 1 or
                 field[0][1] == 1 and field[1][1] == 1 and field[2][1] == 1 or
                 field[0][2] == 1 and field[1][2] == 1 and field[2][2] == 1 or
                 field[0][0] == 1 and field[1][1] == 1 and field[2][2] == 1 or
                 field[0][2] == 1 and field[1][1] == 1 and field[2][0] == 1)

    is_o_wins = (field[0][0] == 2 and field[0][1] == 2 and field[0][2] == 2 or
                 field[1][0] == 2 and field[1][1] == 2 and field[1][2] == 2 or
                 field[2][0] == 2 and field[2][1] == 2 and field[2][2] == 2 or
                 field[0][0] == 2 and field[1][0] == 2 and field[2][0] == 2 or
                 field[0][1] == 2 and field[1][1] == 2 and field[2][1] == 2 or
                 field[0][2] == 2 and field[1][2] == 2 and field[2][2] == 2 or
                 field[0][0] == 2 and field[1][1] == 2 and field[2][2] == 2 or
                 field[0][2] == 2 and field[1][1] == 2 and field[2][0] == 2)

    if is_o_wins and x_amount == o_amount + 1:
        return 'NO'
    if is_x_wins and x_amount == o_amount:
        return 'NO'
    if is_x_wins and is_o_wins:
        return 'NO'

    return 'YES'


field = [[], [], []]
field[0] = list(map(int, input().split()))
field[1] = list(map(int, input().split()))
field[2] = list(map(int, input().split()))

print(solution(field))
