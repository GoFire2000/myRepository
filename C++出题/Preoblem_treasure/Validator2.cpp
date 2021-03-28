#include "testlib.h"
int main(int argc,char **argv){
	registerValidation(argc,argv);
	int n=inf.readInt(1,5000,"n");
	inf.readSpace();
	int m=inf.readInt(1,5000,"m");
	inf.readSpace();
	int K=inf.readInt(1,n*m,"K");
	inf.readEoln();
	for(int i=1;i<=K;i++){
		int x=inf.readInt(1,n,"x_i");
		inf.readSpace();
		int y=inf.readInt(1,m,"y_i");
		inf.readEoln(); 
	} 
	inf.readEof();
	return 0;
}
