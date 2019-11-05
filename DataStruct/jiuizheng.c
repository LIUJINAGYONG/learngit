#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A 1000
#define B 0
#define PI 3.141529
int main(void)
{

    int i;
    int *b = NULL;
    
   int s[500];
    
    int count = 128;
    //short s[500];
    for (i = 0; i < 128; i++)
    {
        *b = (A*sin(PI / 64.00 * i + B));

        b++;
        printf("输出值%d：%d\n",i,s[i]);
    }
 
     return 0;

    //buf = s;
}