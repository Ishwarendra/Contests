# cook your dish here
def count_sort(arr):
    max_element = max(arr)
    count = [0]*(max_element + 1)
    for i in range(len(arr)):
        count[arr[i]] += 1 
    
    for i in range(1, len(count)):
        count[i] += count[i-1]
    print(count)
    output = [0]*len(arr)
    
    for k in range(len(arr)-1, -1, -1):
        output[count[arr[k]] - 1] = arr[k]
        count[arr[k]] -= 1
        print(output)
    return output

t = int(input())

for _ in range(t):
    n = int(input())
    li = [int(x) for x in input().split()]
    print(*count_sort(li))    
