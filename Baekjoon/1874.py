import sys
input = sys.stdin.readline

n = int(input().rstrip())
curr = 1
int_stack = []
answer = []
is_possible = True

for i in range(n):
  element = int(input().rstrip())
  
  while curr <= element:
    int_stack.append(curr)
    curr += 1
    answer.append('+')
  
  if int_stack[-1] == element:
    int_stack.pop()
    answer.append('-')
  else:
    print('NO')
    is_possible = False
    break

if is_possible:
  for i in answer:
    print(i)