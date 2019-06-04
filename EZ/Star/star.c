#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, k, num;
	char buff[50]={}, inName[50]={}, outName[50]={};

	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.out", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

		num = (rand() * rand()) % 1001;

		fprintf(fileIn, "%d", num);

        for(j = 1; j <= num; j++)
        {
            for(k = 1; k <= j; k++)
            {
                fprintf(fileOut, "*");
            }

            fprintf(fileOut, "\n");
        }

		fclose(fileIn);
		fclose(fileOut);
	}
}
