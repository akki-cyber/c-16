#ifndef MOTD_H
#define MOTD_H

#include <rpc/rpc.h>

#define HISTORY_MAX 3
#define MESSAGE_MAX 60

extern char mList[HISTORY_MAX][MESSAGE_MAX + 1];
extern int mCount;

int *count_1_svc(void *argp, struct svc_req *rqstp);
char **get_1_svc(int *argp, struct svc_req *rqstp);
void *add_1_svc(char **argp, struct svc_req *rqstp);

#endif /* MOTD_H */
