# Correct this function so that the correct output is given
inf_p = int(1e10)
inf_n = int(-1e10)


def check_positive(a): # here a is a tuple containing twoelements
    return (a[0] > 0) and (a[1] >= 0)
def check_negative(a):
    return (a[0] < 0) and (a[1] <= 0)

def check_infty(a):
    return a[1] == 0

def value(a):
    if a[1] == 0:
        if a[0] > 0:
            return inf_p
        else:
            return inf_n
    return (a[0]/a[1])

def superior_fraction(a,b):# whether a is better representation or not
    if check_positive(a) and check_positive(b):
        return a[0] < b[0]
    if (check_negative(a)) and (check_negative(b)):
        return abs(a[0]) < abs(b[0])
    if check_positive(a) and check_negative(b):
        return True
    if check_negative(a) and check_positive(b):
        return False
    if (a[0] < 0 and b[0] < 0) and (a[1] > 0 and b[1] > 0):
        return abs(a[0]) < abs(b[0])
    if (a[0] < 0 and a[1] < 0) and (b[0] < 0 and b[1] > 0):
        return abs(a[0]) < abs(b[0])
    else:
        return (a[0] < 0 and a[1] > 0) and (b[0] > 0 and b[1] < 0)

def get_distinct_fractions(arr):
    frac_value = {} # key -> value of fraction || value -> fraction tuple
    values = [] # store distinct values only.
    result = [] # store fraction tuples in asc order (of values)
    for i in arr:
        if value(i) not in frac_value:
            # no element with that value then add
            frac_value[value(i)] = i
        else:
            # find better representation during clash
            if superior_fraction(i, frac_value[value(i)]):
                frac_value[value(i)] = i # update iff better representation found

    for j in frac_value.keys():
        values.append(j)
    values.sort() #sort according to value of fraction

    for k in values:
        result.append(frac_value[k])
    
    return result

 
# ----------------------Do not change anything below this line --------------------------

n = int(input())
arr_strip = list(map(int, input().split()))
arr = []
for i in range(0, 2*n, 2):
    arr.append((arr_strip[i], arr_strip[i+1]))
 
result = get_distinct_fractions(arr)
print(len(result))
for x in result:
    print(x[0], x[1], end = ' ')