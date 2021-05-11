#include "prob.h"

double factora(double m, double n)
{
    double result = 1;

    for (size_t i = 0; i < n && i < m; i++)
    {
        result *= m--;
    }

    return result;
}

double factorc(double m, double n)
{
    if (m < n)
        return 0;
    return factora(m, n) / factora(n, n);
}

//#define MAIN
#ifdef MAIN
int main(int argc, char *argv[])
{
    double m, n;
    if (argc > 2)
    {
        m = atof(argv[1]);
        n = atof(argv[2]);
    }

    if (argc > 2)
    {
        printf("\rA: %g\n", factora(m, n));
        printf("\rC: %g\n", factorc(m, n));
    }
    else
    {
        printf("\rmissing %d number\n", 3 - argc);
    }

    return 0;
}

#undef MAIN
#endif
