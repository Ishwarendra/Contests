def isPrime(n):
    if n == 0 or n == 1:
        return False
    if n == 2:
        return True
    else:
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return False
    return True

def get_prime(n): # prime less than n
    arr = [2,]
    for i in range(2, n):
          if isPrime(i):
              arr.append(i)
    return arr
def binary_search(arr, x, low, high):
    if low <= high:
        mid = low + (high - low)//2
        if x == arr[mid]:
            return mid
        if x > arr[mid]:
            return binary_search(arr, x, mid + 1, high)
        else:
            return binary_search(arr, x, low, mid - 1)
    return False
t = int(input())
for _ in range(t):
    n = int(input())
    primes = get_prime(n)
    ans = [-1, -1]
    for i in primes:
        Idx_or_False = binary_search(primes, n - i, 0, len(primes)-1)
        if Idx_or_False != False:
            ans[0] = i
            ans[1] = primes[Idx_or_False]
            break
        
    print(*ans)
        
