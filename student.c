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

typedef struct{
    char name[100];
    int studentno;
    int attendance;
    int late;
} Attendance;

void listStudent(Attendance *s, int count){
    printf("\n 학번 이름 출석 지각\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        printf("%d ",i+1);
        readStuduent(s[i]);
    }
}// 학생 데이터 조회 : 메뉴 1번

 
int createStudent(Attendance *s){
        char name[100];
        getchar();
        printf("\n학생 이름은? ");
        fgets(name, 100, stdin);
        rewind(stdin);
        strcpy(s->name, name);
        printf("학번은? ");
        scanf("%d", &s->studentno);
        printf("=> 추가 성공!\n");
        return 0;
}// 학생 정보 추가 : 메뉴 2번


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
	if(up == 1) s->attendance=s->attendance+1;
	else s->late=s->late+1;
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
// 학생 정보 출력 함수


