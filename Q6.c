#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 256
#define MAX_ARGS 32

extern char **environ;

int main(void) {
    char buffer[BUFFER_SIZE];

    while (1) {
        write(STDOUT_FILENO, "enseash % ", 10);

        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (size <= 0)
            exit(0);

        buffer[size] = '\0';

        // supprimer le \n
        if (buffer[size - 1] == '\n')
            buffer[size - 1] = '\0';

        if (strcmp(buffer, "exit") == 0)
            exit(0);

        // tableau d’arguments
        char *argv[MAX_ARGS];
        int argc = 0;

        char *p = buffer;
        while (*p && argc < MAX_ARGS - 1) {
            while (*p == ' ') p++;           // sauter espaces
            if (*p == '\0') break;

            argv[argc++] = p;               // début de l’argument
            while (*p && *p != ' ') p++;    // avancer jusqu’à l’espace
            if (*p) {
                *p = '\0';                  // couper la chaîne
                p++;
            }
        }
        argv[argc] = NULL;

        pid_t pid = fork();

        if (pid == 0) {
            execvp(argv[0], argv);
            perror("execvp");
            _exit(1);
        }

        wait(NULL);
    }
}
