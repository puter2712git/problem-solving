import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  yonsei, korea = 0, 0
  for j in range(9):
    y, k = map(int, input().rstrip().split())
    
    yonsei  += y
    korea   += k

  if    yonsei > korea:
    print('Yonsei')
  elif  yonsei < korea:
    print('Korea')
  else:
    print('Draw')