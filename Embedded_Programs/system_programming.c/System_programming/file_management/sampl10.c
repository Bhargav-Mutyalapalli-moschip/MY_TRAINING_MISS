#include <stdio.h>
#include <string.h>
struct struct_example
{
int integer;
char name[20];
};
union union_example
{
char name[20];
int integer;
};
void main()
{
struct struct_example s={18,"moschip"};
union union_example u={"moschip",18};
printf("structure data:\n integer: %s\n name: %d\n",s.name,s.integer);
printf("\nunion data:\n integer: %s\n name: %d\n",u.name,u.integer);
printf("\nsize of structure :%ld\n", sizeof(s));
printf("size of union : %ld\n", sizeof(u));
printf("\n Accessing one member at time:\n");
printf("\nstructure data:");
s.integer = 240;
printf("\ninteger: %d", s.integer);
strcpy(s.name, "embedded");
printf("\nname: %s\n", s.name);
printf("\n union data:");
u.integer = 240;
printf("\ninteger: %d", u.integer);
strcpy(u.name, "embedded");
printf("\nname: %s\n", u.name);
}

