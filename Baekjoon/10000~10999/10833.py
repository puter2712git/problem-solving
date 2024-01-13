import sys
input = sys.stdin.readline

school = int(input().rstrip())
remain_apple = 0

for i in range(school):
  student, apple = map(int, input().rstrip().split())
  remain_apple += apple % student
  
print(remain_apple)