#include "telecom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeMessages(MessageList* messageList) {
    messageList->head = NULL;
}

int isMessageEmpty(MessageList* messageList) {
    return messageList->head == NULL;
}

void sendMessage(MessageList* messageList, const char* message) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Errore: impossibile allocare memoria per il nuovo messaggio.\n");
        return;
    }

    if (strcpy_s(newNode->message, sizeof(newNode->message), message) != 0) {
        printf("Errore: impossibile copiare il messaggio nella lista.\n");
        free(newNode);
        return;
    }

    if (messageList->head == NULL) {
        // Lista vuota
        newNode->prev = newNode;
        newNode->next = newNode;
        messageList->head = newNode;
    }
    else {
        // Inserimento in coda
        newNode->prev = messageList->head->prev;
        newNode->next = messageList->head;
        messageList->head->prev->next = newNode;
        messageList->head->prev = newNode;
    }

    printf("Messaggio inviato: %s\n", message);
}

void receiveMessage(MessageList* messageList) {
    if (isMessageEmpty(messageList)) {
        printf("Errore: la lista dei messaggi è vuota. Impossibile ricevere messaggi.\n");
        return;
    }

    Node* firstNode = messageList->head;
    Node* lastNode = messageList->head->prev;

    if (firstNode == lastNode) {
        // Unico elemento nella lista
        messageList->head = NULL;
    }
    else {
        // Rimozione dalla testa
        firstNode->next->prev = lastNode;
        lastNode->next = firstNode->next;
        messageList->head = firstNode->next;
    }

    printf("Messaggio ricevuto: %s\n", firstNode->message);
    free(firstNode);
}

void printMessages(MessageList* messageList) {
    if (isMessageEmpty(messageList)) {
        printf("La lista dei messaggi è vuota.\n");
        return;
    }

    Node* currentNode = messageList->head;
    do {
        printf("Stampa Messaggi: %s\n", currentNode->message);
        currentNode = currentNode->next;
    } while (currentNode != messageList->head);
}

void deleteAllMessages(MessageList* messageList) {
    while (!isMessageEmpty(messageList)) {
        receiveMessage(messageList);
    }

    printf("Tutti i messaggi sono stati cancellati.\n");
}
