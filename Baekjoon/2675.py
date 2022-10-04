import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  repeat, string = input().rstrip().split()
  repeat = int(repeat)
  
  for j in range(len(string)):
    for k in range(repeat):
      print(string[j], end='')
  
  print()