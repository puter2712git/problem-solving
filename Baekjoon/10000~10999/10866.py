from collections import deque
import sys
input = sys.stdin.readline

deq = deque()

for _ in range(int(input().rstrip())):
  command = input().rstrip().split()
  
  if command[0] == 'push_front':
    deq.appendleft(int(command[1]))
    
  elif command[0] == 'push_back':
    deq.append(int(command[1]))
  
  elif command[0] == 'pop_front':
    if not deq:
      print(-1)
    else:
      print(deq.popleft())
  
  elif command[0] == 'pop_back':
    if not deq:
      print(-1)
    else:
      print(deq.pop())
  
  elif command[0] == 'size':
    print(len(deq))
  
  elif command[0] == 'empty':
    if deq:
      print(0)
    else:
      print(1)
  
  elif command[0] == 'front':
    if not deq:
      print(-1)
    else:
      print(deq[0])
  
  elif command[0] == 'back':
    if not deq:
      print(-1)
    else:
      print(deq[len(deq) - 1])