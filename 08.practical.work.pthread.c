#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int pthread_create(
	pthread_t *thread,
	const pthread_attr_t *attr,
	void *(*start_routine) (void *),
	void *arg);

#define BUFFER_SIZE 10

typedef struct {
	char type; 
	int amount; 
	char unit; 
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while ((first + 1) % BUFFER_SIZE == last) {
		
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
		}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void printout(){
	printf("Value of first: %d\n",first);
	printf("Value of last: %d\n",last);
}

void *threadFunction(void *param) {
	item i1,i2,i3;

	i1.type = '0';
	i1.amount = 2;
	i1.unit = '0';

	i2.type = '1';
	i2.amount = 200;
	i2.unit = '1';

	i3.type = '0';
	i3.amount = 5;
	i3.unit = '0';
	produce(&i1);
	printout();
	produce(&i2);
	printout();
	produce(&i3);
	printout();
}

void *threadFunction2(void *param) {
	consume();
	printout();
	consume();
	printout();
}

int main(){
	pthread_t tid;
	pthread_create(&tid,NULL,threadFunction,NULL);
	pthread_join(tid, NULL);
	pthread_t tid1;
	pthread_create(&tid1,NULL,threadFunction2,NULL);
	pthread_join(tid1, NULL);
}