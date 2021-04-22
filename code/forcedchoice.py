firstLine = input()
firstLine = firstLine.split()
for i in range(len(firstLine)):
    firstLine[i] = int(firstLine[i])
 
n = firstLine[0]
p = firstLine[1]
s = firstLine[2]

for i in range(s):
    newLine = input()
    newLine = newLine.split()
    for i in range(len(newLine)):
        newLine[i] = int(newLine[i])
    
    contains = False
    for index in newLine[1:]:
        if(index == p):
            contains = True
    if contains:
        print("KEEP")
    else:
        print("REMOVE")
    