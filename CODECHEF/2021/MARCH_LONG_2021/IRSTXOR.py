
def giveLessThan(c):
    d = 1
    while not (c < (2**d)):
        d += 1
    return d

t = int(input())
for _ in range(t):
    max = 0
    c = int(input())
    d = giveLessThan(c)
    for a in range(1, 2**d):
        b = a^c
        if b > 0 and b < 2**d and a*b > max:
            max = a*b
    print(max)

    



    
