num = input()
found = False
while (not found):
    total = 0
    numStr = str(num)
    for i in numStr:
        total += int(i)
    if num % total == 0:
        found = True
        print num
    else:
        num += 1
    