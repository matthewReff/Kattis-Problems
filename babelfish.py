def babelfish():
    wordDict = dict()
    mode = True
    while(True):
        try:
            line = raw_input()
            if mode:
                if line != "":
                    line = line.split()
                    wordDict.update({line[1] : line[0]})
                else:
                    mode = False
            else:
                if line in wordDict:
                    print wordDict[line]
                else:
                    print "eh"
        except EOFError:
            break
babelfish()