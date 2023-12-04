import pprint

a = [[0]*5, [0]*5, [0]*5, [0]*5, [0]*5]
for m in range(5):
    for n in range(5):
        a[m][n] = (m, n)

pprint.pprint(a)
