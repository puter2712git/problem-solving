import sys
input = sys.stdin.readline

while True:
  a, b, c, d = map(int, input().rstrip().split())
  
  if (a == 0 and b == 0 and c == 0 and d == 0):
    break
  
  min_age = c - b
  max_age = d - a
  
  print(min_age, max_age)