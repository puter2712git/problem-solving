import sys
input = sys.stdin.readline

width, height = map(int, input().rstrip().split())

if width * height % 3 == 0:
  print('YES')
else:
  print('NO')