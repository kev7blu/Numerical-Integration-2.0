#include <stdio.h>

typedef double (*dfunc)(double);

double func(double x) { return 4.0 / (x*x + 1.0); }

double gaussquad(double a, double b, dfunc f, double w[], double x[], int n)
{
    double total = 0.0;
    double y = (b - a)/ 2.0;
    double u = (a + b)/ 2.0;
    
    for (int i = 0; i < n; i++)
    {
        //total = total + (w4[i])*(4.0/((y*x4[i]*u*y*x4[i]*u)+1.0)); 
         total = total + (w[i])*f(y*x[i]+u); 
    }
    total = total * y;
    
    return total;
}

double gaussquad4(double a, double b, dfunc f)
{
    double x4[4] = {0.339981, -0.339981, 0.861136, -0.861136};
    double w4[4] = {0.652145, 0.652145, 0.347855, 0.347855};
    return gaussquad(a, b, f, w4, x4, 4);
}

double gaussquad5(double a, double b, dfunc f) 
{
    double x5[5] = {0, 0.538469, -0.538469, 0.90618, -0.90618};
    double w5[5] = {0.568889, 0.478629, 0.478629, 0.236927, 0.236927};
   return gaussquad(a, b, f, w5, x5, 5);
}

double gaussquad20(double a, double b, dfunc f)
{
    
    double w20 [20] = {0.1527533871307258, 0.1527533871307258,0.1491729864726037,0.1491729864726037,0.1420961093183820, 0.1420961093183820,
        0.1316886384491766,0.1316886384491766,0.1181945319615184,0.1181945319615184,0.1019301198172404,0.1019301198172404,0.0832767415767048,
      0.0832767415767048,  0.0626720483341091,0.0626720483341091,0.0406014298003869,0.0406014298003869,0.0176140071391521,0.0176140071391521,};
    double x20 [20] = {-0.0765265211334973, 0.0765265211334973, -0.2277858511416451,0.2277858511416451,-0.3737060887154195,0.3737060887154195,
    -0.5108670019508271,0.5108670019508271,-0.6360536807265150,0.6360536807265150,-0.7463319064601508,0.7463319064601508,-0.8391169718222188,
0.8391169718222188,-0.9122344282513259,0.9122344282513259,-0.9639719272779138,0.9639719272779138,-0.9931285991850949,0.9931285991850949};
    return gaussquad(a,b, f, w20, x20, 20);
}

int main()
{
    printf("the integral of gaussquad4 is %.12lf\n", gaussquad4(0.0, 1.0, func));
    printf("the integral of gaussquad5 is %.12lf\n", gaussquad5(0.0, 1.0, func));
    printf("the integral of gaussquad20 is %.12lf\n", gaussquad20(0.0, 1.0, func));
    
    return 0;
}

/*
double func(double x)
{
    return 4.0/(1.0 + x*x);
}

double intergrate (double a, double b, long int n)
{
    double area = 0.0;
    double dx = (b - a) / n;
    for( int i = 0; i < n; i++)
    {
        double xi = a + i * dx;
        double fx = func(xi);
        area = area + fx;
    }
    area = area * dx;
    return area;
}

int main()
{
    double area = intergrate (0.0 , 1.0, 100000);
    printf("result is %lf\n",   area);
    
    return 0;
}

/*
*************************************
output is 

100,000 iterations are required to get a better answer than gaussquad4
10,000,000 iterations are required to get a better answer than gaussquad5
*/

