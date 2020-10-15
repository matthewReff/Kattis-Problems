def blackfriday():
    uniques = []
    notUniques = []
    diffs = []
    inLine = input()
    people = raw_input()
    people = people.split()
    peopleCopy = []
    for i in people:
        peopleCopy.append(i)
    people.sort()
    for i in people:
        if i not in uniques:
            uniques.append(i)
        else:
            notUniques.append(i)
            
    for i in uniques:
        if i not in notUniques:
            diffs.append(i)
    if len(diffs) == 0:
        print "none"
    else:
        print peopleCopy.index(diffs[len(diffs)-1]) + 1
blackfriday()