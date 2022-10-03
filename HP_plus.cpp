#include<bits/stdc++.h>
using namespace std;

const int N=600;
char ch[N];
int a[N],b[N],n,m,c[N],x;

int main(){

    // freopen("1.in","r",stdin);

    cin>>ch;
    n=strlen(ch);
    for(int i=0;i<n;++i)
        a[n-i]=ch[i]-48;
    
    cin>>ch;
    m=strlen(ch);
    for(int i=0;i<m;++i)
        b[m-i]=ch[i]-48;
    
    if(n<m) n=m;

    x=0;
    for(int i=1;i<=n;++i){
        c[i]=(a[i]+b[i]+x)%10;
        x=(a[i]+b[i]+x)/10;
    }
    if(x>0) ++n, c[n]=x;
    for(int i=n;i>0;--i)
        printf("%d",c[i]);
    return 0;
}
