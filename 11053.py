#Solution to UVa 11053: Flavius Josephus Reloaded
def cycleLength(N, a , b):
    tortoise = b
    hare = (a * b * b + b) % N
    while (tortoise != hare):
        tortoise = (a * tortoise * tortoise + b) % N
        hare = (a * hare * hare + b) % N
        hare = (a * hare * hare + b) % N

    hare = 0
    u = 0 
    while (tortoise != hare):
        hare = (a * hare * hare + b) % N
        tortoise = (a * tortoise * tortoise + b) % N
        u += 1

    tortoise = (a * hare * hare + b) % N
    repeat = u + 1

    while (tortoise != hare):
        tortoise = (a * tortoise * tortoise + b) % N;
        repeat += 1

    return N - repeat + u

while (1):
    put = input()
    put = put.split()
    N = int(put[0])
    if (N == 0):
         break
    a = int(put[1])
    b = int(put[2])
    print(cycleLength(N , a , b))
    