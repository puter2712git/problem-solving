import sys
input = sys.stdin.readline

semester = int(input().rstrip())

for i in range(semester):
  grade = int(input().rstrip())
  semester_info = { 'credit': 0, 'rate': 0 }
  for j in range(grade):
    credit, rate = map(float, input().rstrip().split())
    
    semester_info['credit'] += credit
    semester_info['rate'] += credit * rate
  
  print(int(semester_info['credit']), round(semester_info['rate'] / semester_info['credit'], 1))