from itertools import permutations as ways

w = int(input())

chef_knows = []

for _ in range(w):
	s = input()
	chef_knows.append(s)

encrypted_letters = input().split()

a = ['a','b','c','d','e','f','g','h']
p = ways(a)
x = {}
temp = {}
for _ in range(ord("i"), ord("z") + 1):
	temp[chr(_)] = chr(_)
	x[chr(_)] = chr(_)

for i in p:
	output = []
	x = temp
	for j in range(len(a)):
		x[i[j]] = a[j]
	for k in encrypted_letters:
		word = ""
		for l in range(len(k)):
			word += x[k[l]]
		if word in chef_knows:
			output.append(word)
	if len(output) == len(encrypted_letters):
		print(*output)
		break


chef
had
a
big
had
hdca deg e fib seb


	