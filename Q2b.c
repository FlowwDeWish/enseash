#include <unistd.h>
#include <string.h>

#define PROMPT "enseash % "
#define BUFFER_SIZE 256

int main(void) {
    char buffer[BUFFER_SIZE];

    write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

    ssize_t size = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);

    buffer[size] = '\0';

    char *newline = strchr(buffer, '\n');
    if (newline)
        *newline = '\0';


    execlp(buffer, buffer, NULL);



    return 0;
}
