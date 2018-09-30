def eligibility():
    numStudents = input()
    responces = ["eligible", "ineligible", "coach petitions"]
    for i in range(0, numStudents):
        info = raw_input()
        infoList = info.split()
        state = 0
        if infoList[1] < "2010/01/01" and infoList[2] < "1991/01/01":
            state = 1
        if state == 1 and int(infoList[3]) < 41:
            state = 2
        print infoList[0] + " " + responces[state]
eligibility()