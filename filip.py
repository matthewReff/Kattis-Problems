def filip():
    num1 = ''
    num2 = ''
    conNum1 = ''
    conNum2 = ''
    rawInput=raw_input()
    num1,num2 = rawInput.split()
    for i in range(0,3):
        conNum1 += num1[2-i]
        conNum2 += num2[2-i]
    num1 = int(conNum1)
    num2 = int(conNum2)
    if num1 > num2:
        print num1
    else:
        print num2
    
filip()