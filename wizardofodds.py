import math
nums = raw_input()
nums = nums.split()

n = int(nums[0])
guesses = int(nums[1])

if math.ceil(math.log(n,2)) <= guesses:
    print "Your wish is granted!"
else:
    print "You will become a flying monkey!"
