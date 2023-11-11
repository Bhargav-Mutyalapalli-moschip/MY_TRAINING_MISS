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


