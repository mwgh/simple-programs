import math

def hypotenuse(a,b):
    return math.sqrt(a*a + b*b)

def rightTrianglePerimeter(a, b):
    return hypotenuse(a, b) + a + b

def distance2D(x1, y1, x2, y2):
    return hypotenuse(x1-x2, y1-y2)

def trianglePerimeter(xA, yA, xB, yB, xC, yC):
    return distance2D(xA, yA, xB, yB) + distance2D(xB, yB, xC, yC) + distance2D(xA, yA, xC, yC)
