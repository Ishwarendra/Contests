"""
For n = 7
*
 * *
   * * *
     * * * *
   * * *
 * *
*
"""

n = int(input())
print("*")
n = n - 2
for i in range(1, n//2 + 2):
	print(" "*(2*i - 2) + " *"*(i + 1))
for i in range(n//2, 0, -1):
	print(" "*(2*i - 2) + " *"*(i + 1))

print("*")
