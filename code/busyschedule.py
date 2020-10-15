def busyschedule():
    times = input()
    while (times != 0):
        timeList = []
        for i in range(0, times):
            timeS = raw_input()
            time = timeS.split()
            time[0] = time[0].split(":")
            if time[1] == "a.m.":
                if time[0][0] == "12":
                    timeList.append([(0,int(time[0][1])), timeS])
                else:
                    timeList.append([(int(time[0][0]),int(time[0][1])), timeS])
            else:
                if time[0][0] == "12":
                     timeList.append([(12,int(time[0][1])), timeS])
                else:
                    timeList.append([(int(time[0][0])+12,int(time[0][1])), timeS])
            timeList.sort()
        
        for i in timeList:
            print i[1]
        print ""
                
        times = input()
    
    
busyschedule()