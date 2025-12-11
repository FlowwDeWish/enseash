#include <unistd.h>
#include <string.h>

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define PROMPT "enseash % "

int main(void) {
    write(STDOUT_FILENO, WELCOME_MSG, strlen(WELCOME_MSG));
    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
    while (1) {

    }

    return 0;
}
