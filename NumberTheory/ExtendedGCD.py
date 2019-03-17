def extgcd(a, b):
    g = a
    x = 1
    y = 0
    if b != 0:
        g, y, x = extgcd(b, a % b)
        y -= (a // b) * x
    return (g, x, y)
