

#include <stdio.h>

int UnSetThirdBit(int num);
int SetThirdBit(int num);

int main(int argv, char* argvc[])
{
    int i = 0x000f;
    int r = UnSetThirdBit(i);

    printf(" 0 ^ 0 = %d\n", 0 ^ 0);
    printf(" 1 ^ 0 = %d\n", 1 ^ 0);
    printf(" 1 ^ 1 = %d\n", 1 ^ 1);

    // printf(" i = %d\nr = %d\n",i,r);
    return (0);
}

int SetThirdBit(int num)
{
    return(num || (1<<2));
}

int UnSetThirdBit(int num)
{
    //return (num & (0xff ^ (1<<2))); // (0xff ^ (1<<2)) == 1111 1111 1111 1011
    return (num & ~(1<<2));
}

int FlipThirdBit(int num)
{
    return (num ^ (1 << 2)); //   num ^ 0000 0000 0000 0100
}