<h1 align = "center"> Shell project </h1>

<h2>Description.</h2>

<p>The Shell is in charge of executing the basic commands for system management, it is a fundamental part of an operating system, having features such as process control, input/output redirection and a command language for writing programs.<br>

The shell does three main things:<br>

⦁ <b>Initialize:</b> it will read and execute your configuration files.<br>
⦁ <b>Interpret:</b> it reads the commands it is sent and will execute them.<br>
⦁ <b>Terminate:</b> after it executes your commands, the shell executes any shutdown commands, frees memory, and terminates.</p>

<h2>Usage.</h2>

<h3>Interactive use:</h3>

<p>Occurs when the user enters commands directly into the shell as they are executed, thus allowing interaction with the operating system. In this way, the shell prints the command output on the screen and then waits for the user to enter another command.
</p>

<pre>
 $ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
</pre>

<h3>Non-interactive use:</h3>

<p>This is when the user sends a command file to the Shell that will be executed automatically without having to enter commands manually. In this way the command output can be redirected to a file or to another program for further processing.
</p>
<pre>
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
</pre>

<h2>Basic commands</h2>
<table>
  <tr>
<td>Comands</td>
<td>Description</td>
</tr>
  <tr>
    <td>ls</td>
    <td>Lists the contents of a directory. If used without arguments, lists the contents of the current directory.</td>
  </tr>
  <tr>
    <td>CTRL+D</td>
    <td>Method to exit the shell through the keyboard.</td>
  </tr>
  <tr>
    <td>env</td>
    <td>Run a program in a modified environment.</td>
  </tr>
  <td>man</td>
  <td>Gives information about commands or programs.</td>
  </tr>
  <tr>
  <td>exit</td>
  <td>closes the current shell.</td>
  </tr>
  </table>
  
  <h2>compilation</h2>
  <pre>
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
</pre>
  <h2>Flowcharts.</h2>
  foto
  <h2>description of the files.</h2>
  <table>
  <tr>
    <td>Files</td>
    <td>Descriptions</td>
  </tr>
  <tr>
    <td>main.h</td>
    <td>this file contains the functions to be used for the shell project.</td>
  </tr>
  <tr>
    <td> _shell.c</td>
    <td>this file contains two functions "int main(__attribute__((unused)) int argc, char *argv[])" and "char *Read_line(ssize_t *_exit_)" the first one contains a command interpreter that reads the input, tokenizes it, looks for the matching executable and executes it with the matching commands. finally, the second function reads the user input and stores it in a string. if the input comes from a terminal it will print a prompt "DEPS->". it will also check if the input is the command "exit", and if so, it exits the program as an error, freeing memory as well.</td>
  </tr>
  <tr>
    <td> _execute.c</td>
    <td>this file contains a function "int _EXE_Cute(char **args)" which creates a child process using 'fork()' and uses the execv system call to execute an external program inside that process.  It waits for the successful execution of the command in that process, and returns to the parent process where it resumes shell execution. If the process could not open correctly or execution was not possible it issues error messages.</td>
  </tr>
  <tr>
    <td>_token_separator.c</td>
    <td>This file contains the function *tokenicer(char *line, char *delimit) which receives a string and a delimiter and returns a linked list with the contents of the tokenized string.
</td>
  </tr>
  <tr>
    <td>_list_to_array.c</td>
    <td>This file contains the function _lsit_to_array(token_t *head) which receives a linked list and returns the data from its token field in an array of strings</td>
  </tr>
  <tr>
    <td>_path_finder.c</td>
    <td>This file contains the function *_getenv(char * str) that receives a string with the reference of which environment variable should be isolated from the external variable environ and returns a string with the values contained in that variable. Punctually we use it to extract the value of the PATH variable from environ.</td>
  </tr>
  <tr>
    <td>_stat_checker.c</td>
    <td>This file contains the function *_stat_checker(token_t *head, token_t *path) that using the stat system call checks if the command entered by the user exists and has the execution permissions in the specified path.  In addition, in this file you can find the _concat(char *str, char *add) function that we use as our version of "strcat", we decided to implement it since the original function allocates memory and we considered more convenient not to do it in this case to avoid later mummy errors.</td>
  </tr>
  <tr>
    <td>add_node_end.c</td>
    <td> This file contains the add_node_end(token_t **head, cosnt char *str) function that takes a string and places it as a new value in a linked list.</td>
  </tr>
  <tr>
    <td> free_list.c</td>
    <td>In this file is the free_lsit(token_t *head) fucnion that takes a linked list and frees the memory lodged in each of its registers.</td>
  </tr>
  <tr>
    <td>_env.c</td>
    <td>This file contains the _env(void) function which, like the env function, prints the contents of the system environment variables, i.e. the contents of the external variable</td>
  </tr>
  </table>
  
  <h2>Authors</h2>
  <h4><a href="https://github.com/Diego-Bonora"target="_blank">Diego Bonora</a></h4>
  <h4><a href="https://github.com/TheWhiteMachine"target="_blank">Pablo Riveiro</a></h4>
  <h4><a href="https://github.com/20Emi"target="_blank">Emily Sánchez</a></h4>
