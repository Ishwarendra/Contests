# cook your dish here
def giveFreqMap(arr):
    d = {}
    for i in arr:
        if i not in d:
            d[i] = 1
    return d

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = [int(y) for y in input().split()]
    freqA = giveFreqMap(a)
    freqB = giveFreqMap(b)
    count = 0
    for i in freqA:
        if freqB.get(i, None) != None:
            if freqA[i] == freqB[i]:
                count += 1
    print(count)    