def number_to_words(n: int):
    """
    数値を言葉に変換
    Verified: https://projecteuler.net/problem=17
    """
    if n == 0:
        return "zero"
    W0 = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
          "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    W1 = ["", "", "twenty", "thirty", "forty", "fifty",
          "sixty", "seventy", "eighty", "ninety"]
    W2 = ["", "thousand", "million", "billion", "trillion"]
    words = []
    i = 1
    while n:
        x = n % 100
        if 1 <= x <= 19:
            words.append(W0[x])
        else:
            if x % 10:
                words.append(W0[x % 10])
            words.append(W1[x//10])
        y = (n//100) % 10
        if y:
            if x:
                words.append("and")
            words.append("hundred")
            words.append(W0[y])
        n //= 1000
        z = n % 10
        if z:
            words.append(W2[i])
        i += 1
    return " ".join(reversed(words))


if __name__ == "__main__":
    ans = 0
    for i in range(1, 1001):
        ans += len(number_to_words(i).replace(" ", ""))
    print(ans)
