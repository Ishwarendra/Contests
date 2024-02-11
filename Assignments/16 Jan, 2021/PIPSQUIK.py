t = int(input())

for i in range(t):
    n, h, y1, y2 ,l = [int(x) for x in input().split()]
    bar = 0
    for j in range(n):
        t, x = [int(x) for x in input().split()]
        if (t == 1) and (x >= h- y1) and (l > 0):
            bar +=1
        elif (t == 1) and (x < h-y1) and (l>=1):
            l = l-1
            if l == 0:
                pass
            else:
                bar +=1
        elif (t ==2) and (x <= y2) and (l > 0):
            bar +=1
        elif (t == 2) and (x > y2) and (l >=1):
            l = l-1
            if (l == 0):
                pass
            else:
                bar +=1
                    
    print(bar)

