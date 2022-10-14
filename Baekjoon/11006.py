import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  leg_count, chicken_count = map(int, input().rstrip().split())
  
  chicken_cutted = 2 * chicken_count - leg_count
  chicken_fine = chicken_count - chicken_cutted
  
  print(chicken_cutted, chicken_fine)