

// string revers and lowcase in-place


#include <stdio.h>

void ReversStr(char *str);
void Swape(char *a, char *b);
void ToLower(char* str);
size_t Strlen(char *str);

int main(int argvc, char *argv[])
{
    // char * str = "HelLo wORLd";
    char str[] = "dLROw oLleH";
    ReversStr(str);

    printf("%s\n",str);
    return (0);
}

void ReversStr(char *str)
{
    size_t right = Strlen(str) - 1;
    size_t left = 0;
    
    while(left < right)
    {
        Swape(&str[left], &str[right]);
        ++left;
        --right;
    }
    ToLower(str);
}

void Swape(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void ToLower(char* str)
{
    size_t len = Strlen(str);

    for(int i = 0; i < len; ++i)
    {
        if('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }   
    }
}

size_t Strlen(char *str)
{
    size_t result = 0;

    while('\0' != str[result])
    {
        ++result;
    }
    return (result);
}