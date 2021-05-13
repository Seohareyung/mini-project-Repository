typedef struct{
    char name[100];
    int studentno;
    int attendance;
    int late;
} Attendance;

int selectMenu(); //메뉴 출력 함수

int createStudent(Attendance *s); // 학생 정보 생성

void readStudent(Attendance s); // 학생 정보 조회

int loadStudent(Attendance *s); //파일에서 데이터 불러오기

void saveStduent(Attendance *s, int count); //파일에 데이터 저장하기

void listStudent(Attendance *s, int count); //전체 등록된 학생

int updateStudent(Attendance *s); //학생 정보 수정

int updateAttendance(Attendance *s); //출석부 정보 업데이트

int selectDataNo(Attendance *s, int index); //학생 정보 선택

int deleteStudent(Attendance *s); //학생 정보 삭제

void searchStudent(Attendance *s, int count); //학생검색

void searchStudentNo(Attendance *s, int count); // 학번으로 검색

void searchAttendanceNo(Attendance *s, int count); //출석 횟수로 검색


