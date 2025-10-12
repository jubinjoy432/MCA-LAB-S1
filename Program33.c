/* Program to define a structure for dates with dd/mm/yyyy. Provide functions for reading, displaying and comparing two dates are equal or not
   @Jubin Joy 
   Roll No 35 
   19/09/2025
*/
#include <stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
void readDate(struct date *d)
{
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}
void displayDate(struct date d)
{
    printf("Date: %02d/%02d/%04d\n", d.day, d.month, d.year);
}
int areDatesEqual(struct date d1, struct date d2)
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
int main()
{
    struct date date1, date2;
    readDate(&date1);
    readDate(&date2);
    displayDate(date1);
    displayDate(date2);
    if (areDatesEqual(date1, date2))
        printf("The dates are equal.\n");
    else
        printf("The dates are not equal.\n");
    return 0;
}