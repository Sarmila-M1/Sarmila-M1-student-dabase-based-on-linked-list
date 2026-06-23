#include "as_header.h"
void stud_show(stu *mem)
{
        if(mem==0)
        {       printf("No student record found....\n");
                return;
        }
        while(mem)
        {printf("%d %s %f\n",mem->rollno,mem->name,mem->marks);
        mem=mem->next;}
        return;
}
