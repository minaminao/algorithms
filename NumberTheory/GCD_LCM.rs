fn gcd(x: u32, y: u32) -> u32 {
    if y > 0 { gcd(y, x % y) } else { x }
}
