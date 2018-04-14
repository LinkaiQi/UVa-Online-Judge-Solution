import random

N = 100
print(N)

for _ in range(N):
    out = []
    for _ in range(8):
        out.append(str(random.randint(-10,10)))
    print(' '.join(out))
