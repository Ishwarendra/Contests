from math import log

def lessThan(a, b):
    return 2*a[1]*log(a[0]) < 2*b[1]*log(b[0])
def equalTo(a, b):
    return 2*a[1]*log(a[0]) == 2*b[1]*log(b[0])
def greaterThan(a, b):
    return lessThan(b, a)

for i in range(2, 10**5 + 1):
    for j in range(2, 10**5 + 1):
        