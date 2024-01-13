#include <stdio.h>
#include <stdlib.h>

void exchange_ball(int baskets[], int i, int j)
{
    int tmp = baskets[i];

    baskets[i] = baskets[j];
    baskets[j] = tmp;
}

int main()
{
    int N, M;
    int baskets[101] = { 0, };

    scanf("%d %d", &N, &M);
    
    // Initialize basket
    for (int i = 1; i <= N; i++) {
        baskets[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int i, j;
        scanf("%d %d", &i, &j);

        exchange_ball(baskets, i, j);
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", baskets[i]);
    }
    printf("\n");

    return 0;
}