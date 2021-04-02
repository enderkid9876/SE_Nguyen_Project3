#include "prototypes.h"

// Takes user input until they quit the shell, and passes that input as
// arguments to be run.
int main()
{
    char *argv[MAX_ARGS], *cmd1[MAX_ARGS], *cmd2[MAX_ARGS];
    CommandType command_type;
    int argc;

    // Keep returning the user to the prompt ad infinitum unless they enter
    // 'quit' or 'exit' (without quotes).
    while (true)
    {
        // Display a prompt.
        cout << "Shell$ ";

        // Read in a command from the user.
        argc = read_args(argv);

        // Decipher the command we just read in and split it, if necessary, into
        // cmd1 and cmd2 arrays.  Set pipe_redirect to a PipeRedirect enum value to
        // indicate whether the given command pipes, redirects, or does neither.
        command_type = parse_command(argc, argv, cmd1, cmd2);

        // Determine how to handle the user's command(s).
        if (command_type == PIPE) // piping
            pipe_cmd(cmd1, cmd2);
        else if (command_type == REDIRECT) // redirecting
            redirect_cmd(cmd1, cmd2);
        else if (command_type == SEPARATED)
        {
            for (size_t i = 0; cmd1[i] != NULL; i++)
                cout << cmd1[i];
            
        }
        
        else
            run_cmd(argc, argv); // neither

        // Reset the argv array for next time.
        for (int i = 0; i < argc; i++)
            argv[i] = NULL;
    }

    // Let the OS know everything is a-okay.
    return 0;
}