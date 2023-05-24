#include<stdio.h>
#include<stdlib.h>

int main() {
        FILE* ftr;
        ftr = fopen("file.txt", "w");
        if(ftr == NULL) {
                printf("Error!");
                exit(0);
        }

        int num = 6;
        fprintf(ftr, "Nums is %d", num);
        fclose(ftr);
        return 0;
}

