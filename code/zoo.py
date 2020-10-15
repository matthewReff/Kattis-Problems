def zoo():
    animals = input()
    listNum = 0
    nameList = []
    tempList = []
    pens = dict()
    animal = ""
    while(animals != 0):
        pens = dict()
        listNum += 1
        for i in range(0, animals):
            animal = raw_input()
            animal = animal.lower()
            nameList = animal.split()
            if nameList[len(nameList)-1] not in pens:
                pens.update({nameList[len(nameList)-1]:1}) 
            else:
                pens[nameList[len(nameList)-1]] += 1
        tempList = sorted(pens.keys())
        print "List " + str(listNum) + ":"
        for i in tempList:
            print i + " | " + str(pens[i])
        animals = input()
zoo()