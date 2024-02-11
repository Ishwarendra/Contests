# you can use this less than comparator operator in the choose_pivot, if you would like
# keep in mind that this is the comparator used in the quick sort implementation given
def lessthan(x, y):
    return x[0] < y[0]
 
# complete this function
# the return value is wrong, you are to complete this function so that the return value is correct
# arr is a list of tuples where each tuple contains the pair (x, y)
def choose_pivot(arr):
    freq_map = dict()
    store_not_first = set()
    candidate = []
    idx = 0
    for element in arr:
        if element[0] not in freq_map:
            freq_map[element[0]] = 1
        else:
            freq_map[element[0]] += 1
            store_not_first.add(idx)
        idx += 1
    
    for i in range(len(arr)):
        if i not in store_not_first:
            candidate.append(i)
    return candidate

 
# ---------------------------- Do not modify code below this line ------------------------------------
n = int(input())
arr_strip = list(map(int, input().split()))
arr = []
for i in range(0, 2*n, 2):
    arr.append((arr_strip[i], arr_strip[i+1]))
 
candidates = choose_pivot(arr)
 
print(len(candidates))
print(*candidates)
 