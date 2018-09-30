def simonsays():
    cases = input()
    instruction = ""
    for i in range(0, cases):
        instruction = raw_input()
        if len(instruction) > len("Simon says"):
            if instruction[ : len("Simon says")] == "Simon says":
                print instruction[ len("Simon says") + 1:]
simonsays()