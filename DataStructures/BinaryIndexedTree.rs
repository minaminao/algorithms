// Verified: https://atcoder.jp/contests/chokudai_s001/submissions/7949468
struct BinaryIndexedTree {
    n: usize,
    p: usize,
    v: Vec<isize>,
}

impl BinaryIndexedTree {
    fn new(mut n: usize) -> BinaryIndexedTree {
        let mut p = 1;
        while p < n {
            p = p << 1;
        }
        BinaryIndexedTree {
            n: n,
            p: p,
            v: vec![0; n + 1],
        }
    }

    fn add(&mut self, mut i: usize, x: isize) {
        let mut i = i as isize;
        while i <= self.n as isize {
            self.v[i as usize] = self.v[i as usize] + x;
            i += i & -i;
        }
    }
    fn sum(&mut self, mut i: usize) -> isize {
        let mut ret = 0;
        let mut i = i as isize;
        while i > 0 {
            ret = ret + self.v[i as usize];
            i -= i & -i;
        }
        return ret;
    }
    fn sum2(&mut self, l: usize, r: usize) -> isize {
        return self.sum(r) - self.sum(l - 1);
    }
}