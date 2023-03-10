#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int admin();
int academician();
int officer();
int student();
int dersyazdir();

struct info{
    char ac_name[40];
    char ac_username[10];
    char ac_password[7];
    char of_name[40];
    char of_username[10];
    char of_password[7];
};

typedef struct info Admin;

struct student{
    char student_name[40];
    char department[30];
    char st_username[7];
    char st_password[7];
    float student_grade;
};

typedef struct student Student;

struct ac_les{
    char lessons[30];
    int term; 
};

typedef struct ac_les Ac_les;

int main()
{
    char choose[20]={};
    int password=0;

    printf("Please enter the username!! Admin, Academician, Officer, Student\n");
    gets(choose);
    strlwr(choose);

    if(strcmp(choose, "admin")==0)
    {
        do
        {
            printf("%s Please enter the password\n", choose);
            scanf("%d", &password);
            
            if(password==789520)
            {
                admin();
            }
            else
            {
                printf("Password is wrong!!\n");
            }
        }while(password!=789520);
        
    }
    else if (strcmp(choose, "academician")==0)
    {
        academician();   
    }
    else if (strcmp(choose, "officer")==0)
    {
        officer();   
    }
    else if (strcmp(choose, "student")==0)
    {
        student();   
    }
    else if (strcmp(choose, "dersyazdir")==0)
    {
        dersyazdir();
    }
    
     else
    {
        printf("Username or password is wrong!!");
    }
    return 0;
}

int admin()
{
    Admin a;
    FILE *fPtr;

    fPtr = fopen("info.txt", "w");
    for (int i=0; i<=3; i++)
	{
        printf("Please enter the %d. academician's name and surname\n", i+1);
		scanf(" %[^\n]%*c", a.ac_name);
        printf("Please enter the %d. academician's username\n", i+1);
		scanf(" %[^\n]%*c", a.ac_username);
        printf("Please enter the %d. academician's password\n", i+1);
		scanf(" %[^\n]%*c", a.ac_password);
        fprintf(fPtr, "%s,%s,%s\n", a.ac_name, a.ac_username, a.ac_password);
        printf("\n");
	}

    printf("Please enter the officer's name and surname\n");
	scanf(" %[^\n]%*c", a.of_name);
    printf("Please enter the officer's username\n");
	scanf(" %[^\n]%*c", a.of_username);
    printf("Please enter the officer's password\n");
	scanf(" %[^\n]%*c", a.of_password);
    fprintf(fPtr, "%s,%s,%s\n", a.of_name, a.of_username, a.of_password);
    printf("\n");

    fclose(fPtr);

    return 0;
}
int academician()
{
    char username[7]={};
    char password[7]={};
    Admin a;
    Student s;
    FILE *fptr;
    printf("Please enter the username\n");
    gets(username);
    printf("Please enter the password\n");
    gets(password);

    fptr = fopen("info.txt", "r");
    fscanf(fptr,"%[^,],%[^,],%s", a.of_name, a.ac_username, a.ac_password);
    if(strcmp(username, a.ac_username)==0 && strcmp(password, a.ac_password)==0)
    {
        printf("Hello");
    }
    else
    {
        printf("Username or password is wrong!!");
    }
    fclose(fptr);

    return 0;
}
int officer()
{
    char exit[2]={};
    char choose[30]={};
    Student s;
    Ac_les a;
    Admin ad;
    FILE *adptr;
    FILE *lesptr;
    FILE *acptr;

    printf("Please enter the selection..\n 1.Student Registration\n 2.Open Course\n");
    gets(choose);
    strlwr(choose);

    if(strcmp(choose, "student registration")==0)
    {
        adptr = fopen("student.txt", "w");
	    for (int i=0; i<=2; i++)
	    {
            printf("Please enter the name and surname\n");
		    scanf(" %[^\n]%*c", s.student_name);
            printf("Please enter the student's department name\n");
		    scanf(" %[^\n]%*c", s.department);
            printf("Please enter the student's username\n");
		    scanf(" %[^\n]%*c", s.st_username);
            printf("Please enter the student's password\n");
		    scanf(" %[^\n]%*c", s.st_password);
            fprintf(adptr, "%s,%s,%s,%s\n", s.student_name, s.department, s.st_username, s.st_password);
            printf("\n");
	    }
	    fclose(adptr);
    }

    else if(strcmp(choose, "open course")==0)
    {
        lesptr = fopen("lessons.txt", "w");
        acptr = fopen("info.txt", "r");
	    do{
            printf("Please enter the lessons name\n");
		    scanf(" %[^\n]%*c", a.lessons);
            printf("Please enter the term\n");
		    scanf("%d", &a.term);
            fprintf(lesptr, "%s,%d\n", a.lessons, &a.term);
            /*printf("Please choose an academician\n");
            for(int i=0; i<4;i++)
            {
                fscanf(acptr,"%[^,]\n%s", ad.ac_name);
                printf("%d. %s\n", i+1, ad.ac_name);
            }*/
            printf("Do you want to continue(YES[Y] or NO[N])\n");
		    scanf("%s", &exit);
            strlwr(exit);
            printf("\n");
	    } while(strcmp(exit, "y")==0);
        fclose(acptr);
	    fclose(lesptr);
    }

    return 0;
}
int student()
{
    char username[7]={};
    int password;
    char choose[30]={};

    printf("Please enter the username");
    gets(username);
    printf("Please enter the password");
    scanf("%d", &password);
    printf("Please enter the department name! Software Engineering, Computer Engineering, Mechatronics Engineering\n");
    gets(choose);
    strlwr(choose);

    if(strcmp(choose, "software engineering")==0)
    {
        
    }
    else if(strcmp(choose, "computer engineering")==0)
    {

    }
    else if(strcmp(choose, "mechatronics engineering")==0)
    {

    }
    else
    {
        printf("Department name is wrong!!\n");
    }


    return 0;
}

int dersyazdir()
{
    FILE *fPtr;
    Ac_les a;

    fPtr= fopen("lessons.txt", "r");

    while (!feof(fPtr))
    {
        fscanf(fPtr,"%[^,]\n%s",a.lessons);
        printf(" %s\n", a.lessons);
    }

    return 0;
}

