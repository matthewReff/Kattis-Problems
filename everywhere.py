def uniqueCities():
    dataSets=raw_input()
    dataSets=int(dataSets)
    cityList=[]
    for i in range(0,dataSets):
        subSets=raw_input()
        subSets=int(subSets)
        for j in range(0,subSets):
            city=raw_input()
            if city not in cityList:
                cityList.append(city)
        print len(cityList)
        cityList=[]
            
uniqueCities()