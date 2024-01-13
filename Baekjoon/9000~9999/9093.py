import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  words = input().rstrip().split()

  for j in range(len(words)):
    for k in range(len(words[j])):
      print(words[j][len(words[j]) - k - 1], end='')
    print(' ', end='')
  print()