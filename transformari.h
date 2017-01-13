#include <cstring>
#include <iomanip>
#include <math.h>
#include <stdio.h>


long double trans_char_float(char x[])
{
    char *p = x, *q = strchr(x, '.');
    if(x[0]=='-')
        p++;
    long double a = 0, k = 0.1, b = 0;
    while(p != q && *p != '\0')
    {
        a = a* 10 + *p - '0';
        p++;
    }

    if(!q)
    {
        if(x[0]=='-')
            return -a;
        return a;
    }

    ++q;
    while(*q != '\0')
    {
        b = *q - '0';
        a = a + b * k;
        k /= 10;
        ++q;
    }
    if(x[0]=='-')
        return -a;
    return a;

}

char trans_lungime(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=0.01*f;
        break;
    case 1 :
        f=0.3048*f;
        break;
    case 2 :
        f=0.0254*f;
        break;
    case 3 :
        f=1000*f;
        break;
    case 4 :
        f=1*f;
        break;
    case 5 :
        f=1609.344*f;
        break;
    case 6 :
        f=0.001*f;
        break;
    case 7 :
        f=1852*f;
        break;
    case 8 :
        f=0.9144002494*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=100*f;
        break;
    case 1 :
        f=3.280839895013123*f;
        break;
    case 2 :
        f=39.37007874015748*f;
        break;
    case 3 :
        f=0.001*f;
        break;
    case 4 :
        f=1*f;
        break;
    case 5 :
        f=0.0006213711922373339*f;
        break;
    case 6 :
        f=1000*f;
        break;
    case 7 :
        f=0.0005399568034557236*f;
        break;
    case 8 :
        f=1.0936130000578717*f;
        break;
    }
    sprintf(y, "%lf", f);


}
char trans_arie(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=100*f;
        break;
    case 1 :
        f=4046.856119*f;
        break;
    case 2 :
        f=0.0001*f;
        break;
    case 3 :
        f=0.0929*f;
        break;
    case 4 :
        f=10000*f;
        break;
    case 5 :
        f=0.0006452*f;
        break;
    case 6 :
        f=1000000*f;
        break;
    case 7 :
        f=1*f;
        break;
    case 8 :
        f=0.000001*f;
        break;
    case 9 :
        f=0.836127816*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=0.01*f;
        break;
    case 1 :
        f=0.00024710539999309525*f;
        break;
    case 2 :
        f=10000*f;
        break;
    case 3 :
        f=10.764262648008613*f;
        break;
    case 4 :
        f=0.0001*f;
        break;
    case 5 :
        f=1549.9070055796653*f;
        break;
    case 6 :
        f=0.000001*f;
        break;
    case 7 :
        f=1*f;
        break;
    case 8 :
        f=1000000*f;
        break;
    case 9 :
        f=1.195989394042597*f;
        break;
    }
    sprintf(y, "%lf", f);


}

char trans_volum(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=0.00001*f;
        break;
    case 1 :
        f=0.000001*f;
        break;
    case 2 :
        f=0.0001*f;
        break;
    case 3 :
        f=0.001*f;
        break;
    case 4 :
        f=0.02832*f;
        break;
    case 5 :
        f=0.004546*f;
        break;
    case 6 :
        f=0.003785*f;
        break;
    case 7 :
        f=0.000016387064*f;
        break;
    case 8 :
        f=0.001*f;
        break;
    case 9 :
        f=1*f;
        break;
    case 10 :
        f=0.000001*f;
        break;
    case 11 :
        f=0.764554858*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=100000*f;
        break;
    case 1 :
        f=1000000*f;
        break;
    case 2 :
        f=10000*f;
        break;
    case 3 :
        f=1000*f;
        break;
    case 4 :
        f=35.3146667*f;
        break;
    case 5 :
        f=219.969157*f;
        break;
    case 6 :
        f=264.172052*f;
        break;
    case 7 :
        f=61023.7441*f;
        break;
    case 8 :
        f=1000*f;
        break;
    case 9 :
        f=1*f;
        break;
    case 10:
        f=1000000*f;
        break;
    case 11:
        f=1.30795062*f;
        break;
    }
    sprintf(y, "%lf", f);


}
char trans_timp(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=f/3600;
        break;
    case 1 :
        f=f/60;
        break;
    case 2 :
        f=1*f;
        break;
    case 3 :
        f=24*f;
        break;
    case 4 :
        f=168*f;
        break;
    case 5 :
        f=5208*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=3600*f;
        break;
    case 1 :
        f=60*f;
        break;
    case 2 :
        f=1*f;
        break;
    case 3 :
        f=f/24;
        break;
    case 4 :
        f=f/168;
        break;
    case 5 :
        f=f/5208;
        break;
    }
    sprintf(y, "%lf", f);
}
char trans_viteza(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=0.0001666667*f;
        break;
    case 1 :
        f=0.01*f;
        break;
    case 2 :
        f=0.000084667*f;
        break;
    case 3 :
        f=0.00508*f;
        break;
    case 4 :
        f=0.3048*f;
        break;
    case 5 :
        f=0.0254*f;
        break;
    case 6 :
        f=0.27777778*f;
        break;
    case 7 :
        f=16.666667*f;
        break;
    case 8 :
        f=1000*f;
        break;
    case 9 :
        f=0.000277778*f;
        break;
    case 10 :
        f=0.016666667*f;
        break;
    case 11 :
        f=1*f;
        break;
    case 12 :
        f=1609.344*f;
        break;
    case 13 :
        f=26.8224*f;
        break;
    case 14 :
        f=0.44704*f;
        break;
    case 15 :
        f=0.5144*f;
        break;
    case 16 :
        f=0.000254*f;
        break;
    case 17 :
        f=0.015240004*f;
        break;
    case 18 :
        f=0.9144002494*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=6000*f;
        break;
    case 1 :
        f=100*f;
        break;
    case 2 :
        f=11810.9771221 *f;
        break;
    case 3 :
        f=196.8503937*f;
        break;
    case 4 :
        f=3.28083*f;
        break;
    case 5 :
        f=39.3700787*f;
        break;
    case 6 :
        f=3.6*f;
        break;
    case 7 :
        f=0.06*f;
        break;
    case 8 :
        f=0.001*f;
        break;
    case 9 :
        f=3600*f;
        break;
    case 10 :
        f=60*f;
        break;
    case 11 :
        f=1*f;
        break;
    case 12 :
        f=0.000621371192*f;
        break;
    case 13 :
        f=0.03728227153424004*f;
        break;
    case 14 :
        f=2.2369362920 *f;
        break;
    case 15 :
        f=1.94384449*f;
        break;
    case 16 :
        f=11810.9771221*f;
        break;
    case 17 :
        f=196.8503937*f;
        break;
    case 18 :
        f=3.28083*f;
        break;
    }
    sprintf(y, "%lf", f);
}

char trans_temperatura(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=1*f;
        break;
    case 1 :
        f=(f-32)/1.8;
        break;
    case 2 :
        f=f-273.15;
        break;
    case 3 :
        f=(f - 491.67) * 5/9;
        break;
    }

    switch (j)
    {
    case 0 :
        f=1*f;
        break;
    case 1 :
        f=f*1.8 + 32;
        break;
    case 2 :
        f=f+273.15;
        break;
    case 3 :
        f=(f + 273.15) * 1.8;
        break;

    }
    sprintf(y, "%lf", f);
}

char trans_masa(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=0.001*f;
        break;
    case 1 :
        f=1*f;
        break;
    case 2 :
        f=0.453592*f;
        break;
    case 3 :
        f=1000*f;
        break;
    case 4 :
        f=0.0283495*f;
        break;
    case 5 :
        f=0.0311035*f;
        break;
    case 6 :
        f=14.593903*f;
        break;
    case 7 :
        f=1000*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=1000*f;
        break;
    case 1 :
        f=1*f;
        break;
    case 2 :
        f=2.20462*f;
        break;
    case 3 :
        f=1000000*f;
        break;
    case 4 :
        f=35.27399072*f;
        break;
    case 5 :
        f=32.15072259*f;
        break;
    case 6 :
        f=0.068521765*f;
        break;
    case 7 :
        f=0.001*f;
        break;
    }
    sprintf(y, "%lf", f);
}

char trans_energie(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=1055.0551*f;
        break;
    case 1 :
        f=1054.3495*f;
        break;
    case 2 :
        f=4186.7967*f;
        break;
    case 3 :
        f=4.184*f;
        break;
    case 4 :
        f=1*f;
        break;
    case 5 :
        f=1*f;
        break;
    case 6 :
        f=3599.9971*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=0.0009*f;
        break;
    case 1 :
        f=0.0009*f;
        break;
    case 2 :
        f=0.0002*f;
        break;
    case 3 :
        f=0.239*f;
        break;
    case 4 :
        f=1*f;
        break;
    case 5 :
        f=1*f;
        break;
    case 6 :
        f=0.0003*f;
        break;
    }
    sprintf(y, "%lf", f);
}

char trans_presiune(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=98066.5*f;
        break;
    case 1 :
        f=101325.2738*f;
        break;
    case 2 :
        f=98000*f;
        break;
    case 3 :
        f=248.84*f;
        break;
    case 4 :
        f=3386.38815789*f;
        break;
    case 5 :
        f=98000*f;
        break;
    case 6 :
        f=1000*f;
        break;
    case 7 :
        f=47.88*f;
        break;
    case 8 :
        f=98*f;
        break;
    case 9 :
        f=9800*f;
        break;
    case 10 :
        f=9800*f;
        break;
    case 11 :
        f=9.8*f;
        break;
    case 12 :
        f=133.322368421*f;
        break;
    case 13 :
        f=1000000*f;
        break;
    case 14 :
        f=1000000*f;
        break;
    case 15 :
        f=1*f;
        break;
    case 16 :
        f=6894.75729317*f;
        break;
    case 17 :
        f=133.322368421*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=0.000010197162129779282*f;
        break;
    case 1 :
        f=0.000009869205998632101*f;
        break;
    case 2 :
        f=0.000010204081632653061 *f;
        break;
    case 3 :
        f=0.0040186465198521135*f;
        break;
    case 4 :
        f=0.00029529987508079483*f;
        break;
    case 5 :
        f=0.000010204081632653061*f;
        break;
    case 6 :
        f=0.001*f;
        break;
    case 7 :
        f=0.020885547201336674*f;
        break;
    case 8 :
        f=0.01020408163265306*f;
        break;
    case 9 :
        f=0.00010204081632653062*f;
        break;
    case 10 :
        f=0.00010204081632653062*f;
        break;
    case 11 :
        f=0.1020408163265306*f;
        break;
    case 12 :
        f=0.007500616827044659*f;
        break;
    case 13 :
        f=0.000001*f;
        break;
    case 14 :
        f=0.000001 *f;
        break;
    case 15 :
        f=1*f;
        break;
    case 16 :
        f=0.00014503773773017476*f;
        break;
    case 17 :
        f=0.007500616827044659*f;
        break;
    }
    sprintf(y, "%lf", f);
}

char trans_densitate(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=1000*f;
        break;
    case 1 :
        f=1*f;
        break;
    case 2 :
        f=0.001*f;
        break;
    case 3 :
        f=1000*f;
        break;
    case 4 :
        f=1000000*f;
        break;
    case 5 :
        f=1000000*f;
        break;
    case 6 :
        f=1000*f;
        break;
    case 7 :
        f=1*f;
        break;
    case 8 :
        f=16.017940092904052*f;
        break;
    case 9 :
        f=27679.89858*f;
        break;
    case 10 :
        f=99.77637266*f;
        break;
    case 11 :
        f=119.8264273*f;
        break;
    case 12 :
        f=1*f;
        break;
    case 13 :
        f=0.001*f;
        break;
    case 14 :
        f=0.000001*f;
        break;
    case 15 :
        f=6.236023291*f;
        break;
    case 16 :
        f=7.489150094*f;
        break;
    case 17 :
        f=1.001153961*f;
        break;
    case 18 :
        f=1729.994044*f;
        break;
    case 19 :
        f=1000*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=0.001*f;
        break;
    case 1 :
        f=1*f;
        break;
    case 2 :
        f=1000 *f;
        break;
    case 3 :
        f=0.001*f;
        break;
    case 4 :
        f=0.000001*f;
        break;
    case 5 :
        f=0.000001*f;
        break;
    case 6 :
        f=0.001*f;
        break;
    case 7 :
        f=1*f;
        break;
    case 8 :
        f=0.06243*f;
        break;
    case 9 :
        f=0.00003612730000111149*f;
        break;
    case 10 :
        f=0.010022412855272063*f;
        break;
    case 11 :
        f=0.00834540445319611*f;
        break;
    case 12 :
        f=1*f;
        break;
    case 13 :
        f=1000*f;
        break;
    case 14 :
        f=1000000 *f;
        break;
    case 15 :
        f=0.16035860569078172*f;
        break;
    case 16 :
        f=0.13352649999646274*f;
        break;
    case 17 :
        f=0.9988473690911163*f;
        break;
    case 18 :
        f=0.0005780366721308782*f;
        break;
    case 19 :
        f=0.001*f;
        break;
    }
    sprintf(y, "%lf", f);
}

char trans_consum(char x[256],char y[256],int i,int j)
{
    long double f=trans_char_float(x);

    switch (i)
    {
    case 0 :
        f=1*f;
        break;
    case 1 :
        f=100/f;
        break;
    case 2 :
        f=235.21/f;
        break;
    case 3 :
        f=2.352*f;
        break;
    case 4 :
        f=62.14/f;
        break;
    case 5 :
        f=0.6214*f;
        break;
    }

    switch (j)
    {
    case 0 :
        f=1*f;
        break;
    case 1 :
        f=100/f;
        break;
    case 2 :
        f=235.21/f;
        break;
    case 3 :
        f=0.4251*f;
        break;
    case 4 :
        f=62.14/f;
        break;
    case 5 :
        f=1.609*f;
        break;
    }
    sprintf(y, "%lf", f);
}
