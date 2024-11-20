/*Defne a date structure with variables day, month and year. Write functions to
1. Calculate the number of days between two days.
2. Find the day of the week for a given date
3. Check if a date is valid accounting for leap years.*/

/ didn't understand the logic of this question/

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int isLeapYear(int year);
int isValidDate(Date date);
int calculateDaysBetween(Date date1, Date date2);
void day_of_week(int date, int month, int year);

int main() {
    Date date1, date2;


    printf("Enter the first date (DD MM YYYY): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter the second date (DD MM YYYY): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    if (!isValidDate(date1) || !isValidDate(date2)) {
        printf("One or both of the dates are invalid.\n");
        return 1;
    }
    
    int daysBetween = calculateDaysBetween(date1, date2);
    printf("Number of days between the two dates: %d\n", daysBetween);


    printf("The day of the week for the first date is: ");
    day_of_week(date1.day, date1.month, date1.year);

    printf("The day of the week for the second date is: ");
    day_of_week(date2.day, date2.month, date2.year);

    return 0;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


int isValidDate(Date date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if (isLeapYear(date.year)) {
        daysInMonth[1] = 29;
    }

    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > daysInMonth[date.month - 1]) {
        return 0;
    }
    return 1;
}

int calculateDaysBetween(Date date1, Date date2) {
    int days = 0;
    if (date1.year > date2.year || (date1.year == date2.year && (date1.month > date2.month || (date1.month == date2.month && date1.day > date2.day)))) {
        Date temp = date1;
        date1 = date2;
        date2 = temp;
    }
    for (int year = date1.year; year < date2.year; year++) {
        days += isLeapYear(year) ? 366 : 365;
    }

    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(date1.year)) {
        daysInMonth[1] = 29;
    }
    for (int month = date1.month - 1; month < 12; month++) {
        days += daysInMonth[month];
    }
    days -= date1.day;

    if (isLeapYear(date2.year)) {
        daysInMonth[1] = 29;
    }
    for (int month = 0; month < date2.month - 1; month++) {
        days += daysInMonth[month];
    }
    days += date2.day;

    return days;
}


void day_of_week(int date, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (date + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    const char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("%s\n", days[h]);
}
