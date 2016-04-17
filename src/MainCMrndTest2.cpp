/*
***********************
Comment the Printfs  you used in the Problems before you submit,as Printf might lead to timeouts in large 
cases as I/O is costly operation than CPU operations.
***********************
Do Read All questions carefully ,before writing any Code .
Make sure you submit the Code you have written through tool ,
before the submit window Closes .
*****************
Note : Make sure your MSBuild Suceeds before you submit ,or else It will lead to 0 marks .
->If you are stuck on a question or a particular Test case
is failing , Do Solve the Next question .As long as you click on submit at correct time,
your submissions are safe .
**************
There are only Sample Test Cases provided .Your code will also be graded
using Test cases on our end ,So Do think about testcases in all possible ways .
Your score will totally be based on the number of TestCases your programs
have passed on our end ,so if your code just passes sample cases
and fails all testcases at our end ,you will get you 0 marks .
******************
You can fill in the Helper Functions and make use of it
if you want to test from MainMrndCTest2.cpp
******************
All the Best .
*/

#include <stdlib.h>
#include <stdio.h>
#include "FunctionHeadersMrndTest2.h"


struct oddevennode{
	int data;
	struct oddevennode * next;
	struct oddevennode * random;
};

struct node{
	int data;
	struct node *left;
	struct node *right;
};

//Helper Functions Start


//Helper Functions End
struct oddevennode * createNode1(int num) {
	struct oddevennode *newNode = (struct oddevennode *)malloc(sizeof(struct oddevennode));
	newNode->data = num;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}
void addNode1(struct oddevennode **head, int data){
	struct oddevennode * cur = createNode1(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct oddevennode *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}
int * oddeven_sll1(struct oddevennode *head){

	if (head == NULL)return NULL;
	//oddMod(head);

	struct oddevennode* oddtempfast = head->next;
	struct oddevennode* oddtempslow = head;
	
	//Below code is for setting odd random pointers
	if (oddtempslow->data % 2 != 0){

		printf("loop");
		while (oddtempfast->next != NULL){
			printf("loop");
			if (oddtempfast->data % 2 != 0){
				oddtempslow->random = oddtempfast;
				//oddtempslow->next = oddtempslow->random;
				//struct oddevennode* temp = oddtempslow;
				while (oddtempslow->random != NULL)oddtempslow = oddtempslow->random;
			}
			oddtempfast = oddtempfast->next;

		}
	}
	else{
		oddtempfast = head->next;
		oddtempslow = head;
		while (oddtempslow->data % 2 == 0)oddtempslow = oddtempslow->next;
		while (oddtempfast->next != NULL){
			if (oddtempfast->data % 2 != 0){
				oddtempslow->random = oddtempfast;
				//oddtempslow->next = oddtempslow->random;
				//struct oddevennode* temp = oddtempslow;
				while (oddtempslow->random != NULL)oddtempslow = oddtempslow->random;
			}
			oddtempfast = oddtempfast->next;

		}
	}
	//below code is for setting even random pointers
	oddtempfast = head->next;
	oddtempslow = head;
	if (oddtempslow->data % 2 == 0){
		while (oddtempfast->next != NULL){
			if (oddtempfast->data % 2 == 0){
				oddtempslow->random = oddtempfast;
				//oddtempslow->next = oddtempslow->random;
				//struct oddevennode* temp = oddtempslow;
				while (oddtempslow->random != NULL)oddtempslow = oddtempslow->random;
			}
			oddtempfast = oddtempfast->next;

		}
	}
	
	else
	{
		oddtempfast = head->next;
		oddtempslow = head;
		while (oddtempslow->data % 2 != 0)oddtempslow = oddtempslow->next;
		while (oddtempfast->next != NULL){
			if (oddtempfast->data % 2 != 0){
				oddtempslow->random = oddtempfast;
				//oddtempslow->next = oddtempslow->random;
				//struct oddevennode* temp = oddtempslow;
				while (oddtempslow->random != NULL)oddtempslow = oddtempslow->random;
			}
			oddtempfast = oddtempfast->next;
			printf("loop");
		}
	}
	int a[] = { 0, 0 };
	printf("%d", a[0]);
	struct oddevennode* temp = head;
	for (; temp->next != NULL; temp = temp->next){
		if (temp->data % 2 != 0)a[0]++;
		else a[1]++;

		
	}
	
	return a;
}

int main(){
	
	//Test Odd Even SLL

	//Test CommonRoute

	//MangoCollector
	
	//Test Pillars
	struct oddevennode *head = NULL;
	int nums[20] = { 10, 3, 6, 5, 8, 1, 3 };
	int odds_expected[20] = { 3, 5, 1, 3 };
	int evens_expected[20] = { 10, 6, 8 };
	int ans[2] = { 4, 3 };
	int check = 0, check2 = 0, check3 = 0;

	int totallen = ans[0] + ans[1];
	for (int i = totallen - 1; i >= 0; i--){
		addNode1(&head, nums[i]);
	}
	int *res = oddeven_sll1(head);
	printf("%d", head->data);
	printf("%d", res[0]);
	getchar();
	return 0;
}