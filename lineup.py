def lineEmUp():
    alphaDict={'A': 1, 'C': 3, 'B': 2, 'E': 5, 'D': 4, 'G': 7, 'F': 6, 'I': 9, 'H': 8, 'K': 11, 'J': 10, 'M': 13, 'L': 12, 'O': 15, 'N': 14, 'Q': 17, 'P': 16, 'S': 19, 'R': 18, 'U': 21, 'T': 20, 'W': 23, 'V': 22, 'Y': 25, 'X': 24, 'Z': 26}
    numDict={}
    dataSets=raw_input()
    inputStorage=[]
    rawInput=''
    nameNums=[]
    sortedNameNums=[]
    reverseSortedNameNums=[]
    
    for i in range(0,int(dataSets)): #takes in input and converted to number lists
        rawInput=raw_input()
        inputStorage.append(rawInput)
        nameNums.append([])
        for j in inputStorage[i]:
            nameNums[i].append(alphaDict[j])
            
    sortedNameNums=sorted(nameNums) #created a sorted and revesesorted list
    for i in range(0,len(sortedNameNums)):
        reverseSortedNameNums.append(sortedNameNums[len(sortedNameNums)-1-i])
        
    if sortedNameNums==nameNums: #checks numNames against what an increasing/decreasing list
        print "INCREASING"       #with the elements would look like
    elif nameNums==reverseSortedNameNums:
        print "DECREASING"
    else:
        print "NEITHER"
    
    
lineEmUp()
