def isSubsequence(a, target): # is target subseq of a
	i = 0; j =0
	while i < len(target) and j < len(a):
		if a[j] == target[i]:
			i += 1
		j += 1
	return i == len(target)

def binaryToDecimal(x): # inp -> Bstring; out -> int
	x = list(x); sum = 0
	for i in range(len(x) - 1, -1, -1):
		sum += int(x[i])*pow(2, len(x)-i-1)
	return sum

def decimalToBinary(n): # inp -> int; out -> string
    return "{0:b}".format(int(n))

for _ in range(int(input())):
	n = input()
	x = binaryToDecimal(n)
	for i in range(0, x + 2):
		i_bin = decimalToBinary(i)
		if not isSubsequence(n, i_bin):
			print(i_bin)
			break
