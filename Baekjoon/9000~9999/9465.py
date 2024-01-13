import sys

input = sys.stdin.readline

t = int(input().rstrip())

for _ in range(t):
  n = int(input().rstrip())
  
  stickers = [ [ 0 for _ in range(n) ] for _ in range(2) ]
  
  for i in range(2):
    stickers[i] = list(map(int, input().rstrip().split()))
  
  for i in range(1, n):
    if i == 1:
      stickers[0][i] += stickers[1][i - 1]
      stickers[1][i] += stickers[0][i - 1]
      continue
    
    stickers[0][i] += max(stickers[1][i - 1], stickers[1][i - 2])
    stickers[1][i] += max(stickers[0][i - 1], stickers[0][i - 2])

  print(max(stickers[0][n - 1], stickers[1][n - 1]))