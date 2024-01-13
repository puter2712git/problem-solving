import sys
input = sys.stdin.readline

left_str = list(input().rstrip())
right_str = []

for i in range(int(input())):
  command = list(input().split())
  
  if command[0] == 'L':
    if left_str:
      right_str.append(left_str.pop())
    
  elif command[0] == 'D':
    if right_str:
      left_str.append(right_str.pop())
  
  elif command[0] == 'B':
    if left_str:
      left_str.pop()

  else:
    left_str.append(command[1])

left_str.extend(reversed(right_str))
print(''.join(left_str))