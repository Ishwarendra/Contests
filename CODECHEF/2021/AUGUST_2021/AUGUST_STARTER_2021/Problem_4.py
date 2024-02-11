for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]


    a.sort(), b.sort();
    if (n == 2):
        if (b[0] - a[1] > 0):
            print(b[0] - a[1])
        else:
            print(b[0] - a[0])

        continue


    # ll x;
    x = 99999999999
    #// skipping a[0]
    if ((b[0] - a[1]) == (b[-1] - a[-1]) and b[0] - a[1] > 0):
        x = b[0] - a[1];

    #//skipping a[1] .. a[n - 2] any one
    if (b[0] - a[0] == b[-1] - a[-1] and b[0] - a[0] > 0):
        x =min(x, b[0] - a[0]);
    
    #//skipping a[n - 1]
    if (b[0] - a[0] == b[-1] + a[-2] and b[0] - a[0] > 0):
        x = min(x, b[0] - a[0])    

    print(x)