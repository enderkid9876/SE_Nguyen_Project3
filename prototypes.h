#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
using namespace std;

// Will be used to create an array to hold individual arguments passed by
// the user on the command line.
const int MAX_ARGS = 256;

enum CommandType
{
    PIPE,
    REDIRECT,
    SEPARATED,
    NEITHER
};

// Splits a user's command into two commands, or a command and a file name.
CommandType parseCommand(int &, char **, char **, char **);

// Pipes the first command's output into the second.
void pipeCommands(char **, char **);

// Reads input from the user into the given array and returns the number of
// arguments taken in.
int readInputs(char **);

// Redirects the output from the given command into the given file.
void redirectCommands(char **, char **);

// Given the number of arguments and an array of arguments, this will execute
// those arguments.  The first argument in the array should be a command.
void singleCommands(int, char **);

// Given a string of user input, this will determine if the user wants to
// quit the shell.
bool quitCheck(string);