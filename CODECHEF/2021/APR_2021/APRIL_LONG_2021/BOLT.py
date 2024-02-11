def giveTime(v):
    return round((100/v),2)

for _ in range(int(input())):
    k1, k2, k3, v= [float(x) for x in input().split()]

    if giveTime(v*k1*k2*k3) < (9.58):
        print("YES")
    else:
        print("NO")
