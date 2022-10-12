import sys
input = sys.stdin.readline

n = int(input().rstrip())
score1, score2 = 100, 100

for i in range(n):
  a, b = map(int, input().rstrip().split())
  
  if    a > b:
    score2 -= a
  elif  a < b:
    score1 -= b
  
print(score1)
print(score2)