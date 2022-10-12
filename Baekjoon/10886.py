import sys
input = sys.stdin.readline

n = int(input().rstrip())
votes = {
  '0': 0,
  '1': 0
}

for i in range(n):
  votes[input().rstrip()] += 1
  
if votes['0'] > votes['1']:
  print('Junhee is not cute!')
else:
  print('Junhee is cute!')