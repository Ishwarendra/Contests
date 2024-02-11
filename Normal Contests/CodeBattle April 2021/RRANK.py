import math

def lessThan(a, b): #tuples
    return (a[0] + a[1] < b[0] + b[1]) or (a[0] + b[0] == b[0] + b[1] and a[0] < a[1])
    
def Terms(sum):
    a, b, c = 1, 1, -2*sum
    d = (b**2) - (4*a*c)
    sol1 = (-b - math.sqrt(d))/(2*a)
    sol2 = (-b + math.sqrt(d))/(2*a)
    # print(sol1, sol2, d)
    try:
        if sol1 > 0:
            sol = sol1
        else:
            sol = sol2
    except:
        sol = sol2

    return int(sol)

def yrank(n):
    return (n**2 - n + 2)//2
def xrank(n):
    return (n**2 + n)//2

for _ in range(int(input())):
    arr = [int(x) for x in input().split()]
    sum = arr[0] + arr[1]
    yr = yrank(sum + 1)
    temp = [0, sum]
    # temp.append(arr[1])
    if arr[1] != 0:
        yr += arr[0]
        print(yr)
    else:
        print(xrank(sum + 1))