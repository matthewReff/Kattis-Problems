def falsesecurity():
    morseDict = {"A": ".-", "B": "-...", "C":"-.-.", "D": "-..", "E":".",
    "F":"..-.", "G":"--.", "H":"....", "I":"..", "J":".---", "K":"-.-", "L": ".-..",
    "M":"--", "N":"-.", "O":"---", "P":".--.", "Q": "--.-", "R":".-.", "S":"...",
    "T":"-", "U":"..-", "V":"...-", "W":".--", "X":"-..-", "Y":"-.--", "Z":"--..",
    "_":"..--", ".":"---.", ",":".-.-", "?":"----"}
    morseReverseDict = dict()
    for i in morseDict.keys():
        morseReverseDict.update({morseDict[i]:i})
    while True:
        try:
            encoded = raw_input()
            morseEncoded = ""
            decoded = ""
            currPlace = 0
            decodeLens = []
            subStr = ""
            for i in encoded:
                morseEncoded += morseDict[i]
                decodeLens.append( len(morseDict[i]))
            decodeLens.reverse()
            for i in decodeLens:
                subStr = morseEncoded[currPlace:currPlace+i]
                currPlace += i
                decoded += morseReverseDict[subStr]
            print decoded
        except EOFError:
            break
    
falsesecurity()