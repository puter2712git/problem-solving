import sys
input = sys.stdin.readline

score = list(range(5))

for i in range(5):
  score[i] = int(input().strip())
  if (score[i] < 40):
    score[i] = 40

print(sum(score) // 5)