#include "motd.h"

int main(int argc, char *argv[]) {
    // Initialize message list and count
    mCount = 0;
    for (int i = 0; i < HISTORY_MAX; ++i) {
        memset(mList[i], 0, MESSAGE_MAX + 1);
    }

    // Start the server
    registerrpc(MOTD_PROG, MOTD_VERS, COUNT, count_1_svc, xdr_void, xdr_int);
    registerrpc(MOTD_PROG, MOTD_VERS, GET, get_1_svc, xdr_int, xdr_wrapstring);
    registerrpc(MOTD_PROG, MOTD_VERS, ADD, add_1_svc, xdr_wrapstring, xdr_void);

    svc_run();
    return 0;
}
