import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  n, m = map(int, input().rstrip().split())
  count = 0
  
  for b in range(2, n):
    for a in range(1, b):
      if ((a * a + b * b + m) % (a * b) == 0):
        count += 1
  
  print(count)