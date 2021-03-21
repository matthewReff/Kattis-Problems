cases = int(input())

for i in range(cases):
	line = input()
	case,base,n = tuple(line.split())

	case = int(case)
	base = int(base)
	n = int(n)

	baseString = ""
	for i in range(32, -1, -1):
		value = n // base**i
		n -= base**i * value
		if value > 9:
			value = chr(ord('A') + (value - 10))
		baseString += str(value)
		#print(n)
	#print(baseString)

	ssd = 0
	for index in range(len(baseString)):
		value = int(baseString[index], base)
		ssd += value ** 2
	print(case, ssd)