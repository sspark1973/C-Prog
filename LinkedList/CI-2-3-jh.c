#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	char data;
	struct List *next;
} List;


List * s_to_l(char s[]) {
	List *head;

	if (s[0] == '\0') return NULL;
	head = malloc(sizeof(List));
	head->data=s[0];
	head->next=s_to_l(s+1);
	return head;
}

void printList(List *head) {
	if (head == NULL)
		printf("NULL\n");
	else {
		printf("%c->", head->data);
		printList(head->next);
	}
}

void deleteMiddleNode(List *head) {
	int middle, cnt=0, i;
	List *curPos = head, *bg=head,*middleNode;

	for ( ; bg != NULL ; bg = bg->next)
		++cnt;
	middle = cnt/2;
	printf("cnt = %d\n",middle);
	for( i = 0; curPos != NULL; curPos = curPos->next, i++) {
		if (i == middle-1) {
			middleNode = curPos->next;	
			curPos->next = curPos->next->next;
			free(middleNode);
			break;
		}
		
	}
}

main() {
	char ch[6]={'a','b','c','d','e','\0'};
	List *head;
	head = s_to_l(ch);
	printList(head);
	deleteMiddleNode(head);
	printList(head);
}
