import sys
input = sys.stdin.readline

hour, min, sec = map(int, input().rstrip().split())
query_count = int(input().rstrip())

for i in range(query_count):
  query = list(map(int, input().rstrip().split()))
  
  if query[0] == 1 or query[0] == 2:
    h, m, s = query[1] // 3600, (query[1] % 3600) // 60, (query[1] % 3600) % 60
  
  if query[0] == 1:
    hour += h
    min += m
    sec += s
    
    while sec > 59:
      sec -= 60
      min += 1
    while min > 59:
      min -= 60
      hour += 1
    while hour > 23:
      hour -= 24

  elif query[0] == 2:
    hour -= h
    min -= m
    sec -= s
    
    while sec < 0:
      sec += 60
      min -= 1
    while min < 0:
      min += 60
      hour -= 1
    while hour < 0:
      hour += 24
  
  elif query[0] == 3:
    print(hour, min, sec)