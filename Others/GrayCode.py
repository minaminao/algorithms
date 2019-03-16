def bin_to_gray(n):
    return n ^ (n >> 1)


def gray_to_bin(g):
    mask = g >> 1
    while mask:
        g ^= mask
        mask >>= 1
    return g


n = 10
for i in range(n):
    g = bin_to_gray(i)
    j = gray_to_bin(g)
    assert i == j
    print(i, g, bin(g))
