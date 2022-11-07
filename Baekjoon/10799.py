import sys
input = sys.stdin.readline

form = list(input().rstrip())
stack = []
piece_count = 0

for i in range(len(form)):
  if form[i] == ')':
    if form[i - 1] == '(':
      stack.pop()
      piece_count += len(stack)
    else:
      stack.pop()
      piece_count += 1
  else:
    stack.append(form[i])

print(piece_count)