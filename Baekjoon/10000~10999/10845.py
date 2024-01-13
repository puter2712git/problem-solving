import sys
input = sys.stdin.readline

command_count = int(input().rstrip())
queue = [ None ] * command_count
queue_front = -1
queue_back = -1

for i in range(command_count):
  command = input().rstrip().split()
  
  if command[0] == 'push':
    queue_back += 1
    queue[queue_back] = command[1]
  
  elif command[0] == 'pop':
    if queue_front == queue_back:
      print(-1)
    else:
      queue_front += 1
      print(queue[queue_front])
  
  elif command[0] == 'size':
    print(queue_back - queue_front)
  
  elif command[0] == 'empty':
    if queue_front == queue_back:
      print(1)
    else:
      print(0)
  
  elif command[0] == 'front':
    if queue_front == queue_back:
      print(-1)
    else:
      print(queue[queue_front + 1])
  
  elif command[0] == 'back':
    if queue_front == queue_back:
      print(-1)
    else:
      print(queue[queue_back])