#ifndef UTILS_H
#define UTILS_H
#include "all.h"
#include "student.h"
#define MAX_LENGTH_OF_LINE 100000
int setPoisitionByLine(FILE* fp, int line);
student deepCopy(const student* original);
void freeCopy(student* stu);
#endif
