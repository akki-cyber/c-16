#include "motd.h"

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "usage: %s server_host [message]\n", argv[0]);
        exit(1);
    }

    CLIENT *clnt = clnt_create(argv[1], MOTD_PROG, MOTD_VERS, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(argv[1]);
        exit(EXIT_FAILURE);
    }

    if (argc == 3) {
        // Call the remote ADD procedure to add a new message to the server's list
        char *add_1_arg = argv[2];
        add_1(&add_1_arg, clnt);
    } else {
        // Call the remote COUNT and GET procedures to print the list of messages
        char *count_1_arg;
        int *np = count_1((void *)&count_1_arg, clnt);
        if (np == (int *)NULL) {
            clnt_perror(clnt, "call failed");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < *np; i++) {
            char **spp = get_1(&i, clnt);
            if (spp == (char **)NULL) {
                clnt_perror(clnt, "call failed");
                exit(EXIT_FAILURE);
            }
            printf("%s\n", *spp);
        }
    }

    clnt_destroy(clnt);
    exit(EXIT_SUCCESS);
}
