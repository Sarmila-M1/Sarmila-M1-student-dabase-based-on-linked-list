#include"as_header.h"
stu *hptr=0;
int *roll=0;
int studentcount=0;
int meall=0;
int roll_allocate()
{
        if(roll==0)
        {
                roll=malloc(8);
		meall++;
                roll[0]=1;
                return 1;
        }
        for(int i=0;i<studentcount;i++)
        {
                if(roll[i]==0)
                {
                        roll[i]=i+1;
                        return i+1;
                }
        }
	meall++;
        roll=realloc(roll,8*(studentcount+1));
        roll[studentcount]=studentcount+1;
        return studentcount+1;
}
int main()
{
        while(1)
        {
                char ch;
                printf("******STUDENT RECORD MENU******\n_______________________________\n\n");
                printf("a/A : add new record\nd/D : delete a record\ns/S : show the list\nm/M : modify a record\nv/V : save\ne/E : exit\nt/T : sort the list\nl/L : delete all the records\nr/R : reverse the list\nu/U : to restore the student data from file\n\nEnter your choice : ");
                scanf(" %c",&ch);
                switch(ch)
                {
                        case 'a':
                        case 'A':stud_add(&hptr);printf("\n");break;
                        case 'd':
                        case 'D':stud_del(&hptr);printf("\n");break;
                        case 's':
                        case 'S':stud_show(hptr);printf("\n");break;
                        case 'm':
                        case 'M':stud_mod(&hptr);printf("\n");break;
                        case 'v':
                        case 'V':stud_save(hptr);printf("\n");break;
                        case 'e':
                        case 'E':printf("\n");break;
                        case 't':
                        case 'T':stud_sort(hptr);printf("\n");break;
                        case 'l':
                        case 'L':stud_del_allnode(&hptr);printf("\n");break;
                        case 'r':
                        case 'R':stud_reverse(&hptr);printf("\n");break;
			case 'u':
			case 'U':stu_updatefile(&hptr);printf("\n");break;
			default :printf("You entered an invalid choice\n");break;
             }
                if((ch=='e')||(ch=='E'))
                        break;
        }
}

