import collections
import string
import random

rs = ''.join(random.choices(string.ascii_lowercase, k=1000))
# Create a count of each unique element
count = collections.Counter(rs)
print(count.most_common())
# You can access it like a dictionary
print(count['z'])

dd = collections.defaultdict(list)
dd['new_key'].append(1)
dd['new_key'].append(2)
dd['new_key_2'].append(0)
print(dict(dd))
