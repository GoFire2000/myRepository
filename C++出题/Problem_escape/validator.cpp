#include "testlib.h"
int main(int argc,char **argv){
	registerValidation(argc,argv);
	int n=inf.readInt(1,200,"n");
	inf.readSpace();
	int m=inf.readInt(1,200,"m");
	inf.readSpace();
	int h=inf.readInt(1,200,"h");
	inf.readEoln();
	int num=0;
	for(int k=1;k<=h;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char c=inf.readChar();
				bool flag=false;
				if(c=='#' || c=='*' || c=='S' || c=='T' || c=='P') flag=true;
				ensure(flag==true);
				if(c=='p') num++;
			}
			inf.readEoln();
		}
		if(k!=h) inf.readEoln();
	}
	ensure(num<=1);
	inf.readEof();
	return 0;
}
