t = int(input())
for _ in range(t):
    n, r, g, b = [int(x) for x in input().split()]
    max_column = (r + g + b)//3
    if max_column >= n:
        if r >=n and b >= n:
            ans = n
        else:
            ans = min(r,b)

    else:
        if g >= min(r,b): # green extra
            ans = min(r,b)
        else: #green are lesser in number
            ans = g + min(r-g, b-g, (r+b-2*g)//2)
    print(ans)