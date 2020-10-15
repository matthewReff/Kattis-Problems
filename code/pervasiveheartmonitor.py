def pervasiveheartmonitor():
    inString = ""
    while(True):
        try:
            inString = raw_input()
            data = []
            avgBeats = 0
            sumBeats = 0
            dataPoints = 0        
            name = ""
            data = inString.split()
            for i in data:
                try:
                    testFloat = float(i)
                    sumBeats += testFloat
                    dataPoints += 1
                except ValueError:
                    name += i + " "
            avgBeats = float(sumBeats) / dataPoints
            print str(avgBeats) + " " + name
        except EOFError:
            break
pervasiveheartmonitor()