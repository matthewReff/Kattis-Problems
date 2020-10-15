firstLine = input()
firstLine = firstLine.split()

inMolecule = firstLine[0]
numMolecules = int(firstLine[1])
outMolecule = input()

elementsIn = dict()
i = 0
while i < len(inMolecule):
	currentChar = inMolecule[i]
	tempString = ""
	elementNum = 1
	i += 1
	while(i < len(inMolecule) and inMolecule[i].isdigit()):
		tempString += inMolecule[i]
		i += 1
	if tempString:
		elementNum = int(tempString)

	if currentChar in elementsIn:
		elementsIn[currentChar] += elementNum
	else:
		elementsIn[currentChar] = elementNum

elementsOut = dict()
i = 0
while i < len(outMolecule):
	currentChar = outMolecule[i]
	tempString = ""
	elementNum = 1
	i += 1
	while(i < len(outMolecule) and outMolecule[i].isdigit()):
		tempString += outMolecule[i]
		i += 1
	if tempString:
		elementNum = int(tempString)
	if currentChar in elementsOut:
		elementsOut[currentChar] += elementNum
	else:
		elementsOut[currentChar] = elementNum


valid = True
mostPossible = 10 ** 2501
for entry, amount in elementsOut.items():

	if entry not in elementsIn:
		valid = False
	else:
		divValue = elementsIn[entry] * numMolecules // elementsOut[entry]
		if divValue < mostPossible:
			mostPossible = divValue

if valid:
	print(mostPossible)
else:
	print(0)
