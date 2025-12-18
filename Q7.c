#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define MAX_ARGS 32

int main(void) {
    char buffer[BUFFER_SIZE];
    char *argv[MAX_ARGS];

    while (1) {

        /* prompt */
        write(STDOUT_FILENO, "enseash % ", 10);

        /* lecture */
        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (size <= 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            exit(0);
        }

        buffer[size] = '\0';

        /* enlever le \n */
        if (buffer[size - 1] == '\n')
            buffer[size - 1] = '\0';

        /* exit */
        if (strcmp(buffer, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 11);
            exit(0);
        }

        /* découpage en arguments */
        int argc = 0;
        char *p = buffer;

        while (*p && argc < MAX_ARGS - 1) {
            while (*p == ' ') p++;
            if (*p == '\0') break;

            argv[argc++] = p;
            while (*p && *p != ' ') p++;
            if (*p) {
                *p = '\0';
                p++;
            }
        }
        argv[argc] = NULL;

        /* redirections */
        char *input_file = NULL;
        char *output_file = NULL;

        for (int i = 0; argv[i] != NULL; i++) {
            if (strcmp(argv[i], ">") == 0 && argv[i + 1] != NULL) {
                output_file = argv[i + 1];
                argv[i] = NULL;   /* coupe la commande AVANT '>' */
                break;
            }
            if (strcmp(argv[i], "<") == 0 && argv[i + 1] != NULL) {
                input_file = argv[i + 1];
                argv[i] = NULL;
                break;
            }
        }

        pid_t pid = fork();

        if (pid == 0) {

            /* stdout > fichier */
            if (output_file) {
                int fd = open(output_file,
                              O_WRONLY | O_CREAT | O_TRUNC,
                              0644);
                if (fd < 0) {
                    perror("open");
                    _exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }

            /* stdin < fichier */
            if (input_file) {
                int fd = open(input_file, O_RDONLY);
                if (fd < 0) {
                    perror("open");
                    _exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }

            execvp(argv[0], argv);
            perror("execvp");
            _exit(1);
        }

        wait(NULL);
    }
}
