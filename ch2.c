#include <stdio.h>
//#include <uchar.h>
#include <wchar.h>

void c1(void);
void c2(void);
void c3(void);
void c6(void);
void platinum(void);

int main(void) 
{
    c1();
    c2();
    c3();
    c6();

    platinum();

    getchar();
    return 0;
}

void c6(void)
{
    int toes;

    toes = 10;
    printf("toes: %d, 2*toes: %d, toes*toes: %d", toes, 2*toes, toes*toes);
}

void c3(void)
{
    printf("My days: %d\n\n", 44 * 365);
}

void c2(void)
{
    printf("My name: %s, address: %s\n\n", "ChenJianPing", "Chang Sha!");
}

void c1(void)
{
    printf("ChenJianPing\n");
    printf("Chen\nJianPing\n");
    printf("Chen");
    printf("JianPing\n\n");
}

void platinum(void) {
    float weight;
    float value;

    wprintf(L"你是谁? \n");
    printf("Let's check. \n");
    printf("Please enter: \n");

    scanf("%f", &weight);
    value = 1700.0 * weight * 14.5833;
    
    printf("Your weight $%0.2f. \n", value);
    printf("... \n");
    printf("... \n");

    //return 0;
}