#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char buff[50]={}, inName[50]={}, outName[50]={};
long long int data[1005][1005]={}, qsum[1005][1005]={};

int main()
{
	FILE * fileIn;
	FILE * fileOut;
	int i, j, k;
	long long int a, b, m, n, temp, maxsum, maxM, maxN;

    srand(time(0));

	for(i = 1; i <= 10; i++)
	{
		sprintf(inName, "%d.in", i);
		sprintf(outName, "%d.out", i);

		fileIn = fopen(inName, "w");
		fileOut = fopen(outName, "w");

        printf("Testcase %d:\n", i);
		printf("Enter m, n, a, b: ");
		scanf("%lld %lld %lld %lld", &m, &n, &a, &b);

		fprintf(fileIn, "%lld %lld %lld %lld\n", m, n, a, b);
        printf("Approx. calculation: %lld\n", (a*b) * (m-a+1) * (n-b+1));

        maxsum = 0;

        //generate data
        for(j = 1; j <= m; j++)
        {
            for(k = 1; k <= n; k++)
            {
                data[j][k] = rand() % 10001;
                fprintf(fileIn, "%lld ", data[j][k]);
            }
            fprintf(fileIn, "\n");
        }

        //generate qsum table
        for(j = 1; j <= m; j++)
        {
            for(k = 1; k <= n ; k++)
            {
                qsum[j][k] = data[j][k] + qsum[j-1][k] + qsum[j][k-1] - qsum[j-1][k-1];
            }
        }

        //find max sum
        for(j = a; j <= m; j++)
        {
            for(k = b; k <= n ; k++)
            {
                temp = qsum[j][k] - qsum[j-a][k] - qsum[j][k-b] + qsum[j-a][k-b];
                if(temp > maxsum)
                {
                    maxsum = temp;
                    maxM = j-a;
                    maxN = k-b;
                }
            }
        }

        printf("Max sum = %lld at [%lld, %lld]\n", maxsum, maxM, maxN);
        fprintf(fileOut, "%lld\n%lld %lld", maxsum, maxM, maxN);

		fclose(fileIn);
		fclose(fileOut);
	}
}
