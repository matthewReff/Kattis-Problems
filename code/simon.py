def simon():
    cases = input()
    for i in range(0, cases):
        myString = raw_input()
        if len(myString) >= 11 and "simon says " == myString[:11]:
            print myString[11:]
        else:
            print "\n"
simon()