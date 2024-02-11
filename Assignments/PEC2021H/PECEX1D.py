def giveWays(n, x, pos, steps, result):
    if pos > n or pos < 0: # Can't go above n and below 0
        return
    if steps == x: # No more steps now
        if n == pos:
            result[0] += 1
        return
    for jump in range(-3, 4): 
        giveWays(n, x, pos + jump, steps + 1, result)
    return result[0]

for _ in range(int(input())):
    n, x = [int(x) for x in input().split()]
    if n == 0:
        print(1)
    else:
        if x == 0:
            print(0)
        else:
            print(giveWays(n, x, 0, 0, [0]))