# Assignment-0-The-Unix-Programming-Environment

Create an executable bash script `solution.sh` that does the following:

1. Create a directory called `mydir`
2. Navigate into that directory
3. Create a directory called `mydir2`
4. Navigate into that directory
5. Create an empty file called `myfile`
6. Put the text `hello bash` into `myfile`
7. Print the contents of `myfile`
8. Navigate up one directory so you're in `mydir`
9. Copy `mydir2` and all of its contents to a directory called `mydir3`
10. List everything in the current directory
11. List all directories in the current directory and the ones below it recursively (using ls -R or find + sort)

Each instruction should be completed by exactly one line.

Your output should look something like the following:

```
hello bash
mydir2  mydir3
.:
mydir2  mydir3

./mydir2:
myfile

./mydir3:
myfile
```
