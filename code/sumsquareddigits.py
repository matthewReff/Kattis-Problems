cases = input()
for i in range(1, cases + 1):
    numString = ""
    removed = 0
    square = 0
    line = raw_input()
    line = line.split()
    base = int(line[1])
    num = int(line[2])
    upperLimit = 0
    while( base ** (upperLimit + 1) <= num):
        upperLimit += 1
    while upperLimit != -1:
        removed = int(num / base ** upperLimit)
        if removed < 10:
            numString += str(removed)
        else:
            numString += chr(55+removed)
        num -= removed * base ** upperLimit
        upperLimit -= 1
    for j in numString:
        square += (int(j, base) * int(j, base))
        
  
    print str(i) + " " + str(square)