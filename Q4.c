#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    char buffer[BUFFER_SIZE];
    char prompt[50] = "enseash % ";

    while (1) {
        write(STDOUT_FILENO, prompt, strlen(prompt));

        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

        // CTRL+D
        if (size <= 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            exit(0);
        }

        buffer[size] = '\0';

        char *newline = strchr(buffer, '\n');
        if (newline)
            *newline = '\0';

        // commande exit
        if (strcmp(buffer, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            exit(0);
        }

        // création du fils
        pid_t pid = fork();

        if (pid == 0) {
            execlp(buffer, buffer, NULL);
            _exit(1);
        }

        // PÈRE : récupère status
        int status;
        wait(&status);

        // mise à jour du prompt selon EXIT ou SIGNAL
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            snprintf(prompt, 50, "enseash [exit:%d] %% ", code);
        }
        else if (WIFSIGNALED(status)) {
            int sig = WTERMSIG(status);
            snprintf(prompt, 50, "enseash [sign:%d] %% ", sig);
        }
    }

    return 0;
}
