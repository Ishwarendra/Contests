x1, y1, x2, y2 = [int(x) for x in input().split()]

# 2^2 + 1^2 or 1^2 + 2^2
possible_x1 = [x1 + 2, x1 - 2]
possible_x2 = [x1 + 1, x1 - 1]
possible_y1 = [y1 + 1, y1 - 1]
possible_y2 = [y1 + 2, y1 - 2]

ok = False

for x in possible_x1:
	for y in possible_y1:
		if abs(x - x2) == 2:
			if (abs(y - y2) == 1):
				# print(x, y)
				ok = True
				
		elif abs(x - x2) == 1:
			if (abs(y - y2) == 2):
				# print(x, y)
				ok = True
				
for x in possible_x2:
	for y in possible_y2:
		if abs(x - x2) == 2:
			if (abs(y - y2) == 1):
				# print(x, y)
				ok = True
				
		elif abs(x - x2) == 1:
			if (abs(y - y2) == 2):
				# print(x, y)
				ok = True
 
if ok:
	print("Yes")
else:
	print("No")