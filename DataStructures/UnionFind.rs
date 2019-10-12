// Verified: https://atcoder.jp/contests/atc001/submissions/7948320
struct UnionFind {
    parent: Vec<i32>,
    size: usize,
}

impl UnionFind {
    fn new(n: usize) -> UnionFind {
        UnionFind {
            parent: vec![-1; n],
            size: n,
        }
    }

    fn unite(&mut self, mut x: usize, mut y: usize) -> bool {
        x = self.root(x);
        y = self.root(y);
        if x == y {
            return false;
        }
        if self.size_of(x) < self.size_of(y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.parent[x] += self.parent[y];
        self.parent[y] = x as i32;
        self.size -= 1;
        return true;
    }

    fn same(&mut self, x: usize, y: usize) -> bool {
        return self.root(x) == self.root(y);
    }

    fn root(&mut self, x: usize) -> usize {
        return if self.parent[x] < 0 {
            x
        } else {
            let r = self.parent[x] as usize;
            self.parent[x] = self.root(r) as i32;
            self.parent[x] as usize
        };
    }

    #[allow(dead_code)]
    fn size_of(&mut self, x: usize) -> i32 {
        let r = self.root(x);
        return -self.parent[r];
    }
}