#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char initOrder[13]={'1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
char currentOrder[13]={};
void swap(int a, int b);

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, amt, num, prev;
	char inName[50]={}, outName[50]={};

	srand(time(0));

	for(i = 1; i <= 20; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.sol", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

        //init cards order
        strcpy(currentOrder, initOrder);

        //amt = (rand() * rand()) % 1000001;
        printf("Enter amt: ");
        scanf("%d", &amt);

        fprintf(fileIn, "%d\n", amt);

        for(j = 0; j < amt; j++)
        {
            //first command cannot be G
            if(j == 0)
                num = rand() % 6;
            else
                num = rand() % 7;

            fprintf(fileIn, "%c\n", num + 'A');

            //use previous command for case G, store current otherwise
            if(num == 6)
                num = prev;
            else
                prev = num;

            switch(num)
            {
                case 0: swap(0, 1); break;
                case 1: swap(1, 2); break;
                case 2: swap(2, 3); break;
                case 3: swap(3, 4); break;
                case 4: swap(4, 5); break;
                case 5: swap(5, 6); break;
            }
        }

        for(j = 0; j < 13; j++)
        {
            if(currentOrder[j] == 'T')
                fprintf(fileOut, "10\n");
            else
                fprintf(fileOut, "%c\n", currentOrder[j]);
        }

		fclose(fileIn);
		fclose(fileOut);
	}

	return 0;
}

void swap(int a, int b)
{
    char temp;

    temp = currentOrder[a];
    currentOrder[a] = currentOrder[b];
    currentOrder[b] = temp;
}
