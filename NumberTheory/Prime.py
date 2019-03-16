import random


def gen_prime(n):
    x = random.randint(pow(2, n), pow(2, n + 1))
    if x % 2 == 0:
        x += 1
    while miller_rabin_primality_test(x, 10) == False:
        x += 2
    return x


def miller_rabin_primality_test(x, iteration):
    if x < 2:
        return False
    if x != 2 and x % 2 == 0:
        return False
    s = x - 1
    while s % 2 == 0:
        s //= 2
    for i in range(iteration):
        a = random.randint(1, x - 1)
        tmp = s
        mod = pow(a, tmp, x)
        while tmp != x - 1 and mod != 1 and mod != x - 1:
            mod = (mod * mod) % x
            tmp *= 2
        if mod != x - 1 and tmp % 2 == 0:
            return False
    return True
