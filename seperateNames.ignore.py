import sys

filename = sys.argv[1]    
fileList = []
with open(filename) as fileObj:
    for line in fileObj:
    	for subFile in line.split():
    		fileList.append(subFile)

fileList.sort()
for file in fileList:
	print(file)