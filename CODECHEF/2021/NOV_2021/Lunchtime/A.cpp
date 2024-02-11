for _ in range(int(input())):
    mod = 998244353
    n = int(input())
    num = n * (n + 1) * (n + 1)
    num %= mod
    den = 4
    modi = 748683265
    
    if (num/den == num//den):
        print((num//den) % mod)
    else:
        ans = (num % mod) * modi
        ans = ans % mod
        print(ans)
