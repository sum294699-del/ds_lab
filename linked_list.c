#include <stdio.h>
#include <stdlib.h>

// Structure to store employee salary details
struct Employee {
    float basic;
    float hra;
    float da;
    float monthly_total;
    float annual_total;
};

int main() {
    int i, n;
    struct Employee *emp;

    // Ask user how many employees to enter
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Allocate memory for n employees
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input details for each employee
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].basic);

        printf("Enter HRA: ");
        scanf("%f", &emp[i].hra);

        printf("Enter DA: ");
        scanf("%f", &emp[i].da);

        // Calculate salary
        emp[i].monthly_total = emp[i].basic + emp[i].hra + emp[i].da;
        emp[i].annual_total = emp[i].monthly_total * 12;
    }

    // Display results
    printf("\n\n----- Salary Summary -----\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Basic Salary: %.2f\n", emp[i].basic);
        printf("HRA: %.2f\n", emp[i].hra);
        printf("DA: %.2f\n", emp[i].da);
        printf("Monthly Total Salary: %.2f\n", emp[i].monthly_total);
        printf("Annual Total Salary: %.2f\n", emp[i].annual_total);
    }

    // Free memory
    free(emp);

    return 0;
}
