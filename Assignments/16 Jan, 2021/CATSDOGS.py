t = int(input())
count = 0
while count < t:
    c, d, l = [int(x) for x in input().split() ]
    if l % 4 != 0:
        print("no")
    elif (c - 2*d >= 0):
        if (l <= 4*(c+d)) and (l >= 4*(c-d)):
            print("yes")
        else:
            print("no")
    elif (c - 2*d < 0):
        if (l <= 4*(c+d)) and (l >= 4*d):
            print("yes")
        else:
            print("no")
    count +=1
