#include "all.h"
#include "file.h"
#include "student.h"
void menu(){
	int choice;
	
	while (1) {
		// 打印菜单选项
		printf("Menu:\n");
		printf("1. 选项1\n");
		printf("2. 选项2\n");
		printf("3. 从文件中读取所有数据\n");
		printf("4. 退出\n");
		
		// 提示用户输入选项
		printf("请输入选项数字: ");
		scanf("%d", &choice);
		
		// 根据用户输入执行相应操作
		switch (choice) {
		case 1:
			printf("执行选项1\n");
			// 在这里添加选项1的具体操作
			break;
		case 2:
			printf("执行选项2\n");
			// 在这里添加选项2的具体操作
			break;
		case 3:
			read_file(FILE_NAME);
			// 在这里添加选项3的具体操作
			break;
		case 4:
			printf("退出程序\n");
			return 0; // 退出程序
		default:
			printf("无效的选项，请重新输入\n");
			break;
		}
	}
	return 0;
}
int main(int argc, char *argv[]) {
//	SetConsoleOutputCP(65001);
	load_students(FILE_NAME); //从文件中加载数据
	menu();
//	query_stu_id("20221211122");//找寻这个学号的学生
	
//		student stu = {"20221211121","liruiyydsssss","男",24,"soft ware engineer","2022"};
//	student stu2 = {"20221211122","meowrain222","男",22,"computer science","2022"};
//	insert_stu(&stu);
//	insert_stu(&stu2);
//	delete_stu("20221211121");
//	save_data();
	
//	save_data();
//	read_file(FILE_NAME);
	return 0;
}
