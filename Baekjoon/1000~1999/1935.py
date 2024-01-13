import sys

input = sys.stdin.readline

n = int(input().rstrip())
nums = [0] * n
string = list(input().rstrip())
stack = []

for i in range(n):
  nums[i] = int(input().rstrip())

for i in range(len(string)):
  if string[i] >= 'A' and string[i] <= 'Z':
    stack.append(nums[ord(string[i]) - ord('A')])
  
  else:
    if string[i] == '+':
      stack.append(stack.pop() + stack.pop())
    elif string[i] == '-':
      stack.append(-stack.pop() + stack.pop())
    elif string[i] == '*':
      stack.append(stack.pop() * stack.pop())
    elif string[i] == '/':
      stack.append((1 /stack.pop()) * stack.pop())

print('{:.2f}'.format(stack[0]))