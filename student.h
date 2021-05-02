typedef struct{
    char name[100];
    int studentno;
    int attdance;
} Attendance;

int updateStudent(Attendance *a); //학생 정보 수정

int updateAttendance(Attendance *a); //출석부 정보 업데이트

int selectDataNo(Attendance *a, int index); //학생 정보 선택

int deleteStudent(Attendance *a); //학생 정보 삭제

int searchStudent(Attendance *a, int count); //학생검색

int listStudentNo(Attendance *a, int count); // 학번으로 정렬 검색

int searchAttendaceNo(Attendance *a, int count); //출석 횟수로 검색

