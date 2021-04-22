numInputs = int(input())

running = True
lastTime = int(input())
total = 0


for i in range(1, numInputs):
    inputNum = input()
    inputNum = int(inputNum)
    
    if not running:
        running = True
        lastTime = inputNum
    else:
        running = False
        total += (inputNum - lastTime)
if running:
    print("still running")
else:
    print(total)