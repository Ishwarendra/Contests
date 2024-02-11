t = int(input())
for _ in range(t):
    x1, y1, x2, y2 = [int(x) for x in input().split()]
    hr = (x2 - x1)
    vr = (y2 - y1)
    ans = ""
    if hr > 0:
        ans += "E"*(hr)
    else:
        ans += "W"*((-1)*hr)
    if vr > 0:
        ans += "N"*(vr)
    else:
        ans += "S"*((-1)*vr)
    print(len(ans))
    print(ans)