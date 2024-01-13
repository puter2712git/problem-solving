#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    int baskets[101] = { 0, };

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);

        for (int l = i; l <= j; l++) {
            baskets[l] = k;
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", baskets[i]);
    }
    printf("\n");

    return 0;
}