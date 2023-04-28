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
~~~
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
~~~

<h3>Non-interactive use:</h3>
<p>This is when the user sends a command file to the Shell that will be executed automatically without having to enter commands manually. In this way the command output can be redirected to a file or to another program for further processing.
</p>

## Authors
Diego Bonora
Emily Sanchez
Pablo Riveiro
