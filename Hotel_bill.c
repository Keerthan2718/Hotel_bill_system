#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("D:/MY PROGRAMS/bill.txt", "a");
    char name[50];
    int choice, qty;
    float total = 0.0, tax, grandtotal;

    int idli_qty = 0, dosa_qty = 0, rotti_qty = 0, masaldosa_qty = 0;
    float idli_total = 0, dosa_total = 0, rotti_total = 0, masaldosa_total = 0;

    if (fp == NULL) {
        printf("error opening file\n");
        return 0;
    }

    printf("***WELCOME TO THE HOTEL SHREE DURGA***\n");
    printf("ENTER THE CUSTOMER NAME: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("\nMENU\n");
    printf("1. Idli         - 30 Rs\n");
    printf("2. Dosa         - 40 Rs\n");
    printf("3. Kori Rotti   - 40 Rs\n");
    printf("4. Masala Dosa  - 50 Rs\n");
    printf("5. PRINT BILL\n");

    while (1) {
        printf("\nEnter your item number (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                idli_qty += qty;
                idli_total += qty * 30;
                total += qty * 30;
                break;

            case 2:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                dosa_qty += qty;
                dosa_total += qty * 40;
                total += qty * 40;
                break;

            case 3:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                rotti_qty += qty;
                rotti_total += qty * 40;
                total += qty * 40;
                break;

            case 4:
                printf("Enter quantity: ");
                scanf("%d", &qty);
                masaldosa_qty += qty;
                masaldosa_total += qty * 50;
                total += qty * 50;
                break;

            case 5:
                tax = total * 0.05f;
                grandtotal = total + tax;

                printf("\n---------- BILL ----------\n");
                printf("CUSTOMER NAME: %s\n\n", name);
                printf("%-15s %5s %8s %10s\n", "Item", "Qty", "Price", "Amount");
                printf("----------------------------------------\n");

                if (idli_qty > 0)
                    printf("%-15s %5d %8d %10.2f\n", "Idli", idli_qty, 30, idli_total);
                if (dosa_qty > 0)
                    printf("%-15s %5d %8d %10.2f\n", "Dosa", dosa_qty, 40, dosa_total);
                if (rotti_qty > 0)
                    printf("%-15s %5d %8d %10.2f\n", "Kori Rotti", rotti_qty, 40, rotti_total);
                if (masaldosa_qty > 0)
                    printf("%-15s %5d %8d %10.2f\n", "Masala Dosa", masaldosa_qty, 50, masaldosa_total);

                printf("----------------------------------------\n");
                printf("%-20s %16.2f\n", "Subtotal", total);
                printf("%-20s %16.2f\n", "Tax (5%)", tax);
                printf("%-20s %16.2f\n", "Grand Total", grandtotal);
                printf("----------------------------------------\n");
                printf("THANK YOU! VISIT AGAIN.\n");

                fprintf(fp, "\n***WELCOME TO THE HOTEL SHREE DURGA***\n");
                fprintf(fp, "CUSTOMER NAME: %s\n\n", name);
                fprintf(fp, "%-15s %5s %8s %10s\n", "Item", "Qty", "Price", "Amount");
                fprintf(fp, "----------------------------------------\n");

                if (idli_qty > 0)
                    fprintf(fp, "%-15s %5d %8d %10.2f\n", "Idli", idli_qty, 30, idli_total);
                if (dosa_qty > 0)
                    fprintf(fp, "%-15s %5d %8d %10.2f\n", "Dosa", dosa_qty, 40, dosa_total);
                if (rotti_qty > 0)
                    fprintf(fp, "%-15s %5d %8d %10.2f\n", "Kori Rotti", rotti_qty, 40, rotti_total);
                if (masaldosa_qty > 0)
                    fprintf(fp, "%-15s %5d %8d %10.2f\n", "Masala Dosa", masaldosa_qty, 50, masaldosa_total);

                fprintf(fp, "----------------------------------------\n");
                fprintf(fp, "%-20s %16.2f\n", "Subtotal", total);
                fprintf(fp, "%-20s %16.2f\n", "Tax (5%)", tax);
                fprintf(fp, "%-20s %16.2f\n", "Grand Total", grandtotal);
                fprintf(fp, "----------------------------------------\n");
                fprintf(fp, "THANK YOU! VISIT AGAIN.\n");

                fclose(fp);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}