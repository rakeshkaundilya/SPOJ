#include<stdio.h>
#include<string.h>

int main() {
    int col, q, m,r;
    scanf("%d", &col);
    while (col) {
        char l[1000] = {'\0'}, new[200] = {'\0'};
        int sl, n = 0;
        getchar();
        gets(l);
        sl = strlen(l);
      
        r = sl / col;
        for (m = 0; m < col; m++) {
            for (q = 0; q < r; q++) {

                if (q % 2 == 0)
                    new[n] = l[m + q * col];
                else
                    new[n] = l[(q + 1) * col - 1 - m];

                n++;
            }
        }


        printf("%s", new);
        printf("\n");
        scanf("%d", &col);
    }
    return 0;
}

