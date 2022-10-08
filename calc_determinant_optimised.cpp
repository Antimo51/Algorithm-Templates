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

int gcd(int a,int b){return b?gcd(b,a%b):a;}

struct frac{
    int a,b;
    frac(){a=0, b=1;}
    frac(int x,int y){
        int d=gcd(x,y);
        a=x/d, b=y/d;
    }

    void print(){printf("%d/%d ",a,b);}
    friend bool operator != (const frac &x, const frac &y){ return (x.a!=y.a)||(x.b!=y.b);}
    friend frac operator / (const frac &x, const frac &y){ int a=x.a*y.b, b=x.b*y.a, d=gcd(a,b); return frac(a/d, b/d);}
    friend frac operator * (const frac &x, const frac &y){ int a=x.a*y.a, b=x.b*y.b, d=gcd(a,b); return frac(a/d, b/d);}
    friend frac operator - (const frac &x, const frac &y){ int a=x.a*y.b-x.b*y.a, b=x.b*y.b, d=gcd(a,b); return frac(a/d, b/d);}

}d[1005][1005];

char ch[100];
int len,p,ff=1;

int main(){

    freopen("1.in","r",stdin);

    int n=in;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            scanf("%s",ch+1);
            len=strlen(ch+1); p=0;
            for(int t=1;t<=len;++t)
                if(ch[t]=='/'){ p=t; break;}
            if(!p){
                int x=0,f=1,t=1; if(ch[1]=='-') f=-1, ++t;
                while(t<=len) x=(x<<1)+(x<<3)+ch[t]-48, ++t;
                d[i][j]=frac(x*f,1);
            }else{
                int x=0,f=1,t=1; if(ch[1]=='-') f=-1, ++t;
                while(t<p) x=(x<<1)+(x<<3)+ch[t]-48, ++t;
                d[i][j].a=x, ++t; x=0;
                while(t<=len) x=(x<<1)+(x<<3)+ch[t]-48, ++t;
                d[i][j].b=x;
            }
        }
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            if(d[j][i]!=frac(0,1)){
                for(int k=1;k<=n;++k) swap(d[j][k],d[i][k]);
                ff*=-1;
                break;
            }
        
        for(int j=1;j<=n;++j){
            if(j==i) continue;
            frac div=d[j][i]/d[i][i];
            for(int k=1;k<=n;++k) d[j][k]=d[j][k]-div*d[i][k];
        }
    }

    frac ans(1,1);
    for(int i=1;i<=n;++i) ans=ans*d[i][i];
    if(ans.b^1) ans.print();
    else printf("%d\n",ans);
    return 0;
    
}
