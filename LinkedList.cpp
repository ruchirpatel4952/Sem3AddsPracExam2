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
	if (pos1 == pos2) return true; // No need to swap the same position
    Node *node1 = head, *node2 = head, *prev1 = nullptr, *prev2 = nullptr;
    int count = 0;
    while (node1 != nullptr && count != pos1) {
        prev1 = node1;
        node1 = node1->link;
        count++;
    }
    count = 0;
    while (node2 != nullptr && count != pos2) {
        prev2 = node2;
        node2 = node2->link;
        count++;
    }
    if (node1 == nullptr || node2 == nullptr) return false; // One of the positions is out of bounds
    if (prev1 != nullptr) prev1->link = node2;
    else head = node2;
    if (prev2 != nullptr) prev2->link = node1;
    else head = node1;
    Node *temp = node1->link;
    node1->link = node2->link;
    node2->link = temp;
    return true;
}

bool LinkedList::find_and_delete(int target) {
	if (head == nullptr) return false;
    Node* currNode = head;
    Node* prevNode = nullptr;
    while (currNode != nullptr && currNode->data != target) {
        prevNode = currNode;
        currNode = currNode->link;
    }
    if (currNode == nullptr) return false; // Target not found
    if (prevNode != nullptr) prevNode->link = currNode->link;
    else head = currNode->link;
    delete currNode;
    return true;
}