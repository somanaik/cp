import itertools
import random
import numpy
from random import randint

def get_perm(n):
    return numpy.random.permutation([i for i in range(1, n+1)])

def get_perm_arr(arr):
    return numpy.random.permutation(arr)

def gcd(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return gcd(b, a%b)

def shuffle(l):
    l = sorted(l)
    random.shuffle(l)
    return l


def lcm_of_cons():
    v = [randint(10, 100) for i in range(30)]
    l = [randint(6, 15) for j in range(30)]
    for i in range(len(v)):
        a, b = v[i], l[i]
        arr = [a]
        g = a
        for j in range(a+1, a+b):
            d = gcd(g, j)
            g = (g * j) // d
            ok = True
            for jj in range(a, j+1):
                if g % jj != 0:
                    ok = False
            assert(ok)
            arr.append(g)

        print(a, b, '--> ', ' '.join([str(c) for c in arr]))

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]

t = randint(1, 10)
print(t)
for i in range(t):
    n = randint(1, 6)
    s = ""
    for j in range(n):
        s = s + chr(randint(0, 4)+ord('a'))
    s = s + s
    s = ''.join(shuffle(s))
    print(len(s))
    print(s)