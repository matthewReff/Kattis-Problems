def musicalscales():
    indexDict = dict()
    notes = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
    valid = []
    scales = []
    songString = ""
    song = []
    noteNum = 0
    displayed = False
    noteNum = input()
    constructstring = ""
    for i in range(0,len(notes)):
        indexDict.update({notes[i]:i})
    for i in range(0,len(notes)):
        scales.append([notes[i], notes[(i+2) % 12], notes[(i+4) % 12],
        notes[(i+5) % 12], notes[(i+7) % 12], notes[(i+9) % 12],
        notes[(i + 11) % 12], notes[i]])
    songString = raw_input()
    song = songString.split()
    for i in notes:
        valid.append(True)
    for i in song: #notes in song
        for j in range(0,len(scales)): #for each scale in scales
            if i not in scales[j]:
                valid[j] = False
    for i in range(0,len(valid)):
        if valid[i]:
            displayed = True
            constructstring += scales[i][0] + " "
    if not displayed:
        constructstring += "none"
    print constructstring
musicalscales()