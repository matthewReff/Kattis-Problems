from collections import defaultdict

def main():
    seenDict = defaultdict(returnZero)
    
    inputString = input()
    for letter in inputString:
        seenDict[letter] += 1

    for seenTimes in seenDict.values():
        if seenTimes != 1:
            print(0)
            return

    print(1)

def returnZero():
    return 0

main()