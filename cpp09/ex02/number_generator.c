#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void shuffle_ints(int *arr, int n)
{
    int i = n - 1;
    while (i > 0) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        --i;
    }
}

int main(int argc, char **argv)
{
    int n = 3000;
    if (argc > 1) {
        n = atoi(argv[1]);
        if (n <= 0) {
            fprintf(stderr, "Usage: %s [count]\n", argv[0]);
            return 1;
        }
    }

    int *arr = (int *)malloc(sizeof(int) * (size_t)n);
    if (!arr) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = i + 1;

    srand((unsigned)(time(NULL) ^ getpid()));
    shuffle_ints(arr, n);

    for (int i = 0; i < n; ++i)
        printf("%d%s", arr[i], (i + 1 == n) ? "\n" : " ");

    free(arr);
    return 0;
}