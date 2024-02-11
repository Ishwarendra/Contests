for _ in range(int(input())):
    am, bm, cm, tm, a, b, c = [int(x) for x in input().split()]
    if (a >= am) and (b >= bm) and (c >= cm) and (a + b + c)>=tm:
        print("YES")
    else:
        print("NO")
        