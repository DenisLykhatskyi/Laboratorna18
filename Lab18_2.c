#include <stdio.h>
#include <math.h>

void inputArray(double arr[], int size, const char* arr_name) {
    printf("Введіть %d елементів для масиву %s:\n", size, arr_name);
    for (int i = 0; i < size; ++i) {
        scanf("%lf", &arr[i]);
    }
}

void processArray(double arr[], int size, char type, double* res1, double* res2, double* res3) {
    double s = 0.0;
    double p = 1.0;

    if (size == 0) {
        p = 1.0; // Product of empty set is 1
    } else {
        for (int i = 0; i < size; ++i) {
            s += arr[i];
            p *= arr[i];
        }
    }
    
    if (size == 0 && type == 'z'){ // Ensure p is 1 if array is empty for z
         p = 1.0;
    } else if (size == 0 && type == 'b'){ // Ensure p is 1 if array is empty for beta
         p = 1.0;
    }


    if (type == 'z') {
        double sum_exp_zi = 0.0;
        double sum_zi_cos_zi = 0.0;
        double sum_zi_sin_zi = 0.0;

        for (int i = 0; i < size; ++i) {
            sum_exp_zi += exp(arr[i]);
            sum_zi_cos_zi += arr[i] * cos(arr[i]);
            sum_zi_sin_zi += arr[i] * sin(arr[i]);
        }
        *res1 = s * sum_exp_zi;
        *res2 = p * sum_zi_cos_zi;
        *res3 = p * sum_zi_sin_zi;
    } else if (type == 'b') {
        double sum_betai_sin_betai = 0.0;
        double sum_betai_tan_betai = 0.0;
        double sum_betai_abs_betai = 0.0;

        for (int i = 0; i < size; ++i) {
            sum_betai_sin_betai += arr[i] * sin(arr[i]);
            sum_betai_tan_betai += arr[i] * tan(arr[i]);
            sum_betai_abs_betai += arr[i] * fabs(arr[i]);
        }
        *res1 = s * sum_betai_sin_betai;
        *res2 = p * sum_betai_tan_betai;
        *res3 = p * sum_betai_abs_betai;
    }
}

int main() {
    int n, m;

    printf("Введіть кількість елементів для масиву z (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів для масиву beta (m): ");
    scanf("%d", &m);

    double z[n];
    double beta[m];

    if (n > 0) {
        inputArray(z, n, "z");
    }
    if (m > 0) {
        inputArray(beta, m, "beta");
    }
    

    double A, B, C;
    double D, E, F;

    processArray(z, n, 'z', &A, &B, &C);
    processArray(beta, m, 'b', &D, &E, &F);

    double omega;
    if ((D + E + cos(F)) == 0) {
        printf("Помилка: Ділення на нуль при обчисленні omega.\n");
        return 1;
    }
    omega = (A + B + sin(C)) / (D + E + cos(F));

    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("Omega = %lf\n", omega);

    return 0;
}