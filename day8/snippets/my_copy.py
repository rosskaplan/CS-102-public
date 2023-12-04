import copy

def append_one_in_place(lst):
    lst.append(1)
    return lst

def append_one_to_copy(lst):
    lst = copy.copy(lst)
    lst.append(1)
    return lst

def append_one_to_first_elem(lst):
    lst[0].append(1)
    return lst

a = [3, 2]
b = append_one_in_place(a)
print(a)
print(b)

a = [3, 2]
b = append_one_to_copy(a)
print(a)
print(b)

a = [[0]]
b = append_one_to_first_elem(a)
print(a)
print(b)
