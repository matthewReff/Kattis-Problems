def boatParts():
    numbers = raw_input()
    numbers = numbers.split()
    p = int(numbers[0])
    n = int(numbers[1])
    lastAdded = 0
    part = ""
    parts = []
    for i in range(0,n):
        part = raw_input()
        if part not in parts:
            parts.append(part)
            lastAdded = i+1
    if len(parts) == p:
        print lastAdded
    else:
        print "paradox avoided"
boatParts()