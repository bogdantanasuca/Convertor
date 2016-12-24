#include <cstring>
#include <iomanip>
#include <math.h>
#include <stdio.h>


long double trans_char_float(char x[])
{
    char *p = x, *q = strchr(x, '.');
    long double a = 0, k = 0.1, b = 0;
    while(p != q && *p != '\0')
    {
        a = a* 10 + *p - '0';
        p++;
    }

    if(!q)
    {
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

   return a;

}

char trans_lungime(char x[256],char y[256],int i,int j)
{
    long double f;

    f=trans_char_float(x);
    switch (i ){
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

    switch (j ) {
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
    sprintf(y , "%lf" , f);
    std::cout<<y<<std::endl;

}


