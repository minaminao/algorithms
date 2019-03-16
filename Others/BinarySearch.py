def binary_search(l, r, f):
    """
    f(l) f(l+1) ... f(t-1) f(t) f(t+1) ... f(r) が
    false false ... false true true ... true
    のように、f(x) が true となるような最小値 t を返す
    """
    if f(l):
        return l
    while l+1 < r:
        m = (l+r)//2
        if f(m):
            r = m
        else:
            l = m
    return r
