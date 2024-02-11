for _ in range(int(input())):
    n, r = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    x = 0
    X = [0]
    for i in range(n):
        x += b[i]
        if x > X[0]:
            X[0] = x 
        if i + 1 < n:
            x -= (a[i+1] - a[i])*r
            if x < 0:
                x = 0
    print(X[0]) 