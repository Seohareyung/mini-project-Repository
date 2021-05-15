#include <stdio.h>
#include "student.h"

int main(void)
{
    Attendance att[100];
    int count = 0, index = 0, menu;

    while(1)
    {
        menu = selectMenu();
        if (menu == 0)
        {
            printf("종료됨!\n");
            break;
        }
        if (menu == 1 || menu == 3 || menu == 4 || menu == 5)
            if (count == 0)
                continue;
        if (menu == 2)
        {
            count += createStudent(&att[index++]);
        }
        else if (menu == 1){
            if(count > 0) listStudent(att, index);
        }

        else if (menu == 3)
        {
            int no = selectDataNo(att, index);
            if (no == 0)
            {
                printf("=> 취소됨\n");
                continue;
            }
            updateStudent(&att[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(att, index);
            if(no == 0){
                printf("=> 취소됨\n");
                continue;
            }
            updateAttendance(&att[no-1]);
        }
        else if (menu == 5)
        {
            int no = selectDataNo(att, index);
            if (no == 0)
            {   
                 printf("=> 취소됨\n");
                continue;
            }
                int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제:1)");
                scanf("%d", &deleteok);
                if (deleteok == 1)
                {
                    if(deleteStudent(&att[no-1])) count--;
                }
            }
        else if(menu == 6)
        {
            saveData(att, index);
        }
        else if (menu == 7)
        {
            searchStudent(att, index);
        }
        else if (menu == 8)
        {
            searchStudentNo(att, index);
        }
        else if (menu == 9)
        {
            searchAttendanceNo(att, index);
        }
    }
    return 0;
}

