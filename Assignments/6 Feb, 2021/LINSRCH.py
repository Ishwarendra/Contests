print(1)
n = int(input())
s = set([])
for i in range(n):
    x = int(input())
    s.add(x)
q = int(input())
for j in range(q):
    val = int(input())
    if val in s:
        print("yes")
    else:
        print("no")

