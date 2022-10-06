import sys, math
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  score = list(map(int, input().rstrip().split()))
  
  score[0] = 9.23076 * pow((26.7 - score[0]), 1.835)
  score[1] = 1.84523 * pow((score[1] - 75), 1.348)
  score[2] = 56.0211 * pow((score[2] - 1.5), 1.05)
  score[3] = 4.99087 * pow((42.5 - score[3]), 1.81)
  score[4] = 0.188807 * pow((score[4] - 210), 1.41)
  score[5] = 15.9803 * pow((score[5] - 3.8), 1.04)
  score[6] = 0.11193 * pow((254 - score[6]), 1.88)
  
  for i in range(7):
    score[i] = math.floor(score[i])
  
  print(sum(score))