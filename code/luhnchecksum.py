cases = input()
for i in range(0, cases):
    arr = []
    check = raw_input()
    for j in check:
        arr.append(int(j))
    for j in range(len(arr)-1, -1, -1):
        if j % 2 == len(arr) % 2:
            if arr[j] * 2 >= 10:
                temp = str(arr[j] * 2)
                total = 0
                for k in temp:
                    total += int(k)
                arr[j] = total
            else:
                arr[j] = 2*arr[j]
    total = 0
    for j in range(0,len(arr)):
        total += arr[j]
    if total % 10 == 0:
        print "PASS"
    else:
        print "FAIL"