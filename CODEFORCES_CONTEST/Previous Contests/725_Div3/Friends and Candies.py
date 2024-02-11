for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    mean = sum(a)/n
    k = 0
    if mean != int(mean):
        print(-1)
        continue
    else:
        for i in a:
            if i > mean:
                k += 1

    print(k)