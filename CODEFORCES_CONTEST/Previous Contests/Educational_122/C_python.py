from math import floor, ceil

Hc, Dc = -1, -1;

for _ in range(int(input())):
    hc, dc = [int(x) for x in input().split()]
    Hm, Dm = [int(x) for x in input().split()]
    
    k, w, a = [int(x) for x in input().split()]
    
    possible = False;
    
    for i in range(0, k + 1):
        Hc = hc + a*i;
        Dc = dc + (k - i)*w;        
        
        left = ceil(Hm/Dc);
        right = floor(Hc/Dm + 1) if Hc % Dm != 0 else Hc/Dm;
        
        if (right - left >= 0):
            possible = True
            break;
    
    if (possible):
        print("YES")
    else:
        print("NO")