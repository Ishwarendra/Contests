for _ in range(int(input())):
    n, x = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a_dist = set(a); print(a_dist)
    if (n-x) >= len(a_dist):
        print(len(a_dist))
    else:
        print(n-x)