inf_p = int(1e10)
inf_n = int(-1e10)
def lessthan(a,b):
	if (a[1] == b[1] == 0):
		return a[0] < 0
	if (a[0]*b[1]) < (b[0]*a[1]):
		return True
	return False

def equalTo(a,b):
    return not (lessthan(a, b) and lessthan(b, a))

def check_positive(a):
    return (a[0] > 0) and (a[1] >= 0)

def check_infty(a):
    return a[1] == 0

def value(a):
    if a[1] == 0:
        if a[0] > 0:
            return inf_p
        else:
            return inf_n
    return (a[0]/a[1])

def superior_fraction(a,b):
    if check_positive(a) and check_positive(b):
        return a[0] < b[0]
    elif (not check_positive(a)) and (not check_positive(b)):
        return abs(a[0]) < abs(b[0])
    elif (check_positive(a)):
        return True
    elif check_positive(b):
        return False
    else:
        return a[0] > 0 and b[1] < 0

def get_distinct_fractions(arr):
    frac_value = {}
    values = []
    result = []
    for i in arr:
        if value(i) not in frac_value:
            # no element with that value then add
            frac_value[value(i)] = i
        else:
            # find better representation during clash
            if superior_fraction(i, frac_value[value(i)]):
                frac_value[value(i)] = i # update if better representation found

    for j in frac_value.keys():
        values.append(j)
    values.sort()

    for k in values:
        print(frac_value[k])
        result.append(frac_value[k])
    
    return result

        


