import sys
input = sys.stdin.readline

v = int(input().rstrip())
votes = input().rstrip()
a, b = 0, 0

for i in range(v):
  if    votes[i] == 'A':
    a += 1
  elif  votes[i] == 'B':
    b += 1

if    a > b:
  print('A')
elif  a < b:
  print('B')
else:
  print('Tie')