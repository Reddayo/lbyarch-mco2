#include <stdio.h>
#include <stdlib.h>

float sdot_c(int n, float *A, float *B);
extern float sdot_asm(int n, float *A, float *B);

float *get_vector(int n);

int main() {
    int n;

    printf("Vector length: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    float *A = get_vector(n);
    float *B = get_vector(n);

    if (!A || !B) {
        printf("Memory allocation failed.\n");
        free(A);
        free(B);
        return 1;
    }

    float sdot = sdot_c(n, A, B);
    printf("Result - C:    %f\n", sdot);

    sdot = sdot_asm(n, A, B);
    printf("Result - ASM:  %f\n", sdot);

    free(A);
    free(B);

    return 0;
}

float sdot_c(int n, float *A, float *B) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];
    }
    return sum;
}


float *get_vector(int n) {
    float *vec = (float *)malloc(n * sizeof(float));
    if (!vec) return NULL;
    
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &vec[i]) != 1) {
            printf("Invalid input at %s[%d].\n", i);
            free(vec);
            return NULL;
        }
    }
    return vec;
}
