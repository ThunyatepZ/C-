#include <stdio.h>
#include <time.h>

int main()
{

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    float basic, gross, da, hra;

    printf("Enter basic salary of an employee: ");
    scanf("%f", &basic);

    if (basic <= 10000)
    {
        da = basic * 0.8;
        hra = basic * 0.2;
    }
    else if (basic <= 20000)
    {
        da = basic * 0.9;
        hra = basic * 0.25;
    }
    else
    {
        da = basic * 0.95;
        hra = basic * 0.3;
    }

    gross = basic + hra + da;

    printf("GROSS SALARY OF EMPLOYEE = %.2f\n", gross);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time = %f seconds\n", cpu_time_used);

    return 0;
}