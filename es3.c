#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        pid_t pid2 = fork();

        if (pid2 == 0) {
            printf("[Nipote] Il mio PID e': %d\n", getpid());
            printf("[Nipote] Termino\n");
            exit(0);
        } else {
            wait(NULL);
            printf("[Padre] Il mio PID e': %d\n", getpid());
            printf("[Padre] Termino\n");
            exit(0);
        }
    } else {
        wait(NULL);
        printf("[Nonno] Il mio PID e': %d\n", getpid());
        printf("[Nonno] Termino\n");
    }

    return 0;
}
