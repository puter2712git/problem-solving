import sys
input = sys.stdin.readline

string = list(input().rstrip())
i = 0

while i < len(string):
  if string[i] == '<':
    while string[i] != '>':
      i += 1
    i += 1
  
  elif string[i].isalnum():
    start = i
    while i < len(string) and string[i].isalnum():
      i += 1
    
    temp = string[start:i]
    string[start:i] = reversed(temp)
  
  else:
    i += 1

print(''.join(string))