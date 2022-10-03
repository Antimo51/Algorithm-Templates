#include<bits/stdc++.h>
using namespace std;
#define in Read()

int in{
    int i=0,f=1; char ch=0;
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') f=-1, ch=getchar();
    while('0'<=ch&&ch<='9') i=(i<<1)+(i<<3)+ch-48, ch=getchar();
    return i*f;
}

const int N=501;
int a[N][N],b[N][N],c[N][N];

int main(){

    freopen("1.in","r",stdin);

    int an,am,bn,bm;
    an=in,am=in;
    for(int i=1;i<=an;++i)
        for(int j=1;j<=am;++j)
            a[i][j]=in;
    bn=in,bm=in;
    for(int i=1;i<=bn;++i)
        for(int j=1;j<=bm;++j)
            b[i][j]=in;
    for(int i=1;i<=an;++i)
        for(int j=1;j<=bm;++j)
            for(int k=1;k<=am;++k)
                c[i][j]+=a[i][k]*b[k][j];
    for(int i=1;i<=an;++i){
        for(int j=1;j<=bm;++j)
            printf("%d ",c[i][j]);
        puts("");
    }
    return 0;
    
}