nums = input().split(' ')
nums = [float(x) for x in nums]
x00, y00, x01, y01, x10, y10, x11, y11 = nums

y00_01, x01_00 = y00 - y01, x01 - x00
y10_11, x11_10 = y10 - y11, x11 - x10
x01_y00, x00_y01 = x01 * y00, x00 * y01
x11_y10, x10_y11 = x11 * y10, x10 * y11

right1 = x01_y00 - x00_y01
right2 = x11_y10 - x10_y11

try:
    b = (right1 * y10_11 - right2 * y00_01) / (x01_00 * y10_11 - x11_10 * y00_01)
    if y01 > b > y00 or y00 > b > y01:
        print('true')
    else:
        print('false')
except ZeroDivisionError:
    print('false')