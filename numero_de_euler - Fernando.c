#include <stdio.h>
#include <stdlib.h>

int main() {

    int * vec;
    int n;
    int iterator = 0;
    while (1) {

        scanf("%d",&n);
        if (n == -1) break;
        int * tVec = vec;
        vec = malloc((iterator + 1) * sizeof(*vec));



        for(int i = 0; i < iterator + 1; i++) {
            if(i == iterator) {
                vec[i] = n;
                continue;
            }
            vec[i] = tVec[i];
        }
        iterator++;

    }

    for(int ii = 0; ii < iterator; ii++) {

        float e = 0;
        for(int i = 0; i <= vec[ii]; i++) {

            int fat = 1;
            for(int j = i; j > 1; j--){

                fat *= j;

            }

            e = e + 1/(float)fat;

        }

        printf("%f\n", e);
    }
    return 0;
}
