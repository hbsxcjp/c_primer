#include <ctype.h>
#include <stdio.h>
#include <string.h>


void toUpper(char* str)
{
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin); //gets(st);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

struct month {
    int index;
    char name[10];
    char short_name[3];
    int day;
};

struct month months[12] = {
    { 1, "January", "JAN", 31 },
    { 2, "February", "FEB", 28 },
    { 3, "March", "MAR", 31 },
    { 4, "April", "APR", 30 },
    { 5, "May", "MAY", 31 },
    { 6, "June", "JUN", 30 },
    { 7, "July", "JUL", 31 },
    { 8, "August", "AUG", 31 },
    { 9, "September", "SEP", 30 },
    { 10, "October", "OCT", 31 },
    { 11, "November", "NOV", 30 },
    { 12, "December", "DEC", 31 }
};

void print_month(int index)
{
    struct month mon;
    int days = 0;
    if (index > 12) {
        index = 12;
    }
    for (int i = 0; i < index; i++) {
        mon = months[i];
        days += mon.day;
        printf("%2d %-10s %3s %2d %3d\n",
            mon.index, mon.name, mon.short_name, mon.day, days);
    }
}

int month_stoi(char* name)
{
    for (int i = 0; i < 12; i++) {
        if (strcmp(name, months[i].short_name) == 0) {
            return i + 1;
        }
    }
    return 0;
}

void test_i()
{
    int index;
    while (printf("Please input month's index: "),
        (scanf("%d", &index) != 0)) {
        print_month(index);
    };
}

void test_s()
{
    char name[20];
    while (printf("Please input month's name: "),
        s_gets(name, 10) != NULL && name[0] != '\0') {
        toUpper(name);
        print_month(month_stoi(name));
    }
}


int main(void)
{
    //test_i();
    //test_s();

    return -100;
}
