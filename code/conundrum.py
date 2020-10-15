def per():
    rawInput = raw_input()
    total = 0
    for i in range(0,len(rawInput)):
        if i % 3 == 0:
            if rawInput[i] != "P":
                total+=1
        elif i % 3 == 1:
            if rawInput[i] != "E":
                total+=1
        else:
            if rawInput[i] != "R":
                total+=1
    print total
per()