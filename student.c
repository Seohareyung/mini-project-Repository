#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

int selectMenu(){
        int menu;
        printf("\n\n");
        printf("1. 학생 데이터 조회\n");
        printf("2. 학생 정보 추가 \n");
        printf("3. 학생 정보 수정\n");
        printf("4. 출석 정보 업데이트\n");
        printf("5. 학생 정보 삭제\n");
        printf("6. 파일 저장\n");
        printf("7. 학생명으로 검색\n");
        printf("8. 학번으로 검색\n");
        printf("9. 출석횟수로 검색\n");
        printf("0. 종료\n");
        printf("원하는 일을 선택해주세요: ");
        scanf("%d", &menu);
        return menu;
} //메뉴 선택 함수

void listStudent(Attendance *s, int count){
	int i = 0;
    	printf("******************************\n");
    	printf("  학번 이름     출석    지각\n");
    	for (i = 0; i < count; i++)
    	{
		if (s[i].studentno <=0) continue;
        	printf("%2d ", i + 1);
        	readStudent(s[i]);
    }
}

int createStudent(Attendance *s){

	char pname[100];
  	getchar();
  	printf("\n학생 이름은? ");
  	fgets(pname, 100, stdin);
	strcpy(s->name, pname);
  	rewind(stdin);
  	printf("학번은? ");
  	scanf("%d", &s->studentno);
 	 s->attendance = 0;
	s->late = 0;
	printf("=> 추가 성공!\n");    
	return 1;
    }

int updateStudent(Attendance *s){
        char rename[100];
        getchar();
        printf("\n수정할 학생 이름은? ");
        fgets(rename, 100, stdin);
        rewind(stdin);
        strcpy(s->name, rename);
        printf("수정할 학번은? ");
        scanf("%d", &s->studentno);
        printf("=> 수정성공!\n");
        return 1;

} // 학생 정보 수정 : 메뉴 3번

int updateAttendance(Attendance *s){
        int up;

        printf("\n출석? (Yes:1, No:0): ");
        scanf("%d", &up);
<<<<<<< HEAD
	if(up == 1) s->attendance=s->attendance+1;	else s->late=s->late+1;
=======
        if(up == 1) s->attendance=s->attendance+1;
        else s->late=s->late+1;
>>>>>>> 79ceb907bf9eded9b72119d25d94d64376282e1d
        printf("=> 출석 확인 완료!\n");
        return 1;
} //출석 확인 : 메뉴 4번

int deleteStudent(Attendance *s){
        s->studentno = -1;
        s->attendance = -1;
        s->late = -1;
        printf("=> 삭제됨!\n");
        return 1;

} //학생 정보 삭제 함수 : 메뉴5번

int selectDataNo(Attendance *s, int count){
        int no;
        listStudent(s, count);
        printf("\n번호는 (취소 :0)? ");
        scanf("%d", &no);
        return no;
} // 학생 정보 선택 함수


void readStudent(Attendance s){
        printf("%d %s %5d(회) %d(회)\n", s.studentno, s.name, s.attendance, s.late);
}
// 학생 정보 출력

int searchStudent(Attendance *s, int count){}

