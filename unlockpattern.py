import math
def unlockPattern():
    distance = 0.0
    line1 = raw_input()
    line1 = line1.split()
    line2 = raw_input()
    line2 = line2.split()
    line3 = raw_input()
    line3 = line3.split()
    
    combo = []
    coords = []
    for i in range(0,3):
        combo.append(int(line1[i]))
        combo.append(int(line2[i]))
        combo.append(int(line3[i]))
    for i in range(0,9):
        coords.append([])
    for i in range(0,9):
        coords[combo[i] - 1] = [i/3, i%3]
    for i in range(1,9):
        temp = math.sqrt((coords[i][1] - coords[i-1][1]) ** 2 + (coords[i][0] - coords[i-1][0]) ** 2)
        distance += temp
    print distance
unlockPattern()