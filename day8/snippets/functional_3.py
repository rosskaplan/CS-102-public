import time

def timed(f):
    def wrapper(*args, **kwargs):
        t1 = time.time()
        retval = f(*args, **kwargs)
        t2 = time.time()
        print(f'Calling "{f.__name__}" took {t2-t1} seconds')
        return retval
    return wrapper

@timed
def wait(seconds):
    print('waiting')
    time.sleep(seconds)
    print('done waiting!')

timed_wait(0.1)
timed_wait(0.2)
timed_wait(0.3)
