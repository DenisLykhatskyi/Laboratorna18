#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulo(int a, int b);

int main() {
    int (*function_pointers[5])(int, int);

    function_pointers[0] = add;
    function_pointers[1] = subtract;
    function_pointers[2] = multiply;
    function_pointers[3] = divide;
    function_pointers[4] = modulo;

    int num1 = 10;
    int num2 = 5;
    int result;

    for (int i = 0; i < 5; i++) {
        result = function_pointers[i](num1, num2);
        printf("Результат функції %d: %d\n", i + 1, result);
    }

    printf("\nПовторний циклічний виклик з іншими аргументами:\n");
    num1 = 20;
    num2 = 4;
    for (int i = 0; i < 5; i++) {
        result = function_pointers[i](num1, num2);
        printf("Результат функції %d: %d\n", i + 1, result);
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Помилка: Ділення на нуль!\n");
        return 0;
    }
    return a / b;
}

int modulo(int a, int b) {
    if (b == 0) {
        printf("Помилка: Ділення на нуль для модуля!\n");
        return 0;
    }
    return a % b;
}