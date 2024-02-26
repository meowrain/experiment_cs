# 从第n行开始读写

```c
int setPoisitionByLine(FILE* fp,int nLine) {
	int i = 0;
	char buffer[MAX_LENGTH_OF_LINE+1];
	fpos_t pos;
	rewind(fp); //重定向流
	for(;i<nLine;i++) {
		fgets(buffer,MAX_LENGTH_OF_LINE,fp);
	}
	fgetpos(fp,&pos);
	return 0;
}	

int ReadByLine() {
	char buffer[MAX_LENGTH_OF_LINE + 1];
	FILE* fp;
	fp = fopen(filename,"r");
        setPoisitionByLine(fp,2);//定位文件流指针到第二行
       fgets(buffer,MAX_LENGTH_OF_LINE,fp);
       printf("%s\n",buffer);
       return 0;
}
```

