from itertools import combinations_with_replacement as comb, permutations as perm
from math import log


def print357nums(lim):
    max_pow = int(log(lim, 3))
    for nums in comb([x for x in range(max_pow + 1)], 3):
        for pows in set(perm(nums)):
            p = pow(3, pows[0]) * pow(5, pows[1]) * pow(7, pows[2])
            if p <= lim:
                print(p)


if __name__ == '__main__':
    x = int(input())
    print357nums(x)