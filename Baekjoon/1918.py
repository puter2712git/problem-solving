import sys

input = sys.stdin.readline

notation = list(input().rstrip())
stack = []
op_prio = {'+': 0, '-': 0,
           '*': 1, '/': 1}
i = 0

while i < len(notation):
  if notation[i].isalpha():
    print(notation[i], end='')
    
  elif notation[i] == '(':
    stack.append(notation[i])
    
  elif notation[i] == ')':
    while stack[-1] != '(':
      print(stack.pop(), end='')
    stack.pop()

  else:
    while stack and stack[-1] != '(' and op_prio[stack[-1]] >= op_prio[notation[i]]:
      print(stack.pop(), end='')
    stack.append(notation[i])
  
  i += 1

while stack:
  print(stack.pop(), end='')