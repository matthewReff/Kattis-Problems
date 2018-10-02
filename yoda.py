def yoda():
    num1 = input()
    num1 = str(num1)
    num2 = input()
    num2 = str(num2)
    num1String =""
    num2String =""
    out1 = ""
    out2 = ""
    
    if len(num1) > len(num2):
        for i in range(0, len(num1) - len(num2)):
            num2String+="0"
        num1String += num1
        num2String += num2
    elif len(num2) > len(num1):
        for i in range(0, len(num2) - len(num1)):
            num1String+="0"
        num1String += num1
        num2String += num2
    else:
        num1String += num1
        num2String += num2

    for i in range(0, len(num1String)):
        if num1String[i] > num2String[i]:
            out1 += num1String[i]
        elif num2String[i] > num1String[i]:
            out2 += num2String[i]
        else:
            out1 += num1String[i]
            out2 += num2String[i]
            
    if (len(out1) == 0):
        print "YODA"
    else:
        print int(out1)
    if (len(out2) == 0):
        print "YODA"
    else:
        print int(out2)
yoda()