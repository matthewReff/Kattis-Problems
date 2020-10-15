def karte():
    inputString = raw_input()
    cards = len(inputString) / 3
    suit = ""
    number = ""
    notError = True
    totalP = 13
    totalK = 13
    totalH = 13
    totalT = 13
    outString = ""
    P = []
    K = []
    H = []
    T = []
    for i in range(0,13):
        P.append(False)
        K.append(False)
        H.append(False)
        T.append(False)
    i = 0
    while (i < cards and notError):
        suit = inputString[i*3:i*3+1]
        num = inputString[i*3+1:i*3+3]
        num = int(num)
        if suit == "P":
            if P[num - 1]:
                notError = False
            else:
                P[num - 1] = True
                totalP -= 1
        elif suit == "K":
            if K[num - 1]:
                notError = False
            else:
                K[num - 1] = True
                totalK -= 1
        elif suit == "H":
            if H[num - 1]:
                notError = False
            else:
                H[num - 1] = True
                totalH -= 1
        elif suit == "T":
            if T[num - 1]:
                notError = False
            else:
                T[num - 1] = True
                totalT -= 1
        i += 1
    if not notError:
        outString += "GRESKA"
    else:
        outString += str(totalP) + " "
        outString += str(totalK) + " "
        outString += str(totalH) + " "
        outString +=str(totalT)
    print outString
karte()