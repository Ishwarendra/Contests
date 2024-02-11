'''r = int(input())
count = 0
while count < r:
    l = int(input())
    arr = []
    s = input()
    for i in range(len(s)):
        if s[i] !=".":
            arr.append(s[i])
        if len(arr) == 0:
            print("Valid")
        elif (arr[0] != "H") or (arr[len(arr)-1] != "T"):
            print("Invalid")
        else:
            for j in range(0,len(arr)-1):
                if arr[j]==arr[j+1]:
                    print("Invalid")
                    break
                    
            
'''
R=int(input())
for i in range(R):
    N=int(input())
    A=[]
    L=str(input())[:N]
    for j in range(len(L)):
        if L[j]!=".":
            A.append(L[j])
    if len(A)==0:
        print("Valid")
    elif A[0]!="H" or A[len(A)-1]!="T":
        print("Invalid")
    else:
        for k in range(0,len(A)-1):
            if A[k]==A[k+1]:
                print("Invalid")
                break
        else:
            print("Valid")
