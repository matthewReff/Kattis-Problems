cases = int(input())

for i in range(cases):
	case, value = tuple(input().split())
	case = int(case)
	value = int(value)

	rei = (value * (value + 1)) // 2


	print(case, rei + value)