#include <stdio.h>

int main()
{
	unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	int i, j;
	
	for(i = 0; i < 8; ++i) 
	{
		for(j = 0; j < 3; j++)
		{
			   printf("%d\t", wins[i][j]);	
		}
		printf("\n");
	}
	
	printf("\nValores de [i][2]\n\n");
	for(i = 0; i < 8; ++i) 
	{
		printf("%d\n", wins[i][2]);
	}
	
	/*
    for(i = 0; i < 8; ++i) 
	{
        printf("\nIndices 1: %d\n", wins[i][0]);
        printf("\n\n");		
		printf("\nIndices 2: %d\n", wins[i][1]);
        printf("\n\n");
        printf("\nIndices 1: %d\n", wins[i][2]);
        printf("\n\n");   
	}
	*/
	return(0);
}