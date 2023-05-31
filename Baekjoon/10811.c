#include <stdio.h>

void reverse_baskets(int baskets[], int i, int j)
{
    for (int s = i; s < (i + j) / 2 + 1; s++) {
        int tmp = baskets[s];

        baskets[s] = baskets[j - (s - i)];
        baskets[j - (s - i)] = tmp;
    }
}

int main()
{
    int N, M;
    int baskets[101];

    scanf("%d %d", &N, &M);

    /* Initialize baskets */
    for (int i = 1; i <= N; i++) {
        baskets[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int i, j;
        scanf("%d %d", &i, &j);

        reverse_baskets(baskets, i, j);
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", baskets[i]);
    }
    printf("\n");

    return 0;
}