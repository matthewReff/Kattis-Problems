# Cheated a bit for this one, https://en.wikipedia.org/wiki/Brahmagupta%27s_formula
import math
sides = input().split()

for index in range(len(sides)):
    sides[index] = int(sides[index])
    
semi = (sides[0] + sides[1] + sides[2] + sides[3])/2

print(math.sqrt((semi - sides[0])*(semi-sides[1])*(semi-sides[2])*(semi-sides[3])))