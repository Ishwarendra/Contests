
# cook your dish here
for _ in range(int(input())):
    a, n = [int(x) for x in input().split()]
    if a%10 == 0:
        print(0)
    elif a%10 == 1:
        print(1)
    elif a%10 == 2:
        if n == 1:
            print(2)
        elif n == 2:
            print(4)
        else:
            print(6)
    elif a%10 == 3:
        if n ==1:
            print(3)
        elif n == 2:
            print(9)
        else:
            print(1)
    
    elif a%10 == 4:
        if n == 1:
            print(4)
        else:
            print(6)
    elif a%10 == 5 :
        print(5)
    elif a%10 == 6:
        print(6)
    elif a%10 == 7:
        if n == 1:
            print(7)
        if n == 2:
            print(9)
        else:
            print(1)
    elif a%10 == 8:
        if n == 1:
            print(8)
        elif n== 2:
            print(4)
        else:
            print(6)
    else:
        if n == 1:
            print(9)
        else:
            print(1)