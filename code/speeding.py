numInputs = int(input())

maxSpeed = -1
lastTime = 0
lastDist = 0
for i in range(numInputs):
    pair = input().split()
    pair[0] = int(pair[0])
    pair[1] = int(pair[1])
    
    denom = (pair[0] - lastTime)
    numer = (pair[1] - lastDist)
    if(denom == 0):
        denom = 1
    newSpeed =  numer // denom
    
    if(newSpeed > maxSpeed):
        maxSpeed = newSpeed
        
    lastTime = pair[0]
    lastDist = pair[1]
print(maxSpeed)