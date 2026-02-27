#include<stdio.h>
#include <string.h>
 // 成绩结构体
 struct Score {
     int yuwen;   // 语文
     int shuxue;  // 数学
     int yingyu;  // 英语
     int total;   // 总分
 };
 // 学生结构体
 struct Student {
     char id[20];    // 学号
     char name[20];  // 姓名
     struct Score sc; 
 };
 // 学生数组
 struct Student stu[50];
 int n = 0;
 void menu();
 void add();
 void showAll();
 void find();
 void save();
 void load();
 int main() {
     load();
     menu();
     return 0;
 }
 // 菜单
 void menu() {
     while (1) {
         printf("\n------- 学生成绩管理系统 -------\n");
         printf("1. 添加学生\n");
         printf("2. 查看所有学生\n");
         printf("3. 按学号查找学生\n");
         printf("4. 保存并退出\n");
         printf("请输入选择：");
         int choice;
         scanf("%d", &choice);
         if (choice == 1) {
         	add();
		 }
         else if (choice == 2){
         	 showAll();
		 }
         else if (choice == 3){
         	 find();
		 }
         else if (choice == 4) {
             save();
             printf("已保存，退出成功！\n");
             break;
         } else {
             printf("输入错误！\n");
         }
     }
 }
 // 添加学生
 void add() {
     if (n >= 50) {
         printf("学生已满！\n");
         return;
     }
     struct Student *p = &stu[n];
     printf("请输入学号：");
     scanf("%s", p->id);
     printf("请输入姓名：");
     scanf("%s", p->name);
     printf("请输入语文 数学 英语：");
     scanf("%d %d %d", &p->sc.yuwen, &p->sc.shuxue, &p->sc.yingyu);
     // 计算总分
     p->sc.total = p->sc.yuwen + p->sc.shuxue + p->sc.yingyu;
     n++;
     printf("添加成功！\n");
 }
 // 显示所有学生
 void showAll() {
     if (n == 0) {
         printf("暂无学生！\n");
         return;
     }
     printf("\n学号\t姓名\t语文\t数学\t英语\t总分\n");
     for (int i = 0; i < n; i++) {
         printf("%s\t%s\t%d\t%d\t%d\t%d\n",stu[i].id, stu[i].name,stu[i].sc.yuwen, stu[i].sc.shuxue, stu[i].sc.yingyu, stu[i].sc.total);
     }
 }
 // 按学号查找
 void find() {
     char num[20];
     printf("请输入要查找的学号：");
     scanf("%s", num);
     for (int i = 0; i < n; i++) {
         if (strcmp(stu[i].id, num) == 0) {
             printf("找到：%s %s %d %d %d 总分：%d\n", stu[i].id, stu[i].name, stu[i].sc.yuwen, stu[i].sc.shuxue, stu[i].sc.yingyu, stu[i].sc.total);
             return;
         }
     }
     printf("未找到！\n");
 }
 // 保存到文件
 void save() {
     FILE *fp = fopen("student.txt", "w");
     for (int i = 0; i < n; i++) {
         fprintf(fp, "%s %s %d %d %d %d\n",
                 stu[i].id, stu[i].name,
                 stu[i].sc.yuwen, stu[i].sc.shuxue, stu[i].sc.yingyu, stu[i].sc.total);
     }
     fclose(fp);
 }
 // 从文件读取
 void load() {
     FILE *fp = fopen("student.txt", "r");
     if (fp == NULL) return;
     n = 0;
     while (fscanf(fp, "%s %s %d %d %d %d",
                   stu[n].id, stu[n].name,
                   &stu[n].sc.yuwen, &stu[n].sc.shuxue, &stu[n].sc.yingyu, &stu[n].sc.total) != EOF) {
         n++;
     }
     fclose(fp);
 }
