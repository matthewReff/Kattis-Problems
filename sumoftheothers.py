def sumoftheothers():
    while(True):
        try:
            total = 0
            numList = raw_input()
            numList = numList.split()
            for i in range(0, len(numList)):
                numList[i] = int(numList[i])
                total += numList[i]
            for i in range(0, len(numList)):
                if numList[i] == total - numList[i]:
                    print numList[i]
                    break
        except EOFError:
            break
sumoftheothers()