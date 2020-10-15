def planina():
    edges = 2 
    iterations = raw_input()
    iterations = int(iterations)
    for i in range(0,iterations):
        edges += edges - 1
    print edges ** 2
planina()