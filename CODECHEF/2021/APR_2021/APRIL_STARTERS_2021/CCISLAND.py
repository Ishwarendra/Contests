for _ in range(int(input())):
    x, y, xr, yr, d = [int(x) for x in input().split()]
    a = x/xr
    b = y/yr
    if min(a,b) >= d:
        print("YES")
    else:
        print("NO")