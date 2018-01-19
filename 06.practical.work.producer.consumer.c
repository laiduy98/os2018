#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 10

typedef struct {
	char type; 
	int amount; 
	char unit; 
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

item *newitem(char type,int amount,char unit){
	item *temp = malloc(sizeof(item));
	
	temp->type = type;
	temp->amount = amount;
	temp->unit = unit;
	return temp;
}

void printtest(){
	printf("first = %d, last = %d\n",first,last);
}

void produce(item *i) {
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

int main(){
	item *food;
	food = newitem(1,2,3);
	produce(food);
	printtest();
	food = newitem(6,7,8);
	produce(food);
	printtest();
	consume();
	printtest();
	return 0;
}
