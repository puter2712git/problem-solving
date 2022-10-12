import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  result = input().rstrip()
  score = 0
  correct = 0
  
  for j in range(len(result)):
    if result[j] == 'O':
      correct += 1
      score += correct
    else:
      correct = 0

  print(score)
      