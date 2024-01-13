import sys
input = sys.stdin.readline

testcase = int(input().rstrip())
for i in range(testcase):
  vertex, edge = map(int, input().rstrip().split())
  
  face = 2 - (vertex - edge)
  print(face)