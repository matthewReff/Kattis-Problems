numInputs = int(input())

total = int(input())
for index in range(1, numInputs):
    thisValue = int(input())
    total += (thisValue - 1)
    
print(total)