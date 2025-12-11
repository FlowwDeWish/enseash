#include <unistd.h>
#include <string.h>

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash % "
#define BUFFER_SIZE 256

int main(void) {
    char buffer[BUFFER_SIZE];

    write(STDOUT_FILENO, WELCOME_MSG, strlen(WELCOME_MSG));

    while (1) {
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
        if (size <= 0) {
            break;
        }

        buffer[size] = '\0';



        
    }

    return 0;
}
