#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the target string:" << endl;
    string targetString ;
    cin >> targetString;

     cout << "Enter the replacement string:" << endl;
    string replacementString ;
    cin >> replacementString;


    pid_t PID = 0;
    int result = 0, filedes[2], status;

    /* Create child process: */
    PID = fork();

    if (PID == -1) {
        return 1;
    }

    result = pipe(filedes);

    if (PID != 0) {
        cout << "Created child process. PID: " << PID << "\n";
    }

    if (result == -1) {
        return 1;
    }

    if (PID == 0) { // This is the child process

        //replacement process
        targetString = replacementString;
        //
        string prog = "./" + path;
        execvp(prog.c_str(), NULL); // Execute the program
    } else { // This is the parent process
        waitpid(PID, &status, 0); // Wait for the child process to return.
        cout << "Process returned " << WEXITSTATUS(status) << ".\n";
        cout << "Press enter.\n";
    }

    return 0;
}
