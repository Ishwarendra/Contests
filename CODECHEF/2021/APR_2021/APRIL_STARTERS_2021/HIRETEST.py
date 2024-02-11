def func(ans, X, Y):
    count_F = ans.count("F")
    count_P = ans.count("P")

    if count_F >= X or (count_F >= X-1 and count_P >= Y):
        return True
    else:
        return False

# print(func("PPPFP",3, 2))
for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    X, Y = [int(x) for x in input().split()]
    res = ""
    for _i in range(n):
        ans = input()
        if func(ans, X, Y):
            res += "1"
        else:
            res += "0"
    print(res)