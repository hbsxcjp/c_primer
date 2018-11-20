#include <stdio.h>
#include <string.h>
#include <limits.h>

void ch6_1(void);
void ch6_2(int n);
void ch6_3(char ch);
void ch6_4(char ch);
void ch6_5(void);
void ch6_6(void);
void ch6_7(void);
void ch6_8(void);
void ch6_10(void);
void ch6_11(void);
void ch6_12(void);
void ch6_13(void);
void ch6_14(void);
void ch6_15(void);
void ch6_16(void);
void ch6_17(void);
void ch6_18(void);

int main(void) {
    ch6_1();
    ch6_2(5);
    ch6_3('F');
    ch6_4('U');
    ch6_5();
    ch6_6();
    ch6_7();
    ch6_8();
    ch6_10();
    ch6_11();
    ch6_12();
    ch6_13();
    ch6_14();
    ch6_15();
    ch6_16();
    ch6_17();
    ch6_18();
}

void ch6_1(void) {
    char chs[26];

    for (int i=0; i<26; i++) {
        chs[i] = 'a' + i;
    }

    for (int i=0; i<26; i++) {
        printf("%c ", chs[i]);
    }
    printf("\n");
}

void ch6_2(int n) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            printf("$");
        }        
        printf("\n");
    }
}

void ch6_3(char ch) {
    int x;

    x = ch - 'A';
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=i; j++) {
            printf("%c", ch - j);
        }
        printf("\n");
    }
}

void ch6_4(char ch) {
    int line = 1;
    int x = 'A';
    
    while(x <= ch){
        for (int i=1; i<=line; i++, x++) {
            printf("%c", x);
        }
        printf("\n");
        line++;
    }
    
}

void ch6_5() {
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

void ch6_6() {
    int i, j, x, ok;

    ok = scanf("%d %d", &i, &j);
    if (ok == 2 && i < j) {
        printf("   x   x2   x3\n");
        for (x=i; x<=j; x++) {
            printf("%4d %4d %4d\n", x, x*x, x*x*x);
        }
    }
}

void ch6_7() {
    int length;
    char word[30];

    scanf("%s", word);
    length = strlen(word);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}

void ch6_8() {
    float x, y;

    while(scanf("%f%f", &x, &y)) {
        printf("(x-y)/(x*y): %lf\n", (x-y)/(x*y));
    }
}

void ch6_10() {
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

void ch6_11(void) {
    int i, j, nums[8];

    printf("length: %d", sizeof(nums));
    for (i = 0, j = 8; i < j; i++) {
        scanf(" %d", &nums[i]);
    }
    for (i=8-1; i>=0; i--) {
        printf("%d ", nums[i]);
    }
}

void ch6_12() {
    int x;
    double symbol;
    double sum;

    while (scanf("%d", &x), x > 0) {
        sum = 0;
        for (int i=1; i<=x; i++) {
            sum += 1.0/i;
        }
        printf("sum1: %lf\n", sum);
        
        sum = 0;
        for (int i=1; i<=x; i++) {
            symbol = (i % 2 == 1) ? 1.0 : -1.0;
            sum += symbol / i;
        }
        printf("sum2: %lf\n", sum); 
    }
}

void ch6_13() {
    int length = 32;
    int array[length];
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %d\n", UCHAR_MAX);
    printf("USHRT_MAX: %d\n", USHRT_MAX);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %d\n", UINT_MAX);
    printf("LONG_MAX: %ld\n", LONG_MAX);
    printf("ULONG_MAX: %ld\n", ULONG_MAX);
    printf("LLONG_MAX: %ld\n", LLONG_MAX);
    printf("ULLONG_MAX: %lld\n", ULLONG_MAX);

    for (int i=0; i<length; i++) {
        array[i] = 1;
        for (int j=0; j<=i; j++) {
            array[i] *= 2;
        }
    }

    int i = 0;
    do {
        printf(" %d", array[i]);
        i++;
    } while(i < length);
}

void ch6_14() {
    double first[8], second[8];

    for (int i=0; i<8; i++) {
        scanf("%lf", &first[i]);
    }
    second[0] = first[0];
    for (int i=1; i<8; i++) {
        second[i] = second[i-1] + first[i];
    }

    for (int i=0; i<8; i++) {
        printf("%6.2lf", first[i]);
    }
    printf("\n");
    for (int i=0; i<8; i++) {
        printf("%6.2lf", second[i]);
    }
}

void ch6_15() {
    char line[255];

    scanf("%255s", line);
    for (int i=strlen(line)-1; i>=0; i--) {
        printf("%c", line[i]);
    }
    printf("\n");
}

void ch6_16() {
    int n = 0;
    double dap = 100;
    double dei = 100;

    while (dei <= dap) {
        n++;
        dap += 100 * 0.1;
        dei *= 1.05;
        printf("n: %3d, dap: %.2lf, dei: %.2lf\n", n, dap, dei);
    }
    printf("n: %d, dap: %.2lf, dei: %.2lf\n", n, dap, dei);
}

void ch6_17() {
    int n = 0;
    double money = 1000000.0;

    while (money > 100000.0) {
        n++;
        money *= 1.08;
        printf("n: %3d, first: %10.2lf ", n, money);
        money -= 100000.0;
        printf("last: %10.2lf\n", money);
    }
    printf("n: %3d, last: %10.2lf\n", ++n, money);
}

void ch6_18() {
    int weeks = 0;
    int friend_nums = 5;

    while (friend_nums <= 150) {
        weeks++;
        friend_nums -= weeks;
        friend_nums *= 2;
        printf("weeks: %3d, friend_nums: %3d\n", weeks, friend_nums);
    }
}