cases = input()

for i in range(0, cases):
    try:
        newLineEater = raw_input()
        totalCandy = 0
        children = input()
        for j in range(0, children):
            temp = input()
            
            totalCandy += temp
        if (totalCandy % children == 0):
            print "YES"
        else:
            print "NO"
    except (EOFError, SyntaxError):
        pass
       
