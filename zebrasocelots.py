def zebrasocelots():
    digits = input()
    nextDigit = ""
    binString = ""
    for i in range(0, digits):
        nextDigit = raw_input()
        if nextDigit == "Z":
            binString += "1"
        else:
            binString += "0"
    num = int(binString, 2)
    print (2**digits) - (num) - 1
    
    
zebrasocelots()