#include "utils.h"

int setPoisitionByLine(FILE* fp,int line){
	int i = 0;
	char buffer[MAX_LENGTH_OF_LINE + 1];
	fpos_t pos;
	rewind(fp);//重定向流
	for(;i<line;i++) {
		fgets(buffer,MAX_LENGTH_OF_LINE,fp);
	}
	fgetpos(fp,&pos);
	return 0;
}

