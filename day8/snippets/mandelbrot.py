def in_mandelbrot_set(c):
    x = 0
    for n in range(100):
        x = x*x + c
        if abs(x) > 2:
            return False

    return True

def visualize():
    dx = 0.03125;
    dy = 0.0625;
    for n in range(-16, 16+1):
        for m in range(-64, 16+1):
            if in_mandelbrot_set(m*dx + 1j*n*dy):
                print('*', end='')
            else:
                print(' ', end='')
        print();

visualize()
