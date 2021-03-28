/*
*注意/*
*注意//
*注意
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define Inf 1e9
const int maxn=10010;
char s[maxn],Last[maxn];
char ss[maxn];
void Init();
int main(){
//	freopen("test.in","r",stdin);
    Init();
    return 0;
}
void Init(){
    bool flag1=false;
    int flag2=0;
    int len,Lastlen=0;
    while(true){
        int cnt=0;
        bool endtag=false;
        char ch;
        while((ch=getchar())!=EOF) {
            if(ch=='\n') break;
            s[++cnt]=ch;
        }
        if(ch==EOF) break;
        s[cnt+1]=0;
        len=cnt;
//        printf("%d\n",len);
//		printf("======input:");
//		for(int i=1;i<=len;i++) printf("%c",s[i]);puts("\n");
        cnt=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='/' && s[i+1]=='*') {
                flag1 = true;
                i=i+2;
                continue;
            }
            if(s[i]=='*' && s[i+1]=='/') {
                flag1=false;
                i=i+2;
                continue;
            }
            if(flag1==false) s[++cnt]=s[i];
        }
//        printf("flag1=%d\n",flag1);
        len=cnt;
        for(int i=1;i<=len;i++){
            if(s[i]=='\\' && s[i+1]=='\\') {
                len=i-1;
                break;
            }
        }
        cnt=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='{'){
                flag2++;
                s[++cnt]='{';
                continue;
            }
            if(s[i]=='}'){
                flag2--;
                s[++cnt]='}';
                continue;
            }
            if(flag2==0) s[++cnt]=s[i];
        }
        len=cnt;
//        printf("======input:");
//        for(int i=1;i<=len;i++) printf("%c",s[i]);puts("\n");
        cnt=1;
        while(s[cnt]==' ') cnt++;
        int now=0;
        for(int i=cnt;i<=len;i=cnt){
            s[++now]=s[i];
            cnt=i+1;
            if(s[i]==' ') {
                while(s[cnt]==' ' && cnt<=len) cnt++;
            }
        }
        len=now;
        while(s[len]==' ' && len>=1) len--;
        if(len<1) {
            Lastlen=0;
            continue;
        }

        for(int i=1;i<=len;i++){
            if(s[i]=='{') {len=i;break;}
        }
        if(s[len]=='{' && len!=1 && flag2==1 && s[len-1]==')'){
//            puts("<<<<<输出::::");
            len--;
            while(s[len]==' ' && len>=1) len--;
            int pos=0;
            for(int i=1;i<=len;i++){
                printf("%c",s[i]);
                if(s[i]=='('){
                    pos=i+1;
                    break;
                }
            }
            int now;
            for(int i=pos;i<=len;i=now){
                if(s[i]==')') {printf(")");break;}
                now=i;
                while(s[now]==' ' && now<=len) now++;
                int j;
                for(j=now;j<=len;j++){
                    if(s[j]==',' || s[j]==')') break;
                }
                j--;int cun=j;
                while(s[j]==' ' && j>=1) j--;
                while(s[j]!=' ' && j>=1) j--;
                while(s[j]==' ' && j>=1) j--;
                while(now<=j) {
                    printf("%c",s[now]);
                    now++;
                }
                now=cun+1;
                printf("%c",s[now]);
                if(s[now]==')') break;
                now++;
            }
            puts("");
        }
        if(s[1]=='{' && flag2==1 && Last[Lastlen]==')') {

//            puts("<<<<<输出::::");
//            for(int i=1;i<=Lastlen;i++) printf("%c",Last[i]);puts("");
            int pos=0;
            for(int i=1;i<=Lastlen;i++){
                printf("%c",Last[i]);
                if(Last[i]=='('){
                    pos=i+1;
                    break;
                }
            }
            int now;
            for(int i=pos;i<=Lastlen;i=now){
                if(Last[i]==')') {printf(")");break;}
                now=i;
                while(Last[now]==' ' && now<=Lastlen) now++;
                int j;
                for(j=now;j<=Lastlen;j++){
                    if(Last[j]==',' || Last[j]==')') break;
                }
                j--;int cun=j;
                while(Last[j]==' ' && j>=1) j--;
                while(Last[j]!=' ' && j>=1) j--;
                while(Last[j]==' ' && j>=1) j--;
                while(now<=j) {
                    printf("%c",Last[now]);
                    now++;
                }
                now=cun+1;
                printf("%c",Last[now]);
                if(Last[now]==')') break;
                now++;
            }
            puts("");
        }
        for(int i=1;i<=len;i++){
            Last[i]=s[i];
//            printf("%c",s[i]);
        }
//		puts("");
        Lastlen=len;
    }
}
