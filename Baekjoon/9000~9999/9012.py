import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  stack = []
  checked = False

  str = input().rstrip()

  for j in range(len(str)):
    if str[j] == ')':
      if len(stack) == 0:
        print('NO')
        checked = True
        break
      if stack[len(stack) - 1] == '(':
        del stack[len(stack) - 1]
      else:
        print('NO')
        checked = True
        break
    else:
      stack.append('(')
  
  if not checked:
    if len(stack) != 0:
      print('NO')
    else:
      print('YES')