import sys
input = sys.stdin.readline

n = int(input().rstrip())

for i in range(n):
  for j in range(n):
    print('*', end='')
  print()