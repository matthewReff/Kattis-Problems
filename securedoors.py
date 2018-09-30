def securedoors():
    entries = input()
    entry = ""
    building = []
    for i in range(0,entries):
        entry = raw_input()
        entry = entry.split()
        if entry[0] == "entry":
            if entry[1] not in building:
                building.append(entry[1])
                print entry[1] + " entered"
            else:
                print entry[1] + " entered (ANOMALY)"
        else:
            if entry[1] in building:
                building.remove(entry[1])
                print entry[1] + " exited"
            else:
                print entry[1] + " exited (ANOMALY)"
        
securedoors()