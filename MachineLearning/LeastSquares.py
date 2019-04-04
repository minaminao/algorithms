import numpy as np


def least_squares(x, y):
    """
    最小二乗法 1次
    Verified: https://yukicoder.me/submissions/335377
    """
    n = len(x)
    var_x = np.var(x)
    mu_x = np.mean(x)
    mu_y = np.mean(y)
    cov = sum((x-mu_x)*(y-mu_y)) / n
    a = cov / var_x
    b = mu_y - a*mu_x
    cost = sum((_y - a*_x - b) ** 2 for _x, _y in zip(x, y))
    return a, b, cost


if __name__ == "__main__":
    x = [0, 1, 2]
    y = [1, 4, 3]
    print(least_squares(x, y))
    print(np.polyfit(x, y, 1))
