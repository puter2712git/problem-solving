import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  size = int(input().rstrip())
  
  for j in range(size):
    print('=', end='')
  print()