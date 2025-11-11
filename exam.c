#include <stdio.h>

// Structure for date
struct Date {
    int day;
    int month;
    int year;
};

// Structure for passport holder details
struct Holder {
    char name[50];
    struct Date dob;  // date of birth
    char address[100];
    char nationality[30];
};

// Structure for passport details
struct Passport {
    char passportNumber[20];
    struct Date issueDate;
    struct Date expiryDate;
    char issuingCountry[30];
    struct Holder holder;  // nested structure
};

int main() {
    struct Passport p;

    // Input passport details
    printf("Enter passport number: ");
    scanf("%s", p.passportNumber);

    printf("Enter issuing country: ");
    scanf("%s", p.issuingCountry);

    printf("Enter issue date (DD MM YYYY): ");
    scanf("%d %d %d", &p.issueDate.day, &p.issueDate.month, &p.issueDate.year);

    printf("Enter expiry date (DD MM YYYY): ");
    scanf("%d %d %d", &p.expiryDate.day, &p.expiryDate.month, &p.expiryDate.year);

    // Input holder details
    printf("Enter holder name: ");
    scanf(" %[^\n]", p.holder.name); // to allow spaces

    printf("Enter holder address: ");
    scanf(" %[^\n]", p.holder.address);

    printf("Enter holder nationality: ");
    scanf("%s", p.holder.nationality);

    printf("Enter holder date of birth (DD MM YYYY): ");
    scanf("%d %d %d", &p.holder.dob.day, &p.holder.dob.month, &p.holder.dob.year);

    // Display the entered passport information
    printf("\n--- Passport Details ---\n");
    printf("Passport Number: %s\n", p.passportNumber);
    printf("Issuing Country: %s\n", p.issuingCountry);
    printf("Issue Date: %02d/%02d/%04d\n", p.issueDate.day, p.issueDate.month, p.issueDate.year);
    printf("Expiry Date: %02d/%02d/%04d\n", p.expiryDate.day, p.expiryDate.month, p.expiryDate.year);

    printf("\n--- Holder Details ---\n");
    printf("Name: %s\n", p.holder.name);
    printf("Date of Birth: %02d/%02d/%04d\n", p.holder.dob.day, p.holder.dob.month, p.holder.dob.year);
    printf("Address: %s\n", p.holder.address);
    printf("Nationality: %s\n", p.holder.nationality);

    return 0;
}
