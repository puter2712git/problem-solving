import sys

input = sys.stdin.readline

string = list(input().rstrip())

for i in range(len(string)):
  if string[i] >= 'a' and string[i] <= 'z':
    string[i] = chr(ord(string[i]) + 13)
    
    if ord(string[i]) > ord('z'):
      string[i] = chr(ord(string[i]) - 26)
  
  elif string[i] >= 'A' and string[i] <= 'Z':
    string[i] = chr(ord(string[i]) + 13)
    
    if ord(string[i]) > ord('Z'):
      string[i] = chr(ord(string[i]) - 26)

print(*string, sep='')