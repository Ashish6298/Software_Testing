#include<stdio.h>

int check(int day, int month) {
    return (month == 4 || month == 6 || month == 9 || month == 11) && day == 31;
}

int isleap(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int main() {
    int day, month, year;

    do {
        printf("Enter today's date (dd mm yyyy): ");
        scanf("%d %d %d", &day, &month, &year);

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1812 || year > 2018) {
            printf("Invalid input! Day (1-31), Month (1-12), Year (1812-2018)\n");
            continue;
        }

        if (check(day, month)) {
            printf("Day cannot be 31 for this month\n");
            continue;
        }

        if (month == 2) {
            if ((isleap(year) && day > 29) || (!isleap(year) && day > 28)) {
                printf("Invalid day for February\n");
                continue;
            }
        }
        break;
    } while (1);

    day++;
    int days_in_month = (month == 2) ? (isleap(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31);
    
    if (day > days_in_month) {
        day = 1;
        month++;
    }

    if (month > 12) {
        month = 1;
        year++;
        if (year > 2018) {
            printf("Next year out of range\n");
            return 0;
        }
    }

    printf("Next day is: %02d/%02d/%d\n", day, month, year);
    return 0;
}
