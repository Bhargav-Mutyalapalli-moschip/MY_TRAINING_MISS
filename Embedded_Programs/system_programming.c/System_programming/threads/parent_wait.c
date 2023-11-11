#include<stdio.h>
#include<pthread.h>
void *child(void *arg) {
	 printf("child\n");
	 printf("child1\n");
	 printf("child2\n");
	 printf("child2\n");
	 //how to indicate we are done?
		 return NULL;
}
	
int main(int argc, char *argv[]) {
	printf("parent: begin\n");
	pthread_t c;
	pthread_create(&c, NULL, child, NULL); // create child
					       // how to wait for child?
        printf("parent: end\n");
        printf("1parent: end\n");
        printf("2parent: end\n");
        printf("3parent: end\n");
	return 0;
//	pthread_exit(NULL);
        //exit(0);
}
