#Matthew Reff
#Room 313

def inceptionPassword():
    inputStorage=[]
    rawInput=''
    rawInput=raw_input()
    rawInput=rawInput.split()
    
    for i in rawInput:
        inputStorage.append(i)
        
    passwordString=inputStorage[1]
    password=inputStorage[0]
    
    for i in passwordString:
        if i==password[0]: #shorten the password for future cases
            password=password[1:]
            if len(password)==0: #if the password is gone entirely, the password is
                print "PASS"     #valid, and the case is succesful
                return 0
        elif i in password[1:]: #if the letter is in the password and not
            print "FAIL"        #the next letter in the password, case has failed
            return 1
    print "FAIL" #if the end of password string is reached, display that case has failed
inceptionPassword()
