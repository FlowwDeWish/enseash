#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash % "
#define BUFFER_SIZE 256

int main(void) {
    char buffer[BUFFER_SIZE];

    write(STDOUT_FILENO, WELCOME_MSG, strlen(WELCOME_MSG));

    while (1) {
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);


        buffer[size] = '\0';

        char *newline = strchr(buffer, '\n');
        if (newline)
            *newline = '\0';


        if (strcmp(buffer, "exit") == 0)
            break;



        pid_t pid = fork();

        if (pid == 0) {

            execlp(buffer, buffer, NULL);


            _exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}