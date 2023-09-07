# Introduction to Makefiles

A Makefile is a file that helps you automate your development workflow.  It is
consumed by a simple yet powerful program called `make`.  Note that for all
examples, the file must be called `Makefile` or `make` will not detect it.

## A Simple Example

This is a very simple makefile.

```Makefile
greet:
	echo "hello"
```

There is one `target` named `greet` and one command associated with that
target, `echo "hello"`.  If you run `make greet` the command will be run.

Note one common mistake with creating makefiles: every command must be
started with a `tab`, not spaces.  If you were to uses spaces instead, you
would get the confusing error `Makefile:2: *** missing separator.  Stop.`  

## Dependencies

You probably would not need a makefile if you only needed to run one command.
The general case is that there are many steps to getting a project ready, and
some of them depend on others.  This example shows a simple case of using
a dependency in a Makefile.

```Makefile
greet:
	echo "hello"

farewell: greet
	echo "goodbye"
```

Clearly, if you are to give someone a farewell, you must greet them first.

If you run `make farewell` you will see that `greet` is first run, and then
`farewell`  This is because `farewell: greet` says that `farewell` is dependent
on `greet`.

Note also, if you only run `make`, only the target `greet` will be run.  This
is because the top target is run by default.

## Files

The most common case for a Makefile is generating files from code which are not
otherwise stored because they are too large, not compatible with version control (such as github), or
dependent on the user's machine.  This example will avoid that for
simplicity.  Instead, we will use a regular bash script which depends on a
file.

`make_greet.sh`:
```bash
echo 'echo '$(cat greet_word.txt)', $1' > greet.sh
```

`greet_word.txt`:
```bash
Hello
```

`Makefile`:
```Makefile
build: greet.sh

greet.sh: greet_word.txt
	./make_greet.sh
	chmod +x greet.sh

clean:
	rm greet.sh
```

Now we have file dependencies.  This `Makefile` says that the file we are
making, `greet.sh` depends on `greet_word.txt`.

Try running `make build`, you should see that `greet.sh` has been generated.
Now if you run `make build` again, you should see the message
`make: Nothing to be done for 'build'.`.  `make` is saying that since the
dependency `greet_word.txt` has not been updated since `greet.sh` was created,
there is not need to make it again.
