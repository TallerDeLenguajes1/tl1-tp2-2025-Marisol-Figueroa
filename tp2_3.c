#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main() {
    int mt[N][M];
    int *p = &mt[0][0]; 
    

    srand(time(NULL));

    for (int i = 0; i < N * M; i++) {
        *(p + i) = 1 + rand() % 100;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", mt[i][j]);  
        }
        printf("\n");
    }

    return 0;
}
