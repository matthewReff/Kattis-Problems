def trik():
    instruct=raw_input()
    holder = ""
    ball=["X","",""]
    for i in instruct:
        if i == "A":
            holder=ball[0]
            ball[0]=ball[1]
            ball[1]=holder
            holder=""
        if i == "B":
            holder=ball[1]
            ball[1]=ball[2]
            ball[2]=holder
            holder=""
        if i == "C":
            holder=ball[0]
            ball[0]=ball[2]
            ball[2]=holder
            holder=""
    if ball[0] == "X":
        print 1
    if ball[1] == "X":
        print 2
    if ball[2] == "X":
        print 3
trik()
