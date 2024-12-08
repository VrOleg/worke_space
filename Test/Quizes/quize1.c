
// #include <stdio.c>

// void Main(int argc, char *argv[])
// {
//     int num;
//     const int num2 = 6;
//     const int num3;

//     printf("%d", num);
//     scanf("%d", num);
//     printf("100 divided by %d is %f", num, 100 / num);

//     char ch = 97;
//     num3 = num2 - 5;

//     printf("%f", num3);
//     num = 4.7;
//     (double)num = 4.7;
//     num = 2 * num++;
//     return (0);
// }

#include <stdio.h>

int main(int argc, char *argv[])
{
    int num;
    const int num2 = 6;
    const int num3 = num2 - 5;

    scanf("%d", &num);
    printf("%d\n", num);
    printf("100 divided by %d is %f\n", num, (float)100 / num);

    char ch = 97;
    // num3 = num2 - 5;

    // printf("%f", num3);
    printf("%d\n", num3);
    num = 4.7;
    // (double)num = 4.7;
    num = 2 * num++;


    if(-1 < (unsigned char)1)
    {
        printf("A\n");
    }
    else
    {
        printf("B\n");
    }

    if(-1 < (unsigned int)1)
    {
        printf("A\n");
    }
    else
    {
        printf("B\n");
    }

    return (0);
}