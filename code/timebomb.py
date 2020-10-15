ascii_0 =  ["***",
			"* *",
			"* *",
			"* *",
			"***"]

ascii_1 =  ["  *",
			"  *",
			"  *",
			"  *",
			"  *"]

ascii_2 =  ["***",
			"  *",
			"***",
			"*  ",
			"***"]

ascii_3 =  ["***",
			"  *",
			"***",
			"  *",
			"***"]

ascii_4 =  ["* *",
			"* *",
			"***",
			"  *",
			"  *"]

ascii_5 =  ["***",
			"*  ",
			"***",
			"  *",
			"***"]

ascii_6 =  ["***",
			"*  ",
			"***",
			"* *",
			"***"]

ascii_7 =  ["***",
			"  *",
			"  *",
			"  *",
			"  *"]

ascii_8 =  ["***",
			"* *",
			"***",
			"* *",
			"***"]

ascii_9 =  ["***",
			"* *",
			"***",
			"  *",
			"***"]

ascii_arr = (ascii_0, ascii_1, ascii_2, ascii_3, ascii_4, ascii_5, ascii_6, ascii_7, ascii_8, ascii_9)

inputArr = []
for i in range(5):
	thisLine = input()
	inputArr.append(thisLine)

length = len(inputArr[0])

num_ints = (length + 1) // 4

validArr = []
for i in range(num_ints):
	validArr.append([])
	for j in range(10):
		validArr[i].append(True)

for i in range(5):
	for j in range(0, num_ints*4, 4):
		currIndex = j//4
		thisCompare = inputArr[i][j] + inputArr[i][j+1] + inputArr[i][j+2]
		for k in range(10):
			for subChar in range(3):
				if  thisCompare[subChar] != ascii_arr[k][i][subChar]:
					#print("setting ", currIndex, k, " to false from",  thisCompare, ascii_arr[k][i])
					validArr[currIndex][k] = False

'''
for i in range(num_ints):
	for j in range(10):
		if validArr[i][j]:
			print("YE ", end='')
		else:
			print("NO ", end='')
	print()
'''

allValid = True
createdString = ""
for i in range(num_ints):
	atLeastOne = False
	for j in range(10):
		if validArr[i][j]:
			createdString += str(j)
			atLeastOne = True
	allValid &= atLeastOne
if allValid and int(createdString) % 6 == 0:
	print("BEER!!")
	#print(int(createdString))
else:
	print("BOOM!!")
	#print(int(createdString))
