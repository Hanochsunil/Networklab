#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int s;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    time_t ct;
    pid_t cp;

    if (argc != 3) {
        printf("Usage: client <server-addr> <port>\n");
        exit(0);
    }

    if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error in socket creation");
        exit(0);
    }

    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons((short)atoi(argv[2]));
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind error");
        exit(0);
    }

    socklen_t len = sizeof(cliaddr);
    bzero(buffer, 100);

    while (1) {
        if (recvfrom(s, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len) < 0) {
            perror("Error in recvfrom");
            exit(0);
        }

        ct = time(NULL);
        sprintf(buffer, "%s", ctime(&ct));

        if ((cp = fork()) == 0) {
            while (1) {
                if (sendto(s, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
                    perror("Error in sendto");
                    exit(0);
                }

                memset(buffer, 0, 100);

                if (recvfrom(s, buffer, 1024, 0, (struct sockaddr *)&cliaddr, &len) < 0) {
                    perror("Error in recvfrom");
                    exit(0);
                }

                sprintf(buffer, "%s", ctime(&ct));
            }
        } else if (cp < 0) {
            perror("Fork error");
            exit(0);
        }
    }

    close(s);
    return 0;
}
