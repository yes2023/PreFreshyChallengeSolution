#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, amt, num, min, max;
	char buff[50]={}, inName[50]={}, outName[50]={};

	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.out", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

        amt = (rand() * rand()) % 1000001;

        fprintf(fileIn, "%d\n", amt);

        for(j = 0; j < amt; j++)
        {
            num = (rand() * rand()) % 2000001;
            if(j == 0)
            {
                min = num;
                max = num;
            }
            else
            {
                if(num < min)
                    min = num;
                if(num > max)
                    max = num;
            }

            fprintf(fileIn, "%d\n", num);
        }

        fprintf(fileOut, "%d\n%d", min, max);

		fclose(fileIn);
		fclose(fileOut);
	}
}
