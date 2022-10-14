import sys
input = sys.stdin.readline

while True:
  a, b = map(int, input().rstrip().split())
  if a == 0 and b == 0:
    break
  
  print('{} {} / {}'.format(str(a // b), str(a % b), str(b)))