from math import floor, sqrt
import sys

def get_inpt(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))

def p_str(x): sys.stdout.write(x+"\n")
def p_int(x): sys.stdout.write(str(x) + "\n")
def p_arr(arr): sys.stdout.write(" ".join(map(str, arr)) + "\n")


def simpleSieve(limit, primes):
	mark = [False]*(limit+1)

	for i in range(2, limit+1):
		if not mark[i]:
			primes.append(i)
			for j in range(i, limit+1, i):
				mark[j] = True

def primesInRange(low, high):
	s = 0
	limit = floor(sqrt(high)) + 1
	primes = list()
	simpleSieve(limit, primes)
	
	if low < 2:
		low=2

	n = high - low + 1
	mark = [False]*(n+1)
	for i in range(len(primes)):
		loLim = floor(low/primes[i]) * primes[i]
		if loLim < low:
			loLim += primes[i]
		if loLim == primes[i]:
			loLim += primes[i]
		for j in range(loLim, high+1, primes[i]):
			mark[j-low] = True
	for i in range(low, high+1):
		if not mark[i-low]:
			s += 1
	return s
# print(primesInRange(7,14))
for _ in range(get_int()):
	n = get_int(); ans = 1
	if n == 2:
		print(1)
		continue
	elif n == 3:
		print(2)
		continue
	else:
		ans += primesInRange(n//2 + 1, n)
	p_int(ans)




