import sys
input = sys.stdin.readline

def push(element):
  global stack_top
  stack[stack_top] = int(element)
  stack_top += 1
  
def pop():
  global stack_top
  if empty():
    return -1
  else:
    stack_top -= 1
    return stack[stack_top]

def size():
  global stack_top
  return stack_top

def empty():
  global stack_top
  if stack_top == 0:
    return 1
  else:
    return 0

def top():
  global stack_top
  if empty():
    return -1
  else:
    return stack[stack_top - 1]

command_count = int(input().rstrip())
stack = [ None ] * command_count
stack_top = 0

for i in range(command_count):
  command = input().rstrip().split()
  
  if command[0] == 'push':
    push(command[1])

  if command[0] == 'pop':
    print(pop())
  
  if command[0] == 'size':
    print(size())
  
  if command[0] == 'empty':
    print(empty())
  
  if command[0] == 'top':
    print(top())