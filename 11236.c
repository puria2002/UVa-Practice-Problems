
/*Solution to UVa 11236: Grocery Store */
#include<stdio.h>

int main()
{

    int a, b, c, d;
    for (a = 1; a <= 2000; a++)
    {
        for (b = a; b <= 2000 - a; b++)
        {
            for (c = b; c <= 2000 - a - b; c++)
            {   
                if (a * b * c != 1000000 && (1000000 * (a + b + c)) % (a * b * c  - 1000000) == 0)
                {
                    d = (1000000 * (a + b + c)) / (a * b * c  - 1000000); 
                    if (d >= c && a + b + c + d <= 2000)
                    { 
                        printf("%0.2f %0.2f %0.2f %0.2f\n", a / 100.0, b / 100.0, c / 100.0, d / 100.0);
                    }
                }
            }
        }
    }
}