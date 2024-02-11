for _ in range(int(input())):
    ans = 1000
    m, k, a1, ak = [int(x) for x in input().split()]
    for x1 in range(a1 + 1):
        for xk in range(ak + 1):
            for y1 in range(50):
                for yk in range(50):
                    val = x1 + y1 + yk * k + xk * k;
                    if val != m:
                        continue

                    ans = min(ans, y1 + yk)

    
    print(ans) 