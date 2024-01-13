import sys

input = sys.stdin.readline

n = int(input().rstrip())

triangle = [ [ 0 for _ in range(n) ] for _ in range(n) ]

for i in range(n):
  triangle[i] = list(map(int, input().rstrip().split()))
  
  if i == 0:
    continue
  
  for j in range(i + 1):
    if j == 0:
      triangle[i][j] += triangle[i - 1][j]
      continue
    if j == i:
      triangle[i][j] += triangle[i - 1][j - 1]
      continue
    
    triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j])
  
print(max(triangle[n - 1]))