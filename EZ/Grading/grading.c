#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, a, b, c, d, sum;
	char buff[50]={}, inName[50]={}, outName[50]={};

	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.out", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

		a = rand() % 26;
		b = rand() % 26;
		c = rand() % 26;
		d = rand() % 26;

		sum = a + b + c + d;

		fprintf(fileIn, "%d\n%d\n%d\n%d", a, b, c, d);

		if(sum >= 80)
			fprintf(fileOut, "A");
		else if(sum >= 75)
			fprintf(fileOut, "B+");
		else if(sum >= 70)
			fprintf(fileOut, "B");
		else if(sum >= 65)
			fprintf(fileOut, "C+");
		else if(sum >= 60)
			fprintf(fileOut, "C");
		else if(sum >= 55)
			fprintf(fileOut, "D+");
		else if(sum >= 50)
			fprintf(fileOut, "D");
		else
			fprintf(fileOut, "F");

		fclose(fileIn);
		fclose(fileOut);
	}
}
