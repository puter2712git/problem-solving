import sys
input = sys.stdin.readline

dec = int(input().rstrip())
new_num = []
new_num.clear()

while dec > 0:
  new_num.insert(0, dec % 9)
  dec //= 9
new_num = ''.join(map(str, new_num))

print(str(new_num))