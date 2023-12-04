import pprint
import itertools

pprint.pprint(list(itertools.product([0, 1, 2], [0, 1, 2])))
pprint.pprint(list(itertools.product([0, 1, 2], repeat=3)))
pprint.pprint(list(itertools.product(['a', 'b', 'c'], [1, 2, 3])))

pprint.pprint(list(itertools.permutations('aabc')))
pprint.pprint(list(itertools.combinations('aabc', 3)))
