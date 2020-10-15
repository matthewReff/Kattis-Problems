def character():
    factorials = [1]
    for i in range(1, 31):
        factorials.append(i * factorials[i-1])
    n = input()
    total = 0
    for k in range(n, 1, -1):
        total += (factorials[n] / (factorials[k] * factorials[n - k]))
    print total
character()