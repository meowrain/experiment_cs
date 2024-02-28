#include "student.h"
#include "utils.h"
student students[1024]; //从磁盘中读取student数据之后，将会把数据存储在这个数组之中
int len = 0;
void insert_stu(student* stu) {
	students[++len] = *stu;
}
int load_students(const char* filename) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("fopen");
		return 1;
	}
	setPoisitionByLine(fp, 2); //控制文件流指针到第二行，使得其不读取上面两行（也就是表头
	char buffer[MAX_LENGTH_OF_LINE];
	while (fgets(buffer, MAX_LENGTH_OF_LINE, fp) != NULL) {
		// 使用 malloc 在堆上分配内存给 student 对象
		student* stu = malloc(sizeof(student));
		char* token;
		const char* delim = "\t";//分隔符

		token = strtok(buffer, delim);
		stu->stu_id = strdup(token);
//		printf("%s\n",stu->stu_id);
		token = strtok(NULL, delim);
		stu->stu_name = strdup(token);
//		printf("%s\n",stu->stu_name);
		token = strtok(NULL, delim);
		stu->stu_sex = strdup(token);
//		printf("%s\n",stu->stu_sex);
		token = strtok(NULL, delim);
		stu->stu_age = atoi(token);
//		printf("%d\n",stu->stu_age);
		token = strtok(NULL, delim);
		stu->stu_major = strdup(token);
//		printf("%s\n",stu->stu_major);
		token = strtok(NULL, delim);
		stu->clazz = strdup(token);
//		printf("%s\n",stu->clazz);
		// 将堆上的对象插入数组，而非栈上的对象
		insert_stu(stu);
//		freeCopy(stu);
	}

	return 0;

}
int creat_stu_talbe(char* file_name) {
	FILE* fp;
	fp = fopen(file_name, "w");
	if (fp == NULL) {
		perror("fopen");
		return 1;//表示打开错误
	}
	char* str = "学号\t姓名\t性别\t年龄\t专业\t班级\n---------------------------------";
	fprintf(fp, "%s", str);
	fclose(fp);//关闭文件描述符
	return 0;
}

/**
 * @brief
 *
 * @param stu
 *
 * @return
 */
int insert_stu_file(student* stu) {
	FILE* fp;
	fp = fopen(FILE_NAME, "a");
	setPoisitionByLine(fp, 2); //控制文件流指针到第二行，使得其不读取上面两行（也就是表头
	if (fp == NULL) {
		perror("fopen");
		return 1;//表示打开错误
	}
	fputc('\n', fp);
	if (fprintf(fp, "%s\t", stu->stu_id) == -1) {
		perror("fprintf");
		return 1;
	}
	if (fprintf(fp, "%s\t", stu->stu_name) == -1) {
		perror("fprintf");
		return 1;
	}
	if (fprintf(fp, "%s\t", stu->stu_sex) == -1) {
		perror("fprintf");
		return 1;
	}
	if (fprintf(fp, "%d\t", stu->stu_age) == -1) {
		perror("fprintf");
		return 1;
	}
	if (fprintf(fp, "%s\t", stu->stu_major) == -1) {
		perror("fprintf");
		return 1;
	}
	if (fprintf(fp, "%s\t", stu->clazz) == -1) {
		perror("fprintf");
		return 1;
	}
	fflush(fp);
	fclose(fp);
	return 0;
}

int delete_stu(char* stu_id) {
	if (len == 0) {
		printf("读取到的结构体数组为空，无法删除任何元素！\n");
		return 1;
	}
	for (int i = 1; i <= len; i++) {
		if (strcmp(students[i].stu_id, stu_id) == 0) {
			printf("删除成功！\n");
			for (int j = i; j < len; j++) {
				students[j] = students[j + 1];
			}
			len--;
			return 0;
		}
	}
	return 1;
}

int save_data() {
	creat_stu_talbe(FILE_NAME);
	for (int i = 1; i <= len; i++) {
		insert_stu_file(&students[i]);
	}
	return 0;
}

void get_all_students() {
	for (int i = 1; i <= len; i++) {
		printf("%s\n", students[i].stu_name);
	}
}


int query_stu_id(char* stu_id) {
	for (int i = 1; i <= len; i++) {
		if (strcmp(students[i].stu_id, stu_id) == 0) {
			printf("%s\t", students[i].stu_id);
			printf("%s\t", students[i].stu_name);
			printf("%s\t", students[i].stu_sex);
			printf("%d\t", students[i].stu_age);
			printf("%s\t", students[i].stu_major);
			printf("%s\t", students[i].clazz);
			return 0;
		}
	}
	return 1;
}
int query_stu_name(char* stu_name);
int query_stu_age(int stu_age);
int query_stu_major(char* stu_major);
int query_stu_clazz(char* clazz);
