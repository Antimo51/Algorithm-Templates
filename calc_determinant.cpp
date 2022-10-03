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

const int N=1e3+5;
int b[N],a[N][N],n,tre[N];

int lowbit(int i){return i&-i;}

void Add(int x,int v){
    while(x<=n){
        tre[x]+=v;
        x+=lowbit(x);
    }
    return;
}

int Query(int x){
    int res=0;
    while(x>0){
        res+=tre[x];
        x-=lowbit(x);
    }
    return res;
}

int rev(){
    int ans=0;
    memset(tre,0,sizeof(tre));
    for(int i=1;i<=n;++i){
        Add(b[i],1);
        ans+=n-Query(b[i]);
    }
    return ans;
}

int main(){

    freopen("1.in","r",stdin);

    n=in;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j]=in;
    
    for(int i=1;i<=n;++i) b[i]=i;
    int ans=0;
    do{
        int f=1;
        if(rev()&1) f=-1;
        for(int i=1;i<=n;++i)
            f*=a[i][b[i]];
        ans+=f;
    }while(next_permutation(b+1,b+n+1));

    cout<<ans<<endl;
    return 0;
    
}