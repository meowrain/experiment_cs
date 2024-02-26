#ifndef STUDENT_H
#define STUDENT_H
#include "all.h"
#include "file.h"
typedef struct student {
	char* stu_id;//学生id
	char* stu_name;//名字
	char* stu_sex;//性别
	int stu_age;//年龄
	char* stu_major;//专业
	char* clazz;
}student;

/*
* @description 创建学生表
*/
int creat_stu_talbe(char* file_name);

void get_all_students();

void insert_stu(student* stu);
/**
 * @description  从文件中读取数据，然后把数据存储到student students[1024]数组中
 * 
 * @param filename 
 * 
 * @return 
 */
int load_students(const char* filename);



/*
* @description 插入单个学生到文件
*/
int insert_stu_file(student* stu);

/*
* @description 查询学生
* @function query_stu_id 通过stu_id查询学生，stu_id是唯一值，返回这个叙述
* @function query_stu_name 通过stu_name查询学生，返回是这个名字的所有学生（考虑重名情况
* @function query_stu_age 通过stu_age查询学生。返回这个年龄的所有学生
* @function query_stu_major 通过stu_major查询学生，返回这个专业的所有学生
* @function query_stu_clazz 通过stu_clazz查询学生，返回这个班级的所有学生
* */
int query_stu_id(int stu_id);
int query_stu_name(char* stu_name);
int query_stu_age(int stu_age);
int query_stu_major(char* stu_major);
int query_stu_clazz(char* clazz);


/**
 * @description 删除这个id的学生
 * 
 */
int delete_stu(int stu_id);

/*
* @description 保存所有学生数据到磁盘
*/
int save_data();
#endif
