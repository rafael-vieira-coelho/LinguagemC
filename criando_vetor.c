#include <stdio.h>
#include <stdlib.h>

//
// Created by Rafael  vieira coelho on 10/10/19.
//
int main(void) {
    int *pdata;
    size_t n;
    printf("Enter the size of the array: ");
    fflush(stdout); /* Make sure the prompt gets printed to buffered stdout. */
    if (1 != scanf("%zu", &n)) /* If zu is not supported (Windows?) use lu. */ {
        printf("scanf() did not read a in proper value.\n");
        exit(EXIT_FAILURE);
    }
    pdata = calloc(n, sizeof *pdata);
    if (NULL == pdata) {
        perror("calloc() failed"); /* Print error. */
        exit(EXIT_FAILURE);
    }
    free(pdata); /* Clean up. */
    return EXIT_SUCCESS;
}
