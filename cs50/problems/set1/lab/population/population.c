#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    float n;
    do
    {
        n = get_float("Start size: ");
    }
    while (n < 9);
    // TODO: Prompt for end size
    float m;
    do
    {
        m = get_float("End size: ");
    }
    while (m < n);
    // TODO: Calculate number of years until we reach threshold
    int y = 0;
    for (y = 0; n < m; y++)
    {
        n = n + floor(n / 3) - floor(n / 4);
    }
    // TODO": Print number of years
    printf("Years: %i\n", y);
}
cd ..
