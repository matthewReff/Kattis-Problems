def fox():
    cases = input()
    for i in range(0, cases):
        soundList = []
        animalSounds = []
        outString = ""
        totalSounds = raw_input()
        noise = ""
        noise = raw_input()
        while (noise != "what does the fox say?"):
            animalSounds = noise.split(" goes ")
            soundList.append(animalSounds[1])
            noise = raw_input()
        totalSounds = totalSounds.split()
        for i in totalSounds:
            if i not in soundList:
                outString+= i + " "
        print outString  
fox()