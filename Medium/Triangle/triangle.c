#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, k, num;
	char buff[50]={}, inName[50]={}, outName[50]={};

    srand(time(0));

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
            //leading spaces
            for(k = 1; k <= num - j; k++)
                fprintf(fileOut, " ");

            //spacial cases
            if(j == 1)
                fprintf(fileOut, "*");
            else if(j == num)
            {
                for(k = 1; k <= num; k++)
                    fprintf(fileOut, "*");
            }
            //normal cases
            else
            {
            //first star
                fprintf(fileOut, "*");
            //center spaces
                for(k = 1; k <= j - 2; k++)
                    fprintf(fileOut, " ");
            //second star
                fprintf(fileOut, "*");
            }

            fprintf(fileOut, "\n");
        }

		fclose(fileIn);
		fclose(fileOut);
	}
}
