#Simple Shell Project
#Overview
##Write a simmple UNIX Command Interpreter
#Aim
##A UNIX Command Line Interpreter Built in C

1. Who designed and implemented the original Unix operating Sytem?
Ken Thompson and Dennis Ritchie created the first version of UNIX as a team in 1969
2. Who wrote the first version of the UNIX shell?
Thompson shell
3. Who invented the B Programming language ?
It was developed at Bell Labs circa 1969 by Ken Thompson and Dennis Ritchie
4. Who is Ken Thompson?
He designed and implemented the original UNIX operarting system.
5. How does shell work?
Shell corresponds in the computer world to command interpreter where the user has an available interface (CLI, Command-Line Interface) through which the possibility of accessing services of the operating system as well as executing or invoking programs
6. What is a pid and a ppid?
PID(Parent Process ID) which means identification number for currently running process and PPID(Parent Process ID) which means Parent process is responsible for creating the current process(Child Process). Through parent process the Child Process will be created.
7. How to manipulate the enviroment of the current process?
You can only influence a process's enviroment variable at the time the process starts up. If you need to communicate a change to a running process, the enviroment isn't the right tool to perform it
8. What is the difference between a function and a system call?
A function call is a request made by a program to perform a specific task while a system call is a request for the kernel to access a resource
9. How to create processes?
I UNIX and POSIX you call fork() and then the exec() to create a process. When you fork it, it clones a copy of your currentprocess, including all data, environment variables and open file. The Child Process is a duplicate of the parent
10. What are three prototypes of main?
They are int main(); int main(int argc, char **argv);
11. How does shell use PATH to find programs?
The shell tries each directory in the PATH and runs the executable program with the matching command name that it finds
12. How to execute another program with the execve system call?
execve() executes the program pointed by the filename . The filename must either be a binary executable or script starting with a line of the form "#! interpreter [arg]" execve does not return on success and the text, data, bss and stack of the calling process are overwritten by that of the program loaded.
13. How to suspend the execution of a process until one of its children terminates?
The wait() system call suspends execution of the current process until one of its children terminates
14. What is EOF/ "end-of-file"?
This operator stands for the end of the file. This means that whenever a compiler or an interpreter encounters its operator, it will recieve an indication that the file it was reading has ended

