# TODO

from cs50 import get_int

height = 9
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

for i in range(height):
    print(" " * (height - 1 - i), end="")
    print("#" * (i + 1), end="")
    print(" " * 2, end="")
    print("#" * (i + 1))