from collections import defaultdict

(maxCows, initialFarms, days) = input().split(' ')
maxCows = int(maxCows)
initialFarms = int(initialFarms)
days = int(days)

farmMap = defaultdict(lambda: 0)
farms = []

for i in range(initialFarms):
	val = int(input())
	if val != 0:
		farmMap[val] += 1

for i in range(51):
	newTotal = 0
	for key in farmMap:
		newTotal += farmMap[key]

	farms.append(newTotal)

	nextMap = defaultdict(lambda: 0)
	for key in farmMap:
		if key * 2 > maxCows:
			nextMap[key] += farmMap[key] * 2;
		else:
			nextMap[key * 2] += farmMap[key]
	farmMap = nextMap;


for i in range(days):
	queryIndex = int(input())
	print(farms[queryIndex])

#print(farms)