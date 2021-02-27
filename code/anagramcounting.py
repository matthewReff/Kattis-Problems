from collections import defaultdict
from sys import stdin

fact = [1,1]
for i in range(2, 101):
	fact.append(fact[-1] * i)


for inString in stdin:
	inString = inString.rstrip()
	totalLength = len(inString)
	letters = defaultdict(lambda: 0)
	for letter in inString:
		letters[letter] += 1

	total = fact[totalLength]
	for key in letters:
		total //= fact[letters[key]]
	print(total)
