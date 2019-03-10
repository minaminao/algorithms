def extgcd(a, b):
    g = a
    x = 1
    y = 0
    if b != 0:
        g, y, x = extgcd(b, a % b)
        y -= (a // b) * x
    return (g, x, y)


def modinv(x, m):
    g, y, n = extgcd(x, m)
    return (y + m) % m