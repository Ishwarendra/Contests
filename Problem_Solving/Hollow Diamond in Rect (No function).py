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
n = 7
print("*"*n)
n -= 2

for i in range(1, n//2 + 2):
	print("*"*(n - i - 1) + " "*(2*i - 1) + "*"*(n - i - 1))
for i in range(n//2, 0, -1):
	print("*"*(n-i-1) + " "*(2*i - 1) + "*"*(n - i -1))
print("*"*(n+2))