/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	}

    struct RandomListNode *H;
    struct RandomListNode *p = head, *q1, *q2;

    q1 = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
    q1->label = p->label;
    H = q1;

    p = p->next;

    int size = 1;
    while (p != NULL) {
    	q2 = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
    	q2->label = p->label;
    	q1->next = q2;
    	q1 = q2;
    	p = p->next;
       	size++;
    }

    struct RandomListNode *old_arr[size];
    struct RandomListNode *new_arr[size];

    int i = 0;
    for (p = head; p != NULL; p = p->next) {
    	p->label = i;
    	old_arr[i++] = p;
    }

    i = 0;
    for (p = H; p != NULL; p = p->next) {
    	new_arr[i++] = p;
    }

    for (i = 0; i < size; i++) {
    	new_arr[i]->random = new_arr[old_arr[i]->label];
    }

    for (i = 0; i < size; i++) {
    	old_arr[i]->label = new_arr[i]->label;
    }

    return H; 
}
