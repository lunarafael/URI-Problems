import math

x1, y1 = (input()).split(" ")
x2, y2 = (input()).split(" ")
w = (float(x2) - float(x1))**2
z = (float(y2) - float(y1))**2
print(f"{math.sqrt(w+z):.4f}")