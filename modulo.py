def Modulo():
    seenNums=[]
    inputNum=""
    for i in range(0,10):
        inputNum=raw_input()
        inputNum=int(inputNum)
        inputNum %= 42
        if inputNum not in seenNums:
            seenNums.append(inputNum)
    print len(seenNums)
Modulo()
