# cook your dish here
a = input()
b = a.split()
x = int(b[0])
y = int(b[1])
    

if y >= x+0.5 and x % 5==0:
    res = y - x -0.5
    print("%.2f" %res)
else:
    res = y
    print("%.2f"  %res)

