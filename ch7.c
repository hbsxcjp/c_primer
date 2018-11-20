#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

void ch7_1(void);
void ch7_2(void);
void ch7_3(void);
void ch7_4(void);
void ch7_5(void);
void ch7_6(void);
void ch7_7(void);
void ch7_8(void);
void ch7_10(void);
void ch7_11(void);

int main(void) {
    //ch7_1();
    //ch7_2();
    //ch7_3();
    ch7_4();
    //ch7_5();
    //ch7_6();
    //ch7_7();
    //ch7_8();
    //ch7_10();
    //ch7_11();

    return 0;
}

void ch7_1(void) {
    char ch;
    int blank_nums = 0, lf_nums = 0, other_nums = 0;

    while ((ch = getchar()) != '#') {
        if (ch == ' ') {
            blank_nums++;
        } else if (ch == '\n') {
            lf_nums++;
        } else {
            other_nums++;
        }
    }
    printf("blank_nums: %d, lf_nums: %d, other_nums: %d\n", blank_nums, lf_nums, other_nums);
}

void ch7_2() {
    char ch;
    int n = 1;

    while ((ch = getchar()) != '#') {
        printf("%c-%3d ", ch, ch);
        if (n % 8 == 0) {
            putchar('\n');
            n = 1;
        } else {
            n++;
        }
    }
}

void ch7_3() {
    int num, even_nums, odd_nums, even_sum, odd_sum;

    even_nums = odd_nums = even_sum = odd_sum = 0;
    while(scanf("%d", &num) == 1) {
        if (num == 0) {
            break;
        } else if (num % 2 == 0) {
            even_nums++;
            even_sum += num;
        } else {
            odd_nums++;
            odd_sum += num;
        }
    }
    if (even_nums > 0) {
        printf("even_nums: %2d, sum/nums: %10.2f\n", even_nums, 1.0 * even_sum / even_nums);
    }
    if (odd_nums > 0) {
        printf(" odd_nums: %2d, sum/nums: %10.2f\n", odd_nums, 1.0 * odd_sum / odd_nums);
    }
}

void ch7_4() {
    char ch;

    while ((ch = getchar()) != '#') {
        putchar(ch);
    }    
}

void ch7_5() {
    int line, i, j, k, c;
    char ch;

    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') { 
        line = ch - 'A' + 1;
        for (i=1; i<=line; i++) {
            for (j=line; j>i; j--) {
                printf(" ");
            }
            for (k=1, c='A'; k<=i; k++, c++) {
                printf("%c", c);
            }
            for (k=i, c='A'+i-2; k>1; k--, c--) {
                printf("%c", c);
            }
            printf("\n");
        }
    }
}

void ch7_6() {
    int i, j, x, ok;

    ok = scanf("%d %d", &i, &j);
    if (ok == 2 && i < j) {
        printf("   x   x2   x3\n");
        for (x=i; x<=j; x++) {
            printf("%4d %4d %4d\n", x, x*x, x*x*x);
        }
    }
}

void ch7_7() {
    int length;
    char word[30];

    scanf("%s", word);
    length = strlen(word);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}

void ch7_8() {
    float x, y;

    while(scanf("%f%f", &x, &y)) {
        printf("(x-y)/(x*y): %lf\n", (x-y)/(x*y));
    }
}

void ch7_10() {
    float x, y, sum;

    scanf("%f%f", &x, &y);
    while(y > x) {
        sum = 0;
        for (int i=x; i<=y; i++) {
            sum += i * i;
        }
        printf("The sums of the squares: %lf\n", sum);
        scanf("%f%f", &x, &y);
    }
}

void ch7_11(void) {
    int i, j, nums[8];

    //printf("length: %d", sizeof(nums));
    for (i = 0, j = 8; i < j; i++) {
        scanf(" %d", &nums[i]);
    }
    for (i=8-1; i>=0; i--) {
        printf("%d ", nums[i]);
    }
}