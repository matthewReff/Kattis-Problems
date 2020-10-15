def rollCall():
    names = []
    usedNames = []
    alreadyUsed = []
    while(True):
        try:
            name = raw_input()
            name = name.split()
            names.append([name[1],name[0]])
            if name[0] in usedNames:
                alreadyUsed.append(name[0])
            usedNames.append(name[0])
           
        except EOFError:
            break
    names.sort()
    for i in range(0,len(names)):
        outString = ""
        outString += names[i][1]
        if names[i][1] in alreadyUsed:
            outString += " " + names[i][0]
        print outString
rollCall()