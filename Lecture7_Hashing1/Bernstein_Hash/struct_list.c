#include <stddef.h> // for NULL
#include <stdio.h> // for printf()
#include <stdlib.h> // for EXIT_SUCCESS
#include <string.h> // for strcmp()

#define NAME_LENGTH 256
#define PEOPLE 4

typedef struct person person_t;

struct person {
    char *name;
    int age;
    int height;
};

typedef person_t* person_p;

void person_print(person_p p) {
    printf("name=%s age=%dyears height=%dcm\n", p->name, p->age, p->height);
}


typedef struct node node_t;
typedef node_t* node_p;
// a node in a linked list of people
struct node {
    person_p person;
    node_p next;
};

// print all people in the list pointer to by head
// pre: true
// post: list of people printed to screen
void node_print(node_t *head) {
    for ( ; head != NULL; head = head->next)
        person_print(head->person);
}

// add a person to the list pointed to by head
// pre: head != NULL
// post (return == NULL AND failed to allocate memory for new linked list node)
//      OR (return == the new head of the list)
node_t * node_add(node_t *head, person_t *person) {
    node_p new_node = (node_p)malloc(sizeof(node_t));
    if(new_node == NULL)
        return NULL;
    new_node->person = person;
    new_node->next = head;

    return new_node;
}

// find person by name in list pointed to by head
// pre: head != NULL
// post (return == NULL AND name not found)
//      OR (return == node with person named name)
node_t * node_find_name(node_t *head, char *name) {
    for (; head != NULL; head = head->next) {
        if(strcmp(head->person->name, name) == 0)
            return head;
    }
    return NULL;
}

// delete a person by name in list pointed to by head
// pre: head != NULL
// post: return == the new head of the list
node_t * node_delete(node_t *head, char *name) {
    if(head == NULL)
        return NULL;

    node_p cur_node = head;
    if(cur_node->next == NULL)
        return strcmp(cur_node->person->name, name) == 0 ? NULL : head;
    if(strcmp(cur_node->person->name, name) == 0)
        return cur_node->next;

    while(cur_node->next){
        node_p next_node = cur_node->next;
        if(strcmp(next_node->person->name, name) == 0){
            cur_node->next = next_node->next;
            free(next_node);
            return head;
        }
        cur_node = next_node;
    }
    return head;
}


int main(int argc, char **argv) {
    // create two people and print them
    printf("two people:\n");
    // aaron
    person_t aaron = {"aaron", 52, 0};
    aaron.height = 154;
    person_print(&aaron);
    // beth
    person_t *beth = (person_t *)malloc(sizeof(person_t)); // allocate memory for beth on the free store
    if (beth == NULL) {
        printf("memory allocation failure\n");
        return EXIT_FAILURE;
    }
    beth->name = "beth";
    beth->age = 67;
    beth->height = 207;
    person_print(beth);
    printf("\n");

    // create an array of 4 people and print them
    person_t people[] = {aaron, *beth, {"charlie", 44, 188}, {"danika", 5, 72}};
    free(beth); // free memory allocated for beth, the pointer is now a dangling pointer
    beth = NULL; // set pointer to NULL so it is no longer a dangling pointer
    printf("an array of people:\n");

    for (int i = 0; i < 4; i++) {
        person_print(&people[i]);
    }
    printf("\n");
    // create an array of pointers to people containg the same people as the array
    printf("an array of pointers to people:\n");
    person_t *ppeople[] = {&people[0], &people[1], &people[2], &people[3]};
    for (int i = 0; i < PEOPLE; ++i) {
        person_print(ppeople[i]);
    }
    printf("\n");
    
    // create a linked list containing the same people as the array
    node_t *people_list = NULL;
    for (int i = 0; i < PEOPLE; ++i) {
        node_t *newhead = node_add(people_list, &people[i]);
        if (newhead == NULL) {
            printf("memory allocation failure\n");
            return EXIT_FAILURE;
        }
        people_list = newhead;
    }

    // print the linked list of people
    printf("a linked list of people:\n");
    node_print(people_list);
    printf("\n");

    // find a person in the list
    printf("searching for charlie:\n");
    node_t *find = node_find_name(people_list, "charlie");
    person_print(find->person);
    printf("\n");

    // remove the first person from the list
    printf("removing danika:\n");
    people_list = node_delete(people_list, "danika");
    node_print(people_list);
    printf("\n");

    // remove the last person from the list
    printf("removing aaron:\n");
    people_list = node_delete(people_list, "aaron");
    node_print(people_list);
    printf("\n");

    // remove the remaining people from the list
    printf("removing beth and charlie:\n");
    people_list = node_delete(people_list, "beth");
    people_list = node_delete(people_list, "charlie");
    node_print(people_list);
    printf("\n");

    return EXIT_SUCCESS;
}
