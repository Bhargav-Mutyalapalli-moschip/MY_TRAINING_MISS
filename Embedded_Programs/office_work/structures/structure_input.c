#include<stdio.h>
#include<string.h>
struct company_employee
{
	char company[40];
	char employee[40];
	unsigned int id_no;
	char gender;
	char grade;
};
int main()
{
	struct company_employee e;
	e={"moschip","pranav",22,'M','T'};
	printf("The company name address:%p-------The company variable size:%ld--------The company name:%s\n",e.company,sizeof(e.company),e.company);
	printf("The employee name address:%p-------The employee variable size:%ld--------The employee name:%s\n",e.employee,sizeof(e.employee),e.employee);
	printf("The id_no  address:%p-------The id_no variable size:%ld--------The id_no name:%d\n",&e.id_no,sizeof(e.id_no),e.id_no);
	printf("The gender address:%p-------The gender variable size:%ld--------The gender type:%c\n",&e.gender,sizeof(e.gender),e.gender);
	printf("The grade name address:%p-------The grade variable size:%ld--------The grade type:%c\n",&e.grade,sizeof(e.grade),e.grade);
	printf("Override\n");
	strcpy(e.company,"Moschip technologies");
	strcpy(e.employee,"M.B.R.Pranav");
	scanf("%d",&e.id_no);
	__fpurge(stdin);
	scanf("%c",&e.gender);
	__fpurge(stdin);
	scanf("%c",&e.grade);
	printf("All the data received let's print\n");
	printf("The company name address:%p-------The company variable size:%ld--------The company name:%s\n",e.company,sizeof(e.company),e.company);
	printf("The employee name address:%p-------The employee variable size:%ld--------The employee name:%s\n",e.employee,sizeof(e.employee),e.employee);
	printf("The id_no  address:%p-------The id_no variable size:%ld--------The id_no name:%d\n",&e.id_no,sizeof(e.id_no),e.id_no);
	printf("The gender address:%p-------The gender variable size:%ld--------The gender type:%c\n",&e.gender,sizeof(e.gender),e.gender);
	printf("The grade name address:%p-------The grade variable size:%ld--------The grade type:%c\n",&e.grade,sizeof(e.grade),e.grade);
}


