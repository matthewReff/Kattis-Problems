def duplicates():
    flag=False
    rawInput=raw_input()
    rawInput = rawInput.split()
    seen = []
    for i in rawInput:
        if i not in seen:
            seen.append(i)
        else:
            flag = True
    if flag == True:
        print "no"
    else:
        print "yes"
duplicates()