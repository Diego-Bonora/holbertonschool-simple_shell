<h1 align = "center"> Shell project </h1>

<h2>Description.</h2>

<p>The Shell is in charge of executing the basic commands for system management, it is a fundamental part of an operating system, having features such as process control, input/output redirection and a command language for writing programs.<br>

The shell does three main things:<br>

⦁ <b>Initialize:</b> it will read and execute your configuration files.<br>
⦁ <b>Interpret:</b> it reads the commands it is sent and will execute them.<br>
⦁ <b>Terminate:</b> after it executes your commands, the shell executes any shutdown commands, frees memory, and terminates.</p>

<details>
 <summary><h2>Usage.</h2></summary>

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
</details>
 <details>
 <summary><h2>Flowchart.</h2></summary>
  
  ![Shell ](https://user-images.githubusercontent.com/124268926/235258205-f7d65531-8ad7-4e9e-a058-033616c93a5e.jpg)
</details>
  <details>
 <summary><h2>description of the files.</h2></summary>
  
  1.  [ _shell.c ](#_shell.c)
  
  2.  [_execute.c](#_execute.c)
  
  3.  [main.h](#main.h)
  
  4.  [_token_separator.c](#_token_separator.c)
  
  5.  [_list_to_array.c](#_list_to_array.c)
  
  6.  [_path_finder.c ](#_path_finder.c)
  
  7.  [_stat_checker.c ](#_stat_checker.c)
  
  8.  [add_node_end.c](#add_node_end.c)
  
  9.  [free_list.c](#free_list.c)
  
  10. [_env.c ](#_env.c)
  
  <a name="_shell.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_shell.c"target="_blank">_shell.c</a></h2>
  
 The first function contains a command interpreter that selects the input, tokenizes it, looks for the matching executable and executes it with the matching commands. Finally, the second function reads the user input and stores it in a character string. It will also check if the input is the command "exit", and if so, it exits the program as an error, freeing memory as well.
 <pre>
 Prototype: int main(__attribute__((unused)) int argc, char *argv[])
 </pre>
 <pre>
 Prototype: char *Read_line(ssize_t *_exit_)
 </pre>
  ---
  <a name="_execute.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_execute.c"target="_blank">_execute.c</a></h2>
  
creates a child process using 'fork()' and uses the execv system call to execute an external program within that process.  It waits for the command to execute successfully in that process and returns to the parent process where it resumes shell execution. If the process could not open correctly or execution was not possible, it issues error messages.

 <pre>
 Prototype: int _EXE_Cute(char **args)" 
 </pre>
  ---
  <a name="main.h"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/main.h"target="_blank">main.h</a></h2>
  
  this file contains the functions to be used for the shell project
  
  ---
  <a name="_token_separator.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_token_separator.c"target="_blank">_token_separator</a></h2>
  receives a string and a delimiter and returns a linked list with the contents of the tokenized string.
  
   <pre>
 Prototype: token_t *tokenicer(char *line, char *delimit)
 </pre>
  ---
  <a name="_list_to_array.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_list_to_array.c"target="_blank">_list_to_array.c</a></h2>
 receives a linked list and returns the data from its token field in an array of strings
 
  <pre>
 Prototype: char **_list_to_array(token_t *head)
 </pre>
  ---
  <a name="_path_finder.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_path_finder.c"target="_blank">_path_finder.c </a></h2>
  receives a string with the reference of which environment variable should be isolated from the external variable environ and returns a string with the values contained in that variable. Punctually we use it to extract the value of the PATH variable from environ.
  
   <pre>
 Prototype: token_t *_getenv(char *str)
 </pre>
  ---
  <a name="_stat_checker.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_stat_checker.c"target="_blank">_stat_checker</a></h2>
in the first function calls the stat system that checks if the command entered by the user exists and has the permissions to execute in the specified path.  Also, in this file is the second function that we use as our version of "strcat", we decided to implement it since the original function allocates memory and we considered it more convenient not to do so in this case to avoid later mummy errors.

 <pre>
 Prototype: token_t *_stat_checker(token_t *head, token_t *path)
 </pre>
  <pre>
 Prototype: char *_concat(char *str, char *add)
 </pre>
  
  ---
  <a name="add_node_end.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/add_node_end.c"target="_blank">add_node_end.c</a></h2>
  takes a string and places it as a new value in a linked list.
  
   <pre>
 Prototype: token_t *add_node_end(token_t **head, const char *str)
 </pre>
  ---
  <a name="free_list.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/free_list.c"target="_blank">free_list.c</a></h2>
  function that takes a linked list and frees the memory lodged in each of its registers.
 <pre>
 Prototype: void free_list(token_t *head)
 </pre>
  ---
  <a name="_env.c"></a>
  <h2><a href="https://github.com/Diego-Bonora/holbertonschool-simple_shell/blob/master/_env.c"target="_blank">_env.c</a></h2>
  function which, like the env function, prints the contents of the system environment variables, i.e. the contents of the external variable.
  
  <pre>
 Prototype: void _env(void)
 </pre>
  ---
  </details>
  
  <h2>Authors</h2>
  <h4><a href="https://github.com/Diego-Bonora"target="_blank">Diego Bonora</a></h4>
  <h4><a href="https://github.com/TheWhiteMachine"target="_blank">Pablo Riveiro</a></h4>
  <h4><a href="https://github.com/20Emi"target="_blank">Emily Sánchez</a></h4>
