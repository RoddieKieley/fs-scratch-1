#include <stdio.h>
#include <string.h>

static void print_usage(const char *program)
{
    fprintf(stderr, "Usage: %s [--message <text>]\n", program);
}

int main(int argc, char *argv[])
{
    const char *message = "Hello C World!";
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--message") == 0) {
            if (i + 1 >= argc) {
                print_usage(argv[0]);
                return 1;
            }
            message = argv[++i];
        } else {
            print_usage(argv[0]);
            return 1;
        }
    }

    printf("%s\n", message);
    return 0;
}
