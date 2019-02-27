from tqdm import tqdm, trange
a=range(int(1e8))

"""
Create an array `b` which is the `str` equivalent of `int` array `a`,
using `tqdm` for progress.
"""
#method 2
b = [str(n) for n in tqdm(a)]

#method 3
b = map(str, tqdm(a))
