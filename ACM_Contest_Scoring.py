def scoring():
    incomingData=True
    rawInput=''
    processedArgs=[]
    completedProblems=""
    totalTime=0
    while incomingData==True: #create loop to allow variable input length
        rawInput=raw_input()
        if rawInput=='-1':
            incomingData=False
            continue
        processedArgs.append(rawInput.split())
    for i in processedArgs:
        i[0]=int(i[0])
    
    for i in processedArgs: #add correct problems to completesProblems string, and add time completed to total
        if i[2]=="right" and i[1] not in completedProblems:
            completedProblems+=i[1]
            totalTime+=i[0]
            
    for i in processedArgs: # after all correct problems are known, add penatly score for alls that were submitted wrong but were eventually completed
        if i[2]=="wrong" and (i[1] in completedProblems):
            totalTime+=20
    print len(completedProblems), totalTime
    
scoring()