#DirectText: a text editor where you can edit text files while looking at the terminal.
##Why I created DirectText
I am working on a website for a nonprofit whose name and mission I will keep secret for now, and have to access the website via ssh. I realize that, since I am only learning how to code websites, it is very useful to look at files I have already written to help me write new files. This is a feature that will be added to the program soon.
##How to install
1. Make sure that you have build-essential installed
2. Enter `g++ main.cpp -o directtext` into the terminal.
3. Move `directtext` wherever you want.
##How to use
The syntax is:
> `./directtext [filename]`

If you do not specify a filename on starting the program, it will ask you to for a filename when you write out.
###Commands
Syntax
> `[character][arguments]`
For now, the commands are:
* `L[line]`: Enter a line to the end of the file.
* `C`: See what lines you have entered so far.
* `W`: Write out to a file
* `X`: Exit the program
