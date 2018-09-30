def kemija():
    rawInput = raw_input()
    outWord = ""
    i = 0
    while len(rawInput) > i:
        if rawInput[i] in 'aeiou':
            outWord += rawInput[i]
            i+=3
        else:
            outWord += rawInput[i]
            i+=1
    print outWord
kemija()
'''
def kemija():
    rawInput=raw_input()
    outWord=""
    for letter in rawInput:
        if letter in 'aeiou':
            outWord += letter
            outWord += "p"
            outWord += letter
        else:
            outWord += letter
    print outWord
kemija()
'''