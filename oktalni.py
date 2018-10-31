binary = input()
binary = str(binary)
thing = dict()
thing.update({"000":"0", "001":"1", "010":"2", "011":"3", "100":"4", "101":"5", "110":"6", "111":"7"})
tempString = ""
outString = ""
miniString = ""
if len(binary) % 3 != 0:
    for i in range(0, 3 - len(binary)%3):
        tempString += "0"
tempString += binary
for i in range(0, len(tempString)/3):
    miniString = tempString[3*i:3*(i+1)]
    outString += thing[miniString]
print outString