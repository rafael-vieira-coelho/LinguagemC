#include <stdio.h>
#include <getopt.h>
#include <string.h>

/* print a description of all supported options */
void usage(FILE *fp, const char *path) {
    /* take only the last portion of the path */
    const char *basename = strrchr(path, '/');
    basename = basename ? basename + 1 : path;
    fprintf(fp, "usage: %s [OPTION]\n", basename);
    fprintf(fp, " -h, --help\t\t"
                "Print this help and exit.\n");
    fprintf(fp, " -m, --msg=STRING\t"
                "Output a particular message rather than 'Hello world'.\n");
}

/* parse command-line options and print message */
int main(int argc, char *argv[]) {
    /* for code brevity this example just uses fixed buffer sizes for strings */
    char message[256] = "Hello world";
    int help_flag = 0;
    int opt;
/* table of all supported options in their long form.
 * fields: name, has_arg, flag, val
 * `has_arg` specifies whether the associated long-form option can (or, in
 * some cases, must) have an argument. the valid values for `has_arg` are
 * `no_argument`, `optional_argument`, and `required_argument`.
 * if `flag` points to a variable, then the variable will be given a value
 * of `val` when the associated long-form option is present at the command
 * line.
 * if `flag` is NULL, then `val` is returned by `getopt_long` (see below)
 * when the associated long-form option is found amongst the command-line
 * arguments.
 */
    struct option longopts[] = {
            {"help", no_argument,       &help_flag, 1},
            {"msg",  required_argument, NULL,       'm'},
            {0}
    };
/* infinite loop, to be broken when we are done parsing options */
    while (1) {
/* getopt_long supports GNU-style full-word "long" options in addition
     * to the single-character "short" options which are supported by
     * getopt.
     * the third argument is a collection of supported short-form options.
     * these do not necessarily have to correlate to the long-form options.
     * one colon after an option indicates that it has an argument, two
     * indicates that the argument is optional. order is unimportant.
     */
        opt = getopt_long(argc, argv, "hf::m:", longopts, 0);
        if (opt == -1) {
/* a return value of -1 indicates that there are no more options */ break;
        }
        switch (opt) {
            case 'h':
                /* the help_flag and value are specified in the longopts table,
                 * which means that when the --help option is specified (in its long
                 * form), the help_flag variable will be automatically set.
                 * however, the parser for short-form options does not support the
                 * automatic setting of flags, so we still need this code to set the
                 * help_flag manually when the -h option is specified.
                 */
                help_flag = 1;
                break;
            case 'm':
/* since the argument for this option is required, getopt guarantees
         * that aptarg is non-null.
*/
                strncpy(message, optarg, sizeof(message));
                message[sizeof(message) - 1] = '\0';
                break;
            case '?':
                /* a return value of '?' indicates that an option was malformed.
                 * this could mean that an unrecognized option was given, or that an
                 * option which requires an argument did not include an argument.
                 */
                usage(stderr, argv[0]);
                return 1;
            default:
                break;
        }
    }
    if (help_flag) {
        usage(stdout, argv[0]);
        return 0;
    }
    printf("%s\n", message);
    return 0;
}
