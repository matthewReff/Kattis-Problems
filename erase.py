def erase():
    flips = input()
    string1 = raw_input()
    string2 = raw_input()
    flipped = True
    if flips % 2 == 1:
        for i in range(0, len(string1)):
            if string2[i] == string1[i]:
                flipped = False
        if flipped:
            print "Deletion succeeded"
        else:
            print "Deletion failed"
    else:
        for i in range(0, len(string1)):
            if string2[i] != string1[i]:
                flipped = False
        if flipped:
            print "Deletion succeeded"
        else:
            print "Deletion failed"
erase()