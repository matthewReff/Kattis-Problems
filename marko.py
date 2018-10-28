phone = dict()
phone.update({2:["a", "b", "c"], 3:["d", "e", "f"],
    4:["g", "h", "i"], 5:["j", "k", "l"], 6:["m", "n", "o"],
    7:["p", "q", "r", "s"], 8:["t", "u", "v"], 9:["w", "x", "y", "z"]})
wordList = []
validWords = []    
words = input()
for i in range(0, words):
    temp = raw_input()
    validWords.append(True)
    wordList.append(temp)
pressed = raw_input()

for i in range(0, len(pressed)):
    temp = int(pressed[i]) #is number pressed on numpad
    for j in range(0, words):
        if len(wordList[j]) < len(pressed) or wordList[j][i] not in phone[temp]:
            validWords[j] = False
            
total = 0
for i in validWords:
    if i:
        total+= 1
print total