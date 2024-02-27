#include "all.h"
#include "file.h"
#include "student.h"
#include "utils.h"
int menu() {
	int choice;
	while (1) {
		// 打印菜单选项
		printf("\n菜单:\n");
		printf("1. 添加学生\n");
		printf("2. 删除学生\n");
		printf("3. 从文件中读取所有数据\n");
		printf("4. 保存到文件\n");
		printf("5. 查询用户\n");
		printf("6. 退出\n");

		// 提示用户输入选项
		printf("请输入选项数字: ");
		scanf("%d", &choice);

		// 根据用户输入执行相应操作
		switch (choice) {
			case 1:
				printf("请输入学生信息(学号	姓名	性别	年龄	专业	班级)\n");
				student* stu = (student*)malloc(sizeof(student));
				stu->stu_id = (char*)malloc(50);
				stu->stu_major = (char*)malloc(60);
				stu->stu_sex = (char*) malloc(10);
				stu->stu_name = (char*)malloc(100);
				stu->clazz = (char*)malloc(100);
				scanf("%49s %59s %9s %d %99s %99s",stu->stu_id,stu->stu_name,stu->stu_sex,&(stu->stu_age),stu->stu_major,stu->clazz);
				insert_stu(stu);
				break;
			case 2:
				printf("请输入要删除的学生id:\n");
				char delete_id[100];
				scanf("%s",delete_id);
				int ret = delete_stu(delete_id);
				if(ret == 1) {
					printf("删除失败，没有这个学生id！\n");
				}
				break;
			case 3:
				read_file(FILE_NAME);
				break;
			case 4:
				save_data();
				break;
			case 5:
				printf("请输入要查询的学生id:\n");
				char stu_id[100];
				scanf("%s",stu_id);
				query_stu_id(stu_id);
				break;
			case 6:
				printf("退出程序\n");
				return 0;
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
//	read_file(FILE_NAME);
	return 0;
}
