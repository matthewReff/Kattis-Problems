parseString = input();

problemArr = parseString.split(";")

ranges = []

for elem in problemArr:
	tempArr = elem.split("-")
	parsedArr = []
	for i in range(len(tempArr)):
		parsedArr.append(int(tempArr[i]))
	ranges.append(parsedArr)

total = 0

for elem in ranges:
	if len(elem) == 1:
		total += 1
	else:
		total += elem[1] - elem[0] + 1
print(total)
