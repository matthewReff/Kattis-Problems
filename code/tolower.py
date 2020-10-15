def tolower():
    numbers = raw_input()
    numbers = numbers.split()
    problems = int(numbers[0])
    cases = int(numbers[1])
    passedNum = 0
    inputString = ""
    passed = True
    for i in range(0,problems):
        passed = True
        for j in range(0,cases):
            inputString = raw_input()
            if len(inputString) > 1:
                    if inputString[1:] != inputString[1:].lower():
                        passed = False
                
        if passed:
            passedNum += 1
            
    print passedNum
tolower()