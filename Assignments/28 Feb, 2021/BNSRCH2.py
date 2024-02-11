import sys
 
def find_pos(x):
    print('1 ' + str(x))
    sys.stdout.flush()
    t = int(input())
    return t
# ----------------- Do not modify anything above this line -----------------------
# Complete this function count(n, x), this returns 0 always and hence is wrong, it should return the number of occurrences of x in Chef's array
# You can use the function find_pos(x) to find the value of the element at position x (0 indexed)
# If the index is invalid or you use more than 40 queries to obtain the value, you will receive Wrong Answer
# Chef's array size is not more than 10 ** 5
def frequency(x, low, high, T_F, ans):
	while low <= high:
		mid = (low + high)//2
		mid_pos = find_pos(mid)
		if mid_pos < x:
			low = mid + 1
		elif mid_pos > x:
			high = mid - 1
		else:
			ans = mid
			if T_F == True:
				high = mid - 1
			else:
				low = mid + 1
	return ans

def count(n, x):
	low = 0; high = n - 1; ans = -1
	left_part = frequency(x, low, high, True, ans)
	right_part = frequency(x, low, high, False, ans)
	if left_part == -1:
		return 0

	return (right_part - left_part + 1)
    
 
# ----------------- Do not modify anything below this line -----------------------
 
n = int(input())
x = int(input())
 
print('2 ' + str(count(n, x)))