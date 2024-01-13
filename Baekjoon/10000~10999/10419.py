import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  time = int(input().rstrip())
  late_time = 0
  
  while True:
    if time - late_time < (late_time * late_time):
      late_time -= 1
      break
    late_time += 1
  
  print(late_time)