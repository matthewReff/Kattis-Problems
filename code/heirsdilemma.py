nums = raw_input()
nums = nums.split()
low = int(nums[0])
high = int(nums[1])
total = 0
for i in range(low, high+1):
    temp = str(i)
    seen = []
    valid = True
    for j in temp:
        if j == "0" or i % int(j) != 0 or j in seen:
            valid = False
        seen.append(j)
    if valid:
        total += 1
print total