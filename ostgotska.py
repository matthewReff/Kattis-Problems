def ostgotska():
    rawString = raw_input()
    sentence = rawString.split()
    wordCount = 0
    isDia = False
    for word in sentence:
        isDia = False
        if len(word) > 1:
            for j in range(0, len(word)-1):
                if word[j:j+2] == "ae":
                    isDia = True
        if isDia:
            wordCount += 1
    if wordCount / float(len(sentence)) >= .4:
        print "dae ae ju traeligt va"
    else:
        print "haer talar vi rikssvenska"
                    
ostgotska()