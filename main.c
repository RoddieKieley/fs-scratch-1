#include <stdio.h>
#include <string.h>

static void print_usage(const char *program)
{
    fprintf(stderr, "Usage: %s [--message <text>] [--colour <red|blue|green>]\n",
            program);
}

int main(int argc, char *argv[])
{
    const char *message = "Hello C World!";
    const char *colour = NULL;
    const char *colour_code;
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--message") == 0) {
            if (i + 1 >= argc) {
                print_usage(argv[0]);
                return 1;
            }
            message = argv[++i];
        } else if (strcmp(argv[i], "--colour") == 0) {
            if (i + 1 >= argc) {
                print_usage(argv[0]);
                return 1;
            }
            colour = argv[++i];
        } else {
            print_usage(argv[0]);
            return 1;
        }
    }

    if (colour != NULL) {
        if (strcmp(colour, "red") == 0) {
            colour_code = "\033[31m";
        } else if (strcmp(colour, "green") == 0) {
            colour_code = "\033[32m";
        } else if (strcmp(colour, "blue") == 0) {
            colour_code = "\033[34m";
        } else {
            fprintf(stderr, "Specified colour not supported.\n");
            return 1;
        }
        printf("%s%s\033[0m\n", colour_code, message);
    } else {
        printf("%s\n", message);
    }

    return 0;
}
