#ifndef TELECOM_H
#define TELECOM_H

typedef struct Node {
    char message[50];
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} MessageList;

void initializeMessages(MessageList* messageList);
int isMessageEmpty(MessageList* messageList);
void sendMessage(MessageList* messageList, const char* message);
void receiveMessage(MessageList* messageList);
void printMessages(MessageList* messageList);
void deleteAllMessages(MessageList* messageList);

#endif  // TELECOM_H
