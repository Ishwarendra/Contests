# cook your dish here
for _ in range(int(input())):
    n = int(input())
    rem = n%4
    sum = (n//4)*(44)
    if n ==1:
        print(20)
    elif n == 2:
        print(36)
    elif n == 3:
        print(51)
    elif n ==4:
        print(60)
    else:
        if rem == 0:
            sum += 16
        elif rem == 1:
            sum += 32
        elif rem == 2:
            sum += 44
        elif rem == 3:
            sum += 55
            
        print(sum)
            
        