import sys

input = sys.stdin.readline

n = int(input().rstrip())
wine = [ [ 0 for _ in range(3) ] for _ in range(n) ]

for i in range(n):
  wine[i][1] = int(input().rstrip())
  wine[i][2] = wine[i][1]

for i in range(1, n):
  if i == 1:
    wine[i][2] += wine[i - 1][1]
    continue
  
  wine[i][2] += wine[i - 1][1]
  wine[i][1] += max(wine[i - 2][2], wine[i - 1][0], wine[i - 2][0])
  wine[i][0] += max(wine[i - 1][2], wine[i - 1][1])

print(max(wine[i]))