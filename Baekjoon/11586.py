import sys
input = sys.stdin.readline

mirror_size = int(input().rstrip())
image = list(range(mirror_size))

for i in range(mirror_size):
  image[i] = str(input().rstrip())

status = int(input().rstrip())

if status == 2:
  for i in range(mirror_size):
    image[i] = ''.join(reversed(image[i]))
elif status == 3:
  image.reverse()

for image_str in image:
  print(image_str)