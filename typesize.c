/* typesize.c -- 打印类型字节大小 */
#include <stdio.h>
int main(void)
{
    printf(" %12s %12s %12s %12s\n %12d %12d %12d %12d\n", 
            "int", "unsigned", "char", "_Bool",
            sizeof(int), sizeof(unsigned), sizeof(char), sizeof(_Bool));
    printf(" %12s %12s %12s\n %12d %12d %12d\n\n", 
            "short", "long", "long long", 
            sizeof(short), sizeof(long), sizeof(long long));

    printf(" %12s %12s %12s\n %12d %12d %12d\n\n", 
            "float", "double", "long double", 
            sizeof(float), sizeof(double), sizeof(long double));

    printf(" %12s %12s %12s %12s\n %12d %12d %12d %12d\n", 
            "1", "1.0", "\'a\'", "abcdefg",
            sizeof(1), sizeof(1.0), sizeof('a'), sizeof("abcdefg"));
    /*
    printf("int: %u\n", sizeof(int));
    printf("unsigned: %u\n", sizeof(unsigned));
    printf("char: %u\n", sizeof(char));
    printf("_Bool: %u\n", sizeof(_Bool));
    printf("short: %u\n", sizeof(short));
    printf("long: %u\n", sizeof(long));
    printf("long long: %u\n\n", sizeof(long long));

    printf("float: %u\n", sizeof(float));
    printf("double: %u\n", sizeof(double));
    printf("long double: %u\n\n", sizeof(long double));

    printf("1: %u\n", sizeof(1));
    printf("1.0: %u\n", sizeof(1.0));
    printf("\'a\': %u\n", sizeof('a'));
    printf("\"abc\": %u\n", sizeof("abcdefg"));
    */
}