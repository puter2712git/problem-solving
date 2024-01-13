import sys
input = sys.stdin.readline

star_line = int(input().rstrip())

for i in range(star_line):
  for j in range(star_line * 2):
    if (j + i) % 2 == 0:
      print('*', end='')
    else:
      print(' ', end='')
    
  print()