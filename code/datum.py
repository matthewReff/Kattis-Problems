def datum():
    month_days=[31,28,31,30,31,30,31,31,30,31,30,31]
    week_days=["Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"]
    total = 0
    rawInput = raw_input()
    rawInput = rawInput.split()
    for i in range(0,len(rawInput)):
        rawInput[i] = int(rawInput[i])
    for i in range(0,rawInput[1]-1):
        total += month_days[i]
    total += rawInput[0]-1
    total += 3
    print week_days[total%7]
datum()