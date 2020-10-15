def synchronizinglists():
    listLen = input()
    sortingDict = dict()
    tempIn = 0
    list1 = []
    list2 = []
    tempList = []
    while (listLen != 0):
        sortingDict.clear()
        tempIn = 0
        list1 = []
        list2 = []
        tempList = []
        for i in range(0,listLen):
            tempIn = input()
            list1.append(tempIn)
        for i in range(0,listLen):
            tempIn = input()
            list2.append(tempIn)
        for i in list1:
            tempList.append(i)
        list1.sort()
        list2.sort()
        for i in range(0,listLen):
            sortingDict.update({list1[i]:list2[i]})
        list2 = []
        for i in range(0,listLen):
            list2.append(sortingDict[tempList[i]])
        for i in list2:
            print i
        print ""
        listLen = input()
synchronizinglists()