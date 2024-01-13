import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  r, e, c = map(int, input().rstrip().split())
  
  if r < e - c:
    print('advertise')
  elif r == e - c:
    print('does not matter')
  else:
    print('do not advertise')