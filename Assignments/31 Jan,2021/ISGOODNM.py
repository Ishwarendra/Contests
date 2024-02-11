def factors(x):
    sum = 0
    i = 1
    while i*i <= x:
        if x % i == 0:
            sum += i
            if x//i != i: 
                sum += (x//i)
        i += 1
    return (sum - x)
n = int(input())
if factors(n) == n:
    print("YES")
else:
    print("NO")

