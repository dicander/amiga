import sys

for line in sys.stdin.readlines():
    for x in line.split():
        print('"{:s}", '.format(x), end="")
