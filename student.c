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

int updateAttendance(Attendance *s, count){
	int no;
	int up;

	listStudent(s,count);
	no = selectDataNo(s, count);
	printf("\n 출석? (Yes:1, No:0)");
	scanf("%d", &up);
	s[no-1].attendance+=up;
       	printf("\n 지각? (Yes:1, No:0");
	scanf("%d", &up);
	s[no-1].late+=up;
}	

int deleteProduct(Attendance *s){
	p->studentno = -1;
	p->attendance = -1;
	p->late = -1;
	printf("=> 삭제됨!\n");
	return 1;

} // 제품 삭제 함수 : 메뉴

int selectDataNo(Attendance *s, int count){
	int no;
	listStudent(s, count);
	printf("\n번호는 (취소 :0)?");
	scanf("%d", &no);
	return no;
}


