#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, amt, num, min, max;
	char currentHeading;
	char buff[50]={}, inName[50]={}, outName[50]={};

	srand(time(0));

	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.sol", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

        //amt = (rand() * rand()) % 1000001;
        printf("Enter amt: ");
        scanf("%d", &amt);

        fprintf(fileIn, "%d\n", amt);

        currentHeading = 'N';

        for(j = 0; j < amt; j++)
        {
            num = rand() % 4;
            fprintf(fileIn, "%c\n", num + 'A');

            //A does nothing
            //B (turn right)
            if(num == 1)
            {
                switch(currentHeading)
                {
                    case 'N': currentHeading = 'E'; break;
                    case 'E': currentHeading = 'S'; break;
                    case 'S': currentHeading = 'W'; break;
                    case 'W': currentHeading = 'N'; break;
                }
            }
            //C (turn left)
            else if(num == 2)
            {
                switch(currentHeading)
                {
                    case 'N': currentHeading = 'W'; break;
                    case 'W': currentHeading = 'S'; break;
                    case 'S': currentHeading = 'E'; break;
                    case 'E': currentHeading = 'N'; break;
                }
            }
            //D (turn 180 deg)
            else if(num == 3)
            {
                switch(currentHeading)
                {
                    case 'N': currentHeading = 'S'; break;
                    case 'S': currentHeading = 'N'; break;
                    case 'W': currentHeading = 'E'; break;
                    case 'E': currentHeading = 'W'; break;
                }
            }
        }

        fprintf(fileOut, "%c", currentHeading);

		fclose(fileIn);
		fclose(fileOut);
	}
}
