
def ok(x):
    return x >= 0.5
def ans(s, l):
    if s[0] == '0':
        count = 0; frac = 0
    else:
        return "YES"
    for i in range(1, l):
        if s[i] == "1":
            count += 1
        frac = (count)/(i+1)
        if ok(frac):
            return "YES"

    return "NO"


for _ in range(int(input())):
    l = int(input())
    s = input()
    print(ans(s,l))
