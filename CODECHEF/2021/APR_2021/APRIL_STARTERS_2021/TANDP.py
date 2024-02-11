def NoOfTurnsThief(x, y, n, m):
    return (n - x) + (m - y)

def NoOfTurnsPolice(a, b, n, m):
    count = 0
    if min((m-b),(n-a)) == (n-a):
        count += (n-a); a += (n-a); b += (n-a)
        count += (m-b)
    else:
        count += (m-b); a += (m-b); b += (m-b)
        count += (n-a)
    return count

for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    x, y = [int(x) for x in input().split()] # thief
    a, b = [int(x) for x in input().split()] # police

    p_steps = NoOfTurnsPolice(a, b, n, m)
    t_steps = NoOfTurnsThief(x, y, n, m)
    print(p_steps, t_steps)
    if t_steps <= p_steps:
        print("YES")
    else:
        
        print("NO")