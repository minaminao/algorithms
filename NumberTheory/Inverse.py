from ExtendedGCD import *


def modinv(x, m):
    g, y, n = extgcd(x, m)
    return (y + m) % m
