#include "utils.h"

int setPoisitionByLine(FILE* fp, int line) {
	int i = 0;
	char buffer[MAX_LENGTH_OF_LINE + 1];
	fpos_t pos;
	rewind(fp);//重定向流
	for (; i < line; i++) {
		fgets(buffer, MAX_LENGTH_OF_LINE, fp);
	}
	fgetpos(fp, &pos);
	return 0;
}

struct student deepCopy(const student* original) {
	student* copy = (student*)malloc(sizeof(student));
	if (copy == NULL) {
		exit(1);
	}
	copy->stu_id = strdup(original->stu_id);
	copy->stu_name = strdup(original->stu_name);
	copy->stu_sex = strdup(original->stu_sex);
	copy->stu_age = original->stu_age;
	copy->stu_major = strdup(original->stu_major);
	copy->clazz = strdup(original->clazz);
	return * copy;
}
void freeCopy(student* stu) {
	free(stu->stu_id);
	free(stu->stu_name);
	free(stu->stu_sex);
	free(stu->stu_major);
	free(stu->clazz);
	free(stu);
}
