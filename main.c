#include "all.h"
#include "file.h"
#include "student.h"
int main(int argc, char *argv[]) {
//	SetConsoleOutputCP(65001);
	load_students(FILE_NAME);
//		student stu = {"20221211121","liruiyydsssss","男",24,"soft ware engineer","2022"};
//	student stu2 = {"20221211122","meowrain222","男",22,"computer science","2022"};
//	insert_stu(&stu);
//	insert_stu(&stu2);
	get_all_students();
	save_data();

//	save_data();
	read_file(FILE_NAME);
	return 0;
}
