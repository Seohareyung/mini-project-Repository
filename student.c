#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "student.h"

int updateStudent(Attendance *s){
	char rename[100];
	getchar();
	printf("수정할 학생 이름은?");
	return 1;

} // 학생 정보 수정 : 메뉴

int deleteProduct(Attendance *s){
	p->studentno = -1;
	p->attendance = -1;
	p->late = -1;
	printf("=> 삭제됨!\n");
	return 1;

} // 제품 삭제 함수 : 메뉴

int selectDataNo(Attendance *s, int count){
	int no;
	listProduct(s, count);
	printf("\n번호는 (취소 :0)?");
	scanf("%d", &no);
	return no;
}
