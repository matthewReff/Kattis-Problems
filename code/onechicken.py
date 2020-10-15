def chicken():
    numbers = raw_input()
    numbers = numbers.split()
    people = int(numbers[0])
    chickens = int(numbers[1])
    constructStrting = ""
    if chickens > people:
        constructStrting += ("Dr. Chaz will have " + str(chickens - people) +  " piece")
        if chickens - people != 1:
           constructStrting += "s"
        constructStrting += " of chicken left over!"
    else:
        constructStrting += ("Dr. Chaz needs " + str(people - chickens) +  " more piece")
        if people - chickens != 1:
           constructStrting += "s"
        constructStrting += " of chicken!"
    print constructStrting
chicken()