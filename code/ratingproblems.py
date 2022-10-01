inputString = input().split()

totalJudges = int(inputString[0])
alreadyRated = int(inputString[1])
missingRatings = totalJudges - alreadyRated

MAX_SCORE = 3
MIN_SCORE = -3
existingRatingTotal = 0

for i in range(alreadyRated):
    rating = int(input())
    existingRatingTotal += rating

minPossibleScore = (existingRatingTotal + missingRatings * MIN_SCORE) / totalJudges
maxPossibleScore = (existingRatingTotal + missingRatings * MAX_SCORE) / totalJudges

print(minPossibleScore, maxPossibleScore)