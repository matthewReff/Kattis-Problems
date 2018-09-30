def savingdaylight():
    while True:
        try:
            conString = ""
            data = raw_input()
            dataArr = data.split()
            time1 = dataArr[3].split(":")
            time2 = dataArr[4].split(":")
            hour1 = int(time1[0])
            hour2 = int(time2[0])
            min1 = int(time1[1])
            min2 = int(time2[1])
            for i in range(0, 3):
                conString += dataArr[i]
                conString += " "
            if min2 - min1 < 0:
                hour1 += 1
                min1  -= 60
            conString += str(hour2 - hour1)
            conString += " hours "
            conString += str(min2 - min1)
            conString += " minutes"
            print conString
        except EOFError:
            break
savingdaylight()