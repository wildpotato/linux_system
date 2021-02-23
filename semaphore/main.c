#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "binary_sems.h"

#define KEY   777
#define PERMS 0666

enum run_mode { SENDER = 1, RECEIVER = 2 };

void usage(const char *prog)
{
    printf("==============================================\n");
    printf("Usage: %s -m <mode> -r <round>\n\n", prog);
    printf("mode  :  sender / receiver\n");
    printf("round :  number of rounds\n");
    printf("==============================================\n");
}

void sender(int round)
{
    int semid = semget(KEY, 1, IPC_CREAT | IPC_EXCL | PERMS);

}

void receiver(int round)
{

}

int main(int argc, char **argv)
{
    struct option longOpts[] = {
        { "mode", required_argument, NULL, 'm'  },
        { "help", no_argument, NULL, 'h'        },
        { "round", required_argument, NULL, 'r' },
        {  NULL, 0, NULL, '\0'}};
    int opt_idx = 0, option = 0, round = 0;
    enum run_mode mode;

    while ((option = getopt_long(argc, argv, "m:h", longOpts,
                &opt_idx)) != -1) {
        switch(option) {
            case 'm':
                if (strcmp("sender", optarg) == 0) {
                    mode = SENDER;
                } else if (strcmp("receiver", optarg) == 0) {
                    mode = RECEIVER;
                } else {
                    printf("Unsupported mode\n");
                    return 1;
                }
                break;
            case 'r':
                round = atoi(optarg);
                break;
            case 'h':
                usage(argv[0]);
                return 0;
            default:
                usage(argv[0]);
                return 1;
        }
    }
    if (mode == SENDER) {
        sender(round);
    } else if (mode == RECEIVER) {
        receiver(round);
    } else {
    }
    printf("Hello, World!\n");
    return 0;
}
