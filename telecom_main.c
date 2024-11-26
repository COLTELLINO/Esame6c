#include "telecom.h"
#include <stdio.h>

int main() {
    MessageList myMessageList;
    initializeMessages(&myMessageList);

    // Test dell'invio di messaggi
    sendMessage(&myMessageList, "Messaggio 1");
    sendMessage(&myMessageList, "Messaggio 2");
    sendMessage(&myMessageList, "Messaggio 3");

    // Test della ricezione di messaggi
    receiveMessage(&myMessageList);

    // Test della stampa dei messaggi
    printMessages(&myMessageList);

    // Test della cancellazione di tutti i messaggi
    deleteAllMessages(&myMessageList);

    

    return 0;
}
