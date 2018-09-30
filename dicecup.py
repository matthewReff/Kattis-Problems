def dicecup():
    rawInput=raw_input()
    num1,num2 =rawInput.split()
    num1 = int(num1)
    num2 = int(num2)
    values = []
    index = 0
    experiment=dict()
    for i in range(1,num1+1):
        for j in range(1,num2+1):
            if (i + j) not in experiment.keys():
                experiment.update({(i+j):1})
            else:
                experiment[i+j]+=1
    for i in experiment.keys():
        if experiment[i] == max(experiment.values()):
            values.append(i)
    #for i in range(0,len(experiment.keys())):
    for i in range(0,len(values)):
        print str(values[i])
dicecup()
