#include "file.h"
int write_file(const char* filename,char* str) {
	FILE* fp;
	fp = fopen(filename,"a+");
	if(fp == NULL) {
		perror("fopen");
		return 1;
	}
	fprintf(fp,"%s",str);
	fclose(fp);
	return 0;
}
int read_file(const char* filename) {
	char buf[1024];
	FILE* fp;
	fp = fopen(filename,"r");
	if(fp == NULL) {
		perror("fopen");
		return 1;
	}
	
	while(fgets(buf,sizeof(buf),fp) != NULL) {
		printf("%s",buf);
	}
	
	return 0;
}


