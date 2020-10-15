def potato():
    potato=raw_input()
    potatoConst=""
    potatoConst+=potato[0]
    for i in range(1,len(potato)):
        if potato[i] != potato[i-1]:
            potatoConst+=potato[i]
    print potatoConst
potato()