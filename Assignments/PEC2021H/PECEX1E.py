import sys

def n_mod_x(x):
    print('1 ' + str(x))
    sys.stdout.flush()
    return int(input())


# ------------------------------------Do not touch anything above this line! -----------------------------------------

# The following function always returns 2, you should complete it so that it returns the hidden value always
# You can call n_mod_x upto 150 times
def guess():
    low = 0; high = int(1e18)
    ans = 1
    while low <= high:
        mid = (high + low)//2
        mod_nx = n_mod_x(mid)
        if mod_nx == 0:
            ans = mid
            low = mid + 1
        else:
            if mod_nx == n_mod_x(mid+1):
                high = mid - 1
            else:
                low = mid + 1

    return ans

# ------------------------------------Do not touch anything below this line! -----------------------------------------

T = int(input())
while T > 0:
    print('2 ' + str(guess()))
    x = int(input())
    # assert(x == 1)
    T-= 1
