

ifstream fin1("lungime.txt");
char lungime[12][12];

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
