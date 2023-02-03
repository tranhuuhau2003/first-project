//sua bai kt giua ki
int Xn(int n)
{
    int X[1000];
    X[0]=0;
    X[1]=1;
    for (int i=2; i<=n; i++)
    {
        s=0;
        for(int j=1; j<=i-1; j++)
        {
            s=s+X[j];
        }
        X[i]=i+s;
    }
    return X[n];
}