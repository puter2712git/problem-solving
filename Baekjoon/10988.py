import sys, math
input = sys.stdin.readline

word = input().rstrip()
palindrome = True

for i in range(math.floor(len(word) / 2)):
  if word[i] != word[len(word) - i - 1]:
    palindrome = False
    break

if palindrome:
  print(1)
else:
  print(0)