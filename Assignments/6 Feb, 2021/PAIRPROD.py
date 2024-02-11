print(2)
def pair_product(arr):
    sum = 0
    square_sum = 0
    for i in arr:
        sum += i
    sum_square = sum*sum # First sum then square
    for j in arr:
        square_sum += j*j #First square then sum
    val = (sum_square - square_sum)//2
    return val
n = int(input())
arr = []
for i in range(n):
    x =  int(input())
    arr.append(x)
print(pair_product(arr))
    
