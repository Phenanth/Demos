/*
实验8_3
题目：
编写一个文本文件加密(Encryption)程序，
将一个明文文件中的内容，按照其ASCII+2的方法，对每个字符加密后存放到另一个密文文件中。
再编写一个文本文件解密（Decipher）程序，将上述加密密文文件中的内容解密后存放到另一个明文文件中。

构成：
明文文件FILE1：8_3file1.txt 密文文件FILE2：8_3file2.txt 解密文件FILE3： 8_3file3.txt
main函数功能：包含e和d两个函数
encryption函数功能：从FILE1 ch = fgetc并每次将ch + 2 fputc到FILE2 直到EOF
decipher函数功能：从FILE2 同样 ch - 2 放到 FILE3 直到EOF
*/
#include <stdio.h>
#include <stdlib.h>
#define FILE1 "8_3file1.txt"//原文件
#define FILE2 "8_3file2.txt"//加密文件
#define FILE3 "8_3file3.txt"//解密文件

void encryption(void);
void decipher(void);

int main(){
	encryption();
	decipher();
	return 0;
}
void encryption(){
	FILE *pfile1,*pfile2;
	char ch;
	pfile1 = fopen(FILE1,"r");
	if(pfile1 == NULL){
		printf("Can't open the file:%s!\n",FILE1);
		exit(EXIT_FAILURE);
	}
	pfile2 = fopen(FILE2,"w");
	if(pfile2 == NULL){
		printf("Can't open the file:%s!\n",FILE2);
		exit(EXIT_FAILURE);
	}
	ch = fgetc(pfile1);
	while(ch != EOF){
		fprintf(pfile2,"%c",ch + 2);
		ch = fgetc(pfile1);
	}
	fclose(pfile1);
	fclose(pfile2);
}
void decipher(void){
	FILE *pfile2,*pfile3;
	char ch;
	pfile2 = fopen(FILE2,"r");
	if(pfile2 == NULL){
		printf("Can't open the file:%s!\n",FILE2);
		exit(EXIT_FAILURE);
	}	
	pfile3 = fopen(FILE3,"w");
	if(pfile3 == NULL){
		printf("Can't open the file:%s!\n",FILE3);
		exit(EXIT_FAILURE);
	}	
	ch = fgetc(pfile2);
	while(ch != EOF){
		fprintf(pfile3,"%c",ch - 2);
		ch = fgetc(pfile2);
	}
	fclose(pfile2);
	fclose(pfile3);
	printf("Process Succeeded!\n");
}
