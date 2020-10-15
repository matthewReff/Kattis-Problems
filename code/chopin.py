def chopin():
    inputString = ""
    caseNum = 0
    keyDict = {"A":"UNIQUE", "A#":"Bb", "Bb":"A#","B":"UNIQUE", "C":"UNIQUE", 
    "C#":"Db", "Db":"C#", "D":"UNIQUE", "D#":"Eb", "Eb":"D#", "E":"UNIQUE",
    "F":"UNIQUE", "F#":"Gb", "Gb":"F#", "G":"UNIQUE", "G#":"Ab", "Ab":"G#"} 
    
    try:
        while(True):
            caseNum += 1
            inputArr = []
            inputString = raw_input()
            inputArr = inputString.split()
            if keyDict[inputArr[0]] == "UNIQUE":
                print "Case " + str(caseNum) + ": UNIQUE"
            else:
                print "Case " + str(caseNum) + ": " + keyDict[inputArr[0]] + " " + inputArr[1]
    except(EOFError, IndexError):
        pass
chopin()