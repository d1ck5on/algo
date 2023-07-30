def conditioner(t_room, t_cond, mode):
    if mode == 'freeze':
        if t_room <= t_cond:
            return t_room
        return t_cond
    elif mode == 'heat':
        if t_room >= t_cond:
            return t_room
        return t_cond
    elif mode == 'auto':
        return t_cond
    elif mode == 'fan':
        return t_room


t_room, t_cond = map(int, input().split())
mode = input()
print(conditioner(t_room, t_cond, mode))
