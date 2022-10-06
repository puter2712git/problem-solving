import sys
input = sys.stdin.readline

n = int(input().rstrip())
min_x, min_y = -1, -1
max_x, max_y = -1, -1

for i in range(n):
  x, y = map(int, input().rstrip().split())
  
  if (min_x == -1 and min_y == -1):
    min_x, min_y = x, y
  if (max_x == -1 and max_y == -1):
    max_x, max_y = x, y
  
  min_x = min(min_x, x)
  min_y = min(min_y, y)
  max_x = max(max_x, x)
  max_y = max(max_y, y)
  
print((max_x - min_x) * (max_y - min_y))
