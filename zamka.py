def zamka():
    l = int(input())
    d = int(input())
    x = int(input())
    found = False
    i = l
    while i <= d and i >= l and not found:
        digitSum = 0
        for j in str(i):
            digitSum += int(j) 
        if digitSum == x:
           found = True
           print i
        i += 1
    found = False
    i = d
    while i <= d and i >= l and not found:
        digitSum = 0
        for j in str(i):
            digitSum += int(j) 
        if digitSum == x:
           found = True
           print i
        i -= 1
    found = False
zamka()