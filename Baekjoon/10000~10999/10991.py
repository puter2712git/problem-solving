import sys
input = sys.stdin.readline

star_line = int(input().rstrip())

for i in range(star_line):
  for j in range(star_line - i - 1):
    print(' ', end='')
  
  for j in range(2 * (i + 1) - 1):
    if j % 2 == 0:
      print('*', end='')
    else:
      print(' ', end='')
  
  print()