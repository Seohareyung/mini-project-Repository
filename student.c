#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


int selectMenu(){
        int menu;
        printf("\n");
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

void readStudent(Attendance s){
        printf("%d %s %5d(회) %d(회)\n", s.studentno, s.name, s.attendance, s.late);
}

void listStudent(Attendance *s, int count){
   int i = 0;
       printf("******************************\n");
       printf("    학번    이름   \n    출석    지각\n");
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

        printf("\n번호로 입력하세요 : (출석:1, 지각:0): ");
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

void saveStudent(Attendance *s, int count){
    FILE *fp;
    fp = fopen("attendance.txt","wt");
    for(int i =0;i<count;i++){
        if(s[i].attendance == -1) continue;
        fprintf(fp,"%d %s %d %d\n",s[i].studentno, s[i].name, s[i].attendance, s[i].late);
    }
        fclose(fp);
        printf("저장됨!\n");

}// 파일 저장함수: 메뉴 6번


int loadStudent(Attendance *s){
    FILE *fp;
    fp = fopen("attendance.txt","rt");
    int i =0;
    if(fp == NULL){
        printf("=> 파일 없음!\n");
    }
    else {
        for (i=0;i<100;i++){
            fscanf(fp, "%d", &s[i].studentno);
            if(feof(fp)) break;
            fscanf(fp, "%s %d %d", s[i].name, &s[i].attendance, &s[i].late);
        }
        fclose(fp);
        printf("=> 로딩 성공\n");

    }return i;
} //파일 load 함수

void searchStudent(Attendance *s, int count){
        int scnt = 0;
        char search[20];
        int i = 0;

        printf("검색할 학생이름을 입력해주세요: ");
        scanf("%s", search);

        printf("******************************\n");
        printf("    학번    이름   \n    출석    지각\n");
        for(i=0; i<count; i++){
                if(s[i].studentno == -1) continue;
                if(strstr(s[i].name, search)){
                        printf("%2d)", i+1);
                        readStudent(s[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
} //학생검색 : 메뉴 7번

void searchStudentNo(Attendance *s, int count){
        int scnt = 0;
        int num = 0;
        int i = 0;

        printf("검색할 학생의 학번을 입력해주세요: ");
        scanf("%d", &num);

        printf("******************************\n");
        printf("    학번    이름   \n    출석    지각\n");
        for(i=0; i< count; i++){
                if(s[i].studentno == -1) continue;
                if(num == s[i].studentno){
                        printf("%2d) ", i+1);
                        readStudent(s[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("=> 검색된 데이터가 없음!\n");

} // 학번으로 검색 : 메뉴 8번

void searchAttendanceNo(Attendance *s, int count){
        int scnt = 0;
        int attno = 0;
        int i = 0 ;

        printf("출석 횟수를 입력해주세요(n번 이상 출석한 학생 모두 출력): ");
        scanf("%d", &attno);

        printf("******************************\n");
        printf("    학번    이름   \n    출석    지각\n");

        for(i=0; i<count; i++){
                if(s[i].studentno==-1) continue;
                if(s[i].attendance >= attno){
                        printf("%2d) ", i+1);
                        readStudent(s[i]);
                        scnt++;
                }
        }        
        if(scnt == 0) printf("=> 검색된 데이터 없음\n");
} //출석 횟수로 검색 : 메뉴 9번


