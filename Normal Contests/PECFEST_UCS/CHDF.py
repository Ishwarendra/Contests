for _ in range(int(input())):
    n, f = [int(x) for x in input().split()]
    s = input().split()
    for i in range(n):
        if s[i] == "1":
            f += 1
        else:
            f -= 1
        if f == 0:
            ans = "NO"
            break
        else:
            ans = "YES"
        f -= 1
    print(ans)

