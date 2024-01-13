import sys
input = sys.stdin.readline

word = str(input().rstrip())

while len(word) > 10:
  print(word[0:10])
  word = word[10:]
print(word)