//structure definition
struct node 
{
	int data;
	struct node *link;
};
//The push operation//
void push_operation(int num);
//The pop operation
void pop_operation();
//The display stck
void display_stack();
//The count stack data
void count_stack();
//The search operation
int search_stack(int num);
//reverse the stack
void reverse_stack();
//create a stack
void create_stack(int *iptr,int num);
//delete particulara data
void delete_particular_stack(int num);
//add after a data in the stack
void add_after_data(int num,int var);
//add before a data in the stack
void add_before_data(int num,int var);
//swap the data
void swap_data(int num1,int num2);
//swap the data by links
void swap_link(int num1,int num2);
//Delete duplicates
void delete_duplicates();
//delte stack
void delete_stack();


