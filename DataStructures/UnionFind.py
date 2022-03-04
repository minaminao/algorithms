class UnionFind:
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)]
        self.size = n

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.size_of(x) < self.size_of(y):
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x
        self.size -= 1
        return True

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def root(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]

    def size_of(self, x):
        return -self.parent[self.root(x)]