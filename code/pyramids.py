inputNumber = int(input())

total = 0
for i in range(1, 10001, 2):
    newBricks = int(i**2)
    if newBricks <= inputNumber:
        inputNumber -= newBricks
        total += 1
    else :
        print(total)
        break