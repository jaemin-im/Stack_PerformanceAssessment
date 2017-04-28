#include <stdio.h>
#define SIZE 10 // SIZE를 10으로 고정
#define OUTPUTSIZE SIZE*SIZE // OUTPUTSIZE를 SIZE의 제곱으로 고정
int InPointer = -1, OutPointer = 0, InStack[SIZE], OutStack[OUTPUTSIZE]; // 전역변수 설정
int Push(int item) {
	if (InPointer >= SIZE-1) { 
		printf("OVERFLOW\n\n");
		return 0;
	} // top이 SIZE-1보다 크거나 같을 경우 OVERFLOW 출력 후 return
	else { 
		++InPointer;
		InStack[InPointer] = item;
		return 0;
	} // 아닐 경우 top을 늘려서 item을 stack에 입력시키고 return
}
int Pop(int item) {
	if (InPointer == -1) { 
		printf("UNDERFLOW\n\n");
		return 0;
	} // top이 -1일 경우 UNDERFLOW 출력 후 return
	else {
		--InPointer;
		return InStack[InPointer+1];
	} // 아닐 경우 top을 줄이고 원래 값이었던 stack[top+1]을 return
}
void StackPrint() {
	int i; // for문에 사용하는 변수 i 선언
	printf("STACK [ ");
	for (i = 0; i <= InPointer; i++) {
		printf("%d ", InStack[i]); // InStack 원소 전부 출력
	}
	printf("]\nOUTPUT [ ");
	for (i = 0; i < OutPointer; i++) {
		printf("%d ", OutStack[i]); // OutStack 원소 전부 출력
	}
	printf("]\n");
}
void main(void) {
	int item, i, temp; // 지역변수 선언
	printf("STACK PROGRAM\nINPUT INTEGER TO PUSH\nINPUT 9999 TO POP\nINPUT 8888 TO END\nMAXIMUM STACK SIZE IS 10\nMAXIMUM OUTPUT STACK SIZE IS 100\n==============================\n");
	StackPrint(); // StackPrint 함수 호출
	for (;;) { // 무한반복
		printf("INPUT : ");
		scanf("%d", &item); // item 입력
		printf("\n");
		if (item == 9999) { // item이 9999일 경우 Pop
			if (InPointer != -1) {
				OutStack[OutPointer] = Pop(item); // InPointer가 -1이 아닐 경우 OutStack에 Pop(item)의 결과값 전달
				OutPointer++;
			} else {
				Pop(item); // InPointer가 -1일 경우 0이 전달되는 것을 방지하기 위해 Pop만 호출
			}
			StackPrint(); // StackPrint 함수 호출
		} else if (item == 8888) { // item이 8888일 경우 종료
			return 0;
		} else {
			Push(item); // 이외의 경우 Push함수 호출 후 StackPrint 함수 호출
			StackPrint();
		}
	}
}