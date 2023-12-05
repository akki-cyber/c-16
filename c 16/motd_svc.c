#include "motd.h"

int *count_1_svc(void *argp, struct svc_req *rqstp) {
    return &mCount;
}

char **get_1_svc(int *argp, struct svc_req *rqstp) {
    static char *result;

    if (*argp < 0 || *argp >= mCount) {
        result = "error";
        return &result;
    }

    result = mList[*argp];
    return &result;
}

void *add_1_svc(char **argp, struct svc_req *rqstp) {
    // Implement the ADD procedure to add a new message to the mList
    // You need to slide existing messages to make room for the new message
}
