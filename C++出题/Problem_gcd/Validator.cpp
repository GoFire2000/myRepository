#include "testlib.h" 
#define Inf 100000000000ll
#define LL long long
int main(int argc,char **argv){
	registerValidation(argc,argv);
	int n=inf.readInt(2,100000,"n");
	inf.readSpace();
	int Q=inf.readInt(2,100000,"Q");
	inf.readEoln();
	for(int i=1;i<=n;i++){
		LL x=inf.readLong(-Inf,Inf,"a_i");
		if(i==n) inf.readEoln();
		else inf.readSpace();
	} 
	for(int i=1;i<=Q;i++){
		LL x=inf.readLong(-Inf,Inf,"d");
		inf.readEoln();
	}
	inf.readEof();
	return 0;
} 
