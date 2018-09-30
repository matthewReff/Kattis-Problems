def seven_wonders():
    rawInput=raw_input()
    cards=[0,0,0]
    total = 0
    for i in rawInput:
        if i =="T":
            cards[0]+=1
        elif i == "C":
            cards[1]+=1
        else:
            cards[2]+=1
    for i in cards:
        total+=i**2
    cards.sort()
    total+=cards[0]*7
    print total
seven_wonders()