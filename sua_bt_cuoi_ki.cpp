// on tap cuoi hc ki
// file va mang hai chieu

//doc ghi file
void read(FILE *f, int **&A, int &m, int &n)
{
    fsacnf(f, %d, &m, &n);
    A=new int*[m];
    for(int i=0; i<m; i++)
    {
        A[i]=new int[n];
    }
    for(int i =0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(f, "%d", &A[i][j]);
        }
    }
}


// tinh tong cac phan tu tren moi dong
void caub(FILE *f, int **A, int m, int n)
{
    int i, j;
    for(i=0; i<m; i++)
    {
        int sum =0;
        for(j=0; j<n; j++)
        {
            sum+=A[i][j];
        }
        fprintf(f, "ld", sum);
    }
    fprintf(f, "\n");
}

//cau c
int maxdong(int **A, int m, int n, int i)
{
    int l=A[i][0];
    for(int j=1; j<n; j++)
    {
        if(A[i][j] > l)
        {
            l=A[i][j];
        }
    }
    return l;
}


void cauc(int **A, int m, int n, int **&C)
{
    C=new int *[m];
    for(int i =0; i<m; i++)
    {
        C[i]=new int [n];
    }
    for(int i=0; i<m; i++)
    {
        int k=maxdong(A, m, n, i);
        for(int j=0; j<n; j++)
        {
            C[i][j]=A[i][j]*k;
        }
    }
}


//cau d
void caud(int **A, int m, int n, int **&D)
{
    D=new int *[m];
    for(int i =0; i<m; i++)
    {
        D[i] new int[n];
    }
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int S=timS(A, m, n, i, j);
            if(ktsnt(A[i][j]))
            {
                D[i][j] = A[i][j] * s;
            }
            else
            {
                D[i][j] = A[i][j] *S-1;
            }
        }
    }
}

int timS(int **A, int m, int n, int i, int j)
{
    int S=0;
    for(int k=0; k<n; k++)
    {
        if(ktsnt(A[i][k]))
        {
            S++;
        }
    }
    for (int t=0; t<m; t++)
    {
        if(ktsnt(A[t][j]))
        {
            S++;
        }
    }
    if(ktsnt(A[i][j]))
    {
        S--;
    }
    return S;
}


int main()
{
    FILE *f, *g;
    f=fopen("fest.txt", "r");
    if (f==NULL)
    {
        return;
    }
    int **A;
    int m, n;
    read(f, A, m, n);
    g=fopen("output.txt", "w");
    caub(g, A, m, n);
    int **C;
    cauc(A, m, n, C);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fprintf(g, "%d", C[i][j]);
        }

    }
}

