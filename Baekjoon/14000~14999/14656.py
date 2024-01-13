import sys
input = sys.stdin.readline

student_num = int(input().rstrip())
student_list = list(map(int, input().rstrip().split()))
count = 0

for i in range(student_num):
  if student_list[i] != i + 1:
    count += 1
    
print(count)