#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

bool LinkedList::swap(int pos1, int pos2) {

}

bool LinkedList::find_and_delete(int target) {
	if  (!(LinkedList.empty()))
            Node* currNode = head; //start from header noded
            bool found = false;
            while (currNode->link->data != nullptr) {
                if (currNode->link->data == target) {
                    found = true;
                    break;
                }
                currNode = currNode->next;
            }
            if (found) {
                // node found delete it
                Node *node = currNode->next; //copy curr->next to properly delete it
                // point around unneeded node
                currNode->next = curr->next->next;
                delete currNode->next;
            }
}