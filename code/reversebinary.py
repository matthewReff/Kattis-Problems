def reverseBinary():
    convertString=raw_input()
    convertedString=""
    convertString=int(convertString)
    convertString=bin(convertString)
    convertString=convertString[2:]
    for i in range(len(convertString),0,-1):
        convertedString +=convertString[i-1]
    convertedString=int(convertedString,2)
    print convertedString
reverseBinary()