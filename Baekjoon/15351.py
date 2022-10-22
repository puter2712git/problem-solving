import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  sentence = str(input().rstrip())
  score = 0
  
  for char in sentence:
    if (char >= 'A' and char <= 'Z'):
      score += ord(char) - ord('A') + 1
  
  if score == 100:
    print('PERFECT LIFE')
  else:
    print(score)