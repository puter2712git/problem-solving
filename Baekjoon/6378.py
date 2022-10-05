import sys
input = sys.stdin.readline

while True:
  n = input().rstrip()
  if (n == '0'):
    break
  
  temp = 10
  while (temp > 9):
    temp = 0
    for i in range(len(n)):
      temp += int(n[i])
    
    n = str(temp)
  
  print(temp)