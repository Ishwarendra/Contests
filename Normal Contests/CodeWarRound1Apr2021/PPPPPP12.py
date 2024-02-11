for _ in range(int(input())):
    a, b, k = [int(x) for x in input().split()]
    if k % 2 == 0:
        c1 = k//2
        c2 = k//2
    else:
        c1 = k//2 + 1
        c2 = k//2
    print(c1*a - c2*b)