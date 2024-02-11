print(2)
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)
max = 0
count = 0
for j in range(len(arr)):
    if arr[j] > max:
        count += 1
        max = arr[j]
print(count)


