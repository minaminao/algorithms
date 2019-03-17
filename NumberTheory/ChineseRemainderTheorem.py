from ExtendedGCD import *


def compute_crt(a, n):
    assert len(a) == len(n)
    A = 0
    N = 1  # lcm(n_1,n_2,...)
    for i in range(len(a)):
        g, u, v = extgcd(N, n[i])
        if a[i] % g != A % g:
            return (-1, -1)
        m = n[i]//g
        t = (a[i]-A)//g*u % m
        A += N*t
        N *= m
    return (A % N), N


if __name__ == "__main__":
    print(compute_crt([2, 3, 2], [3, 5, 7]))
