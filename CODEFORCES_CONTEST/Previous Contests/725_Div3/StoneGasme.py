def LeftToRight(arr, mini, maxi):
    return max(mini + 1, maxi + 1)

def RighttoLeft(arr, maxi, mini):
    return max(len(arr) - maxi, len(arr) - mini)

def RightThenLeft(arr, mini, maxi):
    return min(mini + 1, maxi + 1) + min(len(arr) - maxi, len(arr) - mini)

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    max_idx = a.index(max(a))
    min_idx = a.index(min(a))
    
    move1, move2, move3= LeftToRight(a, min_idx, max_idx), RighttoLeft(a, min_idx, max_idx), RightThenLeft(a, min_idx, max_idx)

    print(min(move1, move2, move3))
     

    
    
