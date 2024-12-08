
#include <stdio.h>
#include <string.h>

int foo(int *data, int size, int value)
{
	// int arr[32];
	int arr[32767 * 3];
	short index;
	for (index = 0; index < size; index++)
	{
		if(index == 32767)
		{
			printf("index = 32767");
		}
		arr[index] = data[index];
	}
	for (index = 0; index < size; index++)
		arr[index] = arr[index] & value;
	data = &arr[0];

	return (0);
}

int main()
{
	int size = 33767 * 3;
	int ar[size];
	
	char* a = "fdalkhfn";
	char* b = "fadh";
	
	if(a.equel())

	for(int i = 0; i < size; ++i)
	{
		ar[i] = i;
	}

	foo(ar, size, 2);
	// printf("%s\n", result);

	
	return 0;
}