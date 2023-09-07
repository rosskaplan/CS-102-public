# Makefiles part 2

We just spoke about the anatomy of the most basic C program.  We'll build on that
as time goes on.  Let's quickly review why the learning Makefiles was so useful,
and how we'll be using them throughout this class.

## Compiled files

As mentioned before, the most common case for a Makefile is generating files from 
code which are not otherwise stored because they are too large, not compatible with GitHub, 
or dependent on the user's machine.  

Let's review the following example with 4 build targets.  

```Makefile
build: hello.out

hello.out: hello.c
	gcc hello.c -o hello.out

clean:
	rm hello.out

test: hello.out
	./hello.out
```

Now you can run a simple command, `make build test` on a clean directory to build and run your code
in 1 line.  It will consecutively run `make build`, followed by `make test`.  Hopefully seeing this
relatively complete example brings Make's utility full circle and shows why it's so common and useful.
