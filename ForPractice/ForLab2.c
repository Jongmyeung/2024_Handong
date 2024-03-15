// 22300587 leejongmyeung

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes
void saveAllClasses(struct st_class* c[], int csize); // Save all class list


int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0));
	int count = loadData(classes);
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.

	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class)); // 메모리 동적 할당
	
	while(1){
        printf(">> code number > ");
        scanf("%d", &(p->code));
		int check = 0;
        for(int i = 0; i < csize; i++){
            if((p->code) == c[i]->code){ // 중복된 코드를 확인하기 위한 반복문
                printf(">> Code duplicated! Retry.\n");
				check = 1;
			}
        }
		if(check == 0){
			break;
		}
    }

	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
    int check = 0;

    while(1){
        printf(">> Enter a code of class > ");
        scanf("%d", &code);
        
        // You must complete this section.
        for(int i = 0; i < csize; i++) // 수정하려고 하는 코드의 내용을 찾기 위한 반복문
            if(c[i]->code == code){
                p = c[i];
				check = 1;
            }
        if(check == 1)
            break;
        else{ // 존재하지 않는 수업의 코드가 입력된 경우
            printf("No such class.\n");
            check = 0;
        }
    }

	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");

}


// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){

	struct st_class p;
	int check = 0;
	int code, no;
	while(1){
		if(msize > 9){ // 자신이 apply한 class 수가 다 차있는지 검사하는 코드
			printf("Max!! You cannot apply more class\n"); 
			check = 1;
			break;
		}

		check = 0;
		printf(">> Enter a class code > ");
		scanf("%d", &(code));

		for(int i = 0; i < msize; i++) // 중복된 코드인지 확인하기 위한 반복문
			if(my[i] == code){
				printf("Code duplicated! Retry.\n");
				check = 1;
				break;
			}

		if(check == 1)
			continue; // 아래의 코드는 실행하지 않는다!!


		int checkExt = 0;
		for(int i = 0; i < csize; i++){ // 코드가 존재하는지를 판단하기 위한 반복문
			if(c[i]->code == code){
				p = *(c[i]);
				my[msize] = (p.code);
				msize++;
				checkExt= 1;
				break;
			}
		}

		if(checkExt != 1){
			printf("No such code of class.\n");
			continue; // 아래의 코드는 실행하지 않는다!!
		}

		printf(">> [%d] %s [credits %d - %s]\n",p.code, p.name, p.unit, kname[p.grading-1]);
		printf(">> Add more?(1:Yes 2:No) > ");
		scanf("%d", &no);
		if(no == 2){
			break;
		}

	}
	
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){

	int sumOfCredit = 0;
	for(int i = 0; i < msize; i++){
		for(int j = 0; j < csize; j++){
			if(c[j]->code == my[i]){ // 출력하려고 하는 내용을 담고 있는 코드를 if문으로 검사해서 출력
				sumOfCredit += c[j]->unit;
				printf("%d. [%d] %s [credits %d - %s]\n", i + 1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
				break;
			}
		}
	}
	printf("All : %d credits\n", sumOfCredit);
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){

	FILE* file;
	file = fopen("my_classes.txt", "w");
	int total_class = 0, total_credit = 0, total_grading1 = 0, total_grading2 = 0; // 각 결과값에 맞는 변수 설정
	fprintf(file, "My Classes\n");
	for(int i = 0; i < msize; i++){
		for(int j = 0; j < csize; j++){
			if(my[i] == c[j]->code){ 
				fprintf(file, "%d. [%d] %s [credits %d - %s]\n", i + 1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
				total_class++;
				total_credit += c[j]->unit;
				if(c[j]->grading == 1){
					total_grading1+=c[j]->unit;
				} else {
					total_grading2+=c[j]->unit;
				}
			}
		}
	}
	fprintf(file, "All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n", total_class, total_credit, total_grading1, total_grading2);
	fclose(file);
}