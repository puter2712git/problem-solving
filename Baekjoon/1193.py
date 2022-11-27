import sys

input = sys.stdin.readline

x = int(input().rstrip())

line_index = 0
end_index = 0

while x > end_index:
  line_index += 1
  end_index += line_index

index = end_index - x

if line_index % 2 == 0:
  top_num = line_index - index
  bottom_num = index + 1
else:
  top_num = index + 1
  bottom_num = line_index - index

print("%d/%d"%(top_num, bottom_num))