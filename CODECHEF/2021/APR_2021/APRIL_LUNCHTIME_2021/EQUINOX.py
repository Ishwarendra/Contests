# cook your dish here
t = int(input())
letter = {"E","Q","U","I","N","O","X"}
for _ in range(t):
    n, a, b = [int(x) for x in input().split()]
    spoint = 0; apoint = 0;
    for i in range(n):
        s = input()
        if s[0] in letter:
            spoint += a
        else:
            apoint += b 
    if spoint > apoint:
        print("SARTHAK")
    elif apoint > spoint:
        print("ANURADHA")
    else:
        print("DRAW")