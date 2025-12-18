#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Структура для комплексного числа
typedef struct {
    double real;
    double imag;
} Complex;

// Функции для работы с комплексными числами
Complex create_complex(double real, double imag) {
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

void print_complex(Complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi", c.real, c.imag);
    }
    else {
        printf("%.2f - %.2fi", c.real, -c.imag);
    }
}

Complex add(Complex a, Complex b) {
    return create_complex(a.real + b.real, a.imag + b.imag);
}

Complex subtract(Complex a, Complex b) {
    return create_complex(a.real - b.real, a.imag - b.imag);
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;

    if (denominator == 0) {
        printf("Ошибка: деление на ноль!\n");
        return create_complex(0, 0);
    }

    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

double magnitude(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

Complex conjugate(Complex c) {
    return create_complex(c.real, -c.imag);
}

Complex power(Complex c, int n) {
    Complex result = create_complex(1, 0);

    for (int i = 0; i < n; i++) {
        result = multiply(result, c);
    }

    return result;
}

// Функция для отображения меню
void display_menu() {
    printf("\n=== МЕНЮ ОПЕРАЦИЙ С КОМПЛЕКСНЫМИ ЧИСЛАМИ ===\n");
    printf("1. Ввод комплексных чисел\n");
    printf("2. Сложение\n");
    printf("3. Вычитание\n");
    printf("4. Умножение\n");
    printf("5. Деление\n");
    printf("6. Модуль числа\n");
    printf("7. Сопряженное число\n");
    printf("8. Возведение в степень\n");
    printf("9. Показать текущие числа\n");
    printf("0. Выход\n");
    printf("==========================================\n");
    printf("Выберите операцию: ");
}

int main() {
    Complex num1 = create_complex(0, 0);
    Complex num2 = create_complex(0, 0);
    int choice;
    int power_val;

    printf("Программа для работы с комплексными числами\n");

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Ввод чисел
            printf("Введите первое комплексное число (действительная и мнимая части): ");
            scanf("%lf %lf", &num1.real, &num1.imag);
            printf("Введите второе комплексное число (действительная и мнимая части): ");
            scanf("%lf %lf", &num2.real, &num2.imag);
            printf("Числа сохранены.\n");
            break;

        case 2: // Сложение
            printf("(");
            print_complex(num1);
            printf(") + (");
            print_complex(num2);
            printf(") = ");
            print_complex(add(num1, num2));
            printf("\n");
            break;

        case 3: // Вычитание
            printf("(");
            print_complex(num1);
            printf(") - (");
            print_complex(num2);
            printf(") = ");
            print_complex(subtract(num1, num2));
            printf("\n");
            break;

        case 4: // Умножение
            printf("(");
            print_complex(num1);
            printf(") * (");
            print_complex(num2);
            printf(") = ");
            print_complex(multiply(num1, num2));
            printf("\n");
            break;

        case 5: // Деление
            printf("(");
            print_complex(num1);
            printf(") / (");
            print_complex(num2);
            printf(") = ");
            print_complex(divide(num1, num2));
            printf("\n");
            break;

        case 6: // Модуль
            printf("|");
            print_complex(num1);
            printf("| = %.2f\n", magnitude(num1));
            printf("|");
            print_complex(num2);
            printf("| = %.2f\n", magnitude(num2));
            break;

        case 7: // Сопряженное
            printf("Сопряженное для ");
            print_complex(num1);
            printf(" = ");
            print_complex(conjugate(num1));
            printf("\n");
            printf("Сопряженное для ");
            print_complex(num2);
            printf(" = ");
            print_complex(conjugate(num2));
            printf("\n");
            break;

        case 8: // Возведение в степень
            printf("Введите степень для возведения: ");
            scanf("%d", &power_val);
            printf("(");
            print_complex(num1);
            printf(")^%d = ", power_val);
            print_complex(power(num1, power_val));
            printf("\n");
            break;

        case 9: // Показать числа
            printf("Первое число: ");
            print_complex(num1);
            printf("\nВторое число: ");
            print_complex(num2);
            printf("\n");
            break;

        case 0: // Выход
            printf("Выход из программы...\n");
            break;

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

    } while (choice != 0);

    return 0;
}