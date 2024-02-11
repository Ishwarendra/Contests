"""
For n = 7
*******
*** ***
**   **
*     *
**   **
*** ***
*******
"""

def star(x):
	return "*"*x
def space(x):
	return " "*x

n = 7
print("*"*n)
n -= 2

for i in range(1, n//2 + 2):
	print(star(n - i - 1) + space(2*i - 1) + star(n - i - 1))
for i in range(n//2, 0, -1):
	print(star(n-i-1) + space(2*i - 1) + star(n - i -1))
print("*"*(n+2))
