# codeforces-template
The template I use for codeforces. 

### Templates

`Debug.h` is the header file that defines the `debug` macro. It is not included in the source file itself to avoid compilation latencies. It is based on Tourist's debugging template, with a lot of tweaking.

`Template.cpp` is the main file for writing up your solution. Write your solution inside the `solve()` method. If the problem involves multiple test cases, uncomment the already commented out lines at the bottom of the file.

`cp.in` is the file for storing the input for the problem.

`cp.out` is the file for storing the output generated by your solution.

`cp.sh` is a bash script used to compile and execute the main driver code. Refer to the script for usage instructions.

`copy.sh` is a bash script used to copy everything within a `.cpp` file.


### Setup
> [!TIP]
> you can create a directory to store these templates and define a script (e.g., a `.zsh` script) to copy the contents of this directory to your current working directory. For example, you could use a command like `template codeforces-template`, which would copy all files from the template directory to your current directory.

The following images depicts my current setup.


