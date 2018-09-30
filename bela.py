def bela():
    scoresDict={'A':[11,11],'K':[4,4],'Q':[3,3],'J':[20,2],'T':[10,10],'9':[14,0],'8':[0,0],'7':[0,0]}
    rawInput=""
    rawInput=raw_input()
    rawInput=rawInput.split()
    numHands = int(rawInput[0])
    suit = rawInput[1]
    numHands=int(numHands)
    total = 0
    for i in range(0,numHands * 4):
        rawInput=raw_input()
        if rawInput[1] == suit:
            total+=scoresDict[rawInput[0]][0]
        else:
            total+=scoresDict[rawInput[0]][1]
    print total
        
        
    
bela()