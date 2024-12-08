
#include <stdio.h>
#include <stdbool.h>

void TF(int num);

int main(int argvc, char *argv[])
{
    int num = 21;
    printf("Result of TF function with num = %d is :\n",num);
    TF(num);
    return (0);
}

void TF(int num)
{
    int i = 1;
    bool devided = false;

    for(i = 0; i < num; ++i)
    {
        devided = false;

        if(0 == i % 3)
        {
            printf("T");
            devided = true;
        }

        if(0 == i %5)
        {
            printf("F");
            devided = true;
        }

        if( !devided)
        {
            printf("%d", i);
        }
        printf(" ");       
    }
    printf("\n"); 
}