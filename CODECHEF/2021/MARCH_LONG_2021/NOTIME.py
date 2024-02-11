def func(x, t, h):
    for i in t:
        if (x + i) >= h:
            return "YES"
    return "NO"

n, h, x = [int(x) for x in input().split()]
t = [int(x) for x in input().split()]
print(func(x, t, h))
    
