import sys
input = sys.stdin.readline

a1, d, ak = map(int, input().rstrip().split())

if (ak - a1) % d != 0 or (ak - a1) / d < 0:
  print('X')
else:
  print((ak - a1) // d + 1)