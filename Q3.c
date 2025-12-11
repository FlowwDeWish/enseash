#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT "enseash % "
#define BUFFER_SIZE 256

int main(void) {
    char buffer[BUFFER_SIZE];

    while (1) {
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        // CRTL D
        if (size == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            b;
        }



        buffer[size] = '\0';
        char *newline = strchr(buffer, '\n');
        if (newline)
            *newline = '\0';

        // exit
        if (strcmp(buffer, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            break;
        }

        // création du fils pour gérer la commande
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
