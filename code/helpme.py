def helpme():
    lineString = ""
    whiteList=[]
    blackList = []
    outWhiteList = []
    outBlackList = []
    appString = ""
    outString = ""
    sortedd = False
    for i in range(8, 0, -1):
        lineString = raw_input()
        lineString = raw_input()
        lineString = lineString.split("|")
        lineString = lineString[1:9]
        for j in range(0, len(lineString)):
            appString = ""
            if lineString[j][1] in "kqrbnp":
                if lineString[j][1] in "kqrbn":
                    appString += lineString[j][1].upper()
                appString += chr(j+97)
                appString += str(i)
                whiteList.append(appString[::-1])
            elif lineString[j][1] in "KQRBNP":
                if lineString[j][1] in "KQRBN":
                    appString += lineString[j][1].upper()
                appString += chr(j+97)
                appString += str(i)
                blackList.append(appString[::-1])
        whiteList.sort(reverse = True)
        blackList.sort()
        
  
    for i in whiteList:
        if "K" in i:
            outWhiteList.append(i[::-1])
    for i in whiteList:
        if "Q" in i:
            outWhiteList.append(i[::-1])
    for i in whiteList:
        if "R" in i:
            outWhiteList.append(i[::-1])
    for i in whiteList:
        if "B" in i:
            outWhiteList.append(i[::-1])
    for i in whiteList:
        if "N" in i:
            outWhiteList.append(i[::-1])
    for i in whiteList:
        if "K" not in i and "Q" not in i and "R" not in i and "B" not in i and "N" not in i:
            outWhiteList.append(i[::-1])
    
    for i in blackList:
        if "K" in i:
            outBlackList.append(i[::-1])
    for i in blackList:
        if "Q" in i:
            outBlackList.append(i[::-1])
    for i in blackList:
        if "R" in i:
            outBlackList.append(i[::-1])
    for i in blackList:
        if "B" in i:
            outBlackList.append(i[::-1])
    for i in blackList:
        if "N" in i:
            outBlackList.append(i[::-1])
    for i in blackList:
        if "K" not in i and "Q" not in i and "R" not in i and "B" not in i and "N" not in i:
            outBlackList.append(i[::-1])
            
            
    #Bodge Bubble Sort
    while not sortedd:   
        sortedd = True
        for i in range(0, len(outWhiteList) - 1):
            if len(outWhiteList[i]) == 3:
                if outWhiteList[i][0] == outWhiteList[i+1][0] and outWhiteList[i][2] == outWhiteList[i+1][2]:
                    if outWhiteList[i][1] > outWhiteList[i+1][1]:
                        temp =  outWhiteList[i]     
                        outWhiteList[i] = outWhiteList[i+1]
                        outWhiteList[i+1] = temp
                        sortedd = False  
    sortedd = False
    while not sortedd:   
        sortedd = True
        for i in range(0, len(outWhiteList) - 1):
            if len(outWhiteList[i]) == 2:
                if outWhiteList[i][1] == outWhiteList[i+1][1]:
                    if outWhiteList[i][0] > outWhiteList[i+1][0]:
                        temp =  outWhiteList[i]     
                        outWhiteList[i] = outWhiteList[i+1]
                        outWhiteList[i+1] = temp
                        sortedd = False  
    outString+= "White: "
    for i in outBlackList:
        outString += i + ","
    print outString[:-1]
    outString = ""
    outString += "Black: "
    for i in outWhiteList:
        outString+= i +","
    print outString[:-1]
    
    
    
helpme()