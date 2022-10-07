import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  length = list(map(int, input().rstrip().split()))
  length.sort()
  
  print('Case #{0}: '.format(str(i + 1)), end='')
  
  if (length[0] == length[1] and length[0] == length[2]):
    print('equilateral')
  elif (length[0] + length[1] <= length[2]):
    print('invalid!')
  elif (length[0] == length[1] or length[1] == length[2]):
    print('isosceles')
  else:
    print('scalene')