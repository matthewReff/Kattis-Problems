def potato():
    numbers = 0
    estimate = 0
    
    numbers = int(input())
    
    for i in range(0,numbers):
        digits = 0
        estimate = int(input())
        for j in str(estimate):
            digits += 1
        print digits
potato()