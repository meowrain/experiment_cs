#include "all.h"
#include "file.h"
#include "student.h"
int main(int argc, char *argv[]) {
//	SetConsoleOutputCP(65001);
//	const char* filename = "data.txt";
//	creat_stu_talbe(FILE_NAME);
	
	// todo: fix this function error: segment fault
	load_students(FILE_NAME);
	student stu = {"20221211121","liruiyydsssss","男",24,"soft ware engineer"};
	student stu2 = {"20221211122","meowrain222","男",22,"computer science"};
	insert_stu(&stu);
	insert_stu(&stu2);
	save_data();
	read_file(FILE_NAME);
	return 0;
}
