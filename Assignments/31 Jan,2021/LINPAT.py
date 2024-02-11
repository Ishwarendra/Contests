def num_pattern(n, l):
	if n == 1:
		l.append(10)
	elif n == 2:
		num_pattern(n - 1, l)
		l.append(2)
	else:
		if n % 2 == 0:
			term = 2
		else:
			term = 10
		num_pattern(n - 1, l)
		l.append(l[n - 3] + term)
