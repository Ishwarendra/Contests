n = 7;
a = [[i + 1 for i in range(0, n)] for j in range(0, n)]

def disp():
    for x in a:
        print(*x)
for i in range(n):
    a[i][0] = n - i;
# for i in range(n):
#     a[1][i] = n - i;
# for i in range(n):
#     a[2][i] = n - i;
disp();


s = 0
for i in range(n):
    s += sum(a[i])

print(s)