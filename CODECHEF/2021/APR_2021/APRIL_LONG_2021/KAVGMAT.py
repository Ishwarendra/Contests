def func(mat, n, m, k, order):
    value = 0
    min = min(n,m)
    while order < min + 1:
        i = order; j = m
        while i < (n+1):
            x = i + 1 - order
            y = j + 1 - order
            z = mat[i][j] - mat[x-1][j] - mat[i][y-1] + mat[x-1][y-1]

            if z/(order*order) < k:
                i += 1
            else:
                l = i + 1 - order
                high = mid + 1 - order
                z 
