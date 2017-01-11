

ifstream fin1("lungime.txt");
ifstream fin2("arie.txt");
ifstream fin3("volum.txt");
ifstream fin4("timp.txt");
ifstream fin5("viteza.txt");
ifstream fin6("temperatura.txt");
ifstream fin7("masa.txt");
ifstream fin8("energie.txt");
ifstream fin9("presiune.txt");
ifstream fin10("densitate.txt");
ifstream fin11("consum.txt");

char lungime[12][12];
char arie[12][12];
char volum[13][12];
char timp[12][12];
char viteza[23][12];
char temperatura[4][12];
char masa[9][12];
char energie[8][16];
char presiune[19][12];
char densitate[21][17];
char consum[7][12];



void citire_lungime(char a[12][12])
{
    char x[12];
    int i=0,j;
    while(fin1>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_arie(char a[12][12])
{
    char x[12];
    int i=0,j;
    while(fin2>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_volum(char a[13][12])
{
    char x[12];
    int i=0,j;
    while(fin3>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_timp(char a[12][12])
{
    char x[12];
    int i=0,j;
    while(fin4>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}
void citire_viteza(char a[23][12])
{
    char x[12];
    int i=0,j;
    while(fin5>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_temperatura(char a[4][12])
{
    char x[12];
    int i=0,j;
    while(fin6>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_masa(char a[9][12])
{
    char x[12];
    int i=0,j;
    while(fin7>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}


void citire_energie(char a[8][16])
{
    char x[16];
    int i=0,j;
    while(fin8>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_presiune(char a[19][12])
{
    char x[12];
    int i=0,j;
    while(fin9>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_densitate(char a[21][17])
{
    char x[17];
    int i=0,j;
    while(fin10>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}

void citire_consum(char a[7][12])
{
    char x[12];
    int i=0,j;
    while(fin11>>x)
    {
        j=0;
        while(x[j]!=NULL)
        {
            a[i][j]=x[j];
            j++;
        }
        i++;
    }
}
