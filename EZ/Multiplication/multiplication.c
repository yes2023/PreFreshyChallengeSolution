#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, num;
	char buff[50]={}, inName[50]={}, outName[50]={};
    srand(time(NULL));
	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.out", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");


		num = (rand() * rand()) % 100001;

		fprintf(fileIn, "%d", num);

        for(j = 1; j <= 12; j++)
        {
            fprintf(fileOut, "%d x %d = %d\n", num, j, num * j);
        }

		fclose(fileIn);
		fclose(fileOut);
	}
}
