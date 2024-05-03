#include <iostream>

using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		void insertToHead(char data){
			Node *node = new Node();
			node->id = data;
			
			if(head == NULL){
			    head = tail = node;
			} else {
			    node->next = head;
			    head = node;
			}
		}
		void insertToTail(char data){
			Node *node = new Node();
			node->id = data;
			
			if(head == NULL){
			    head = tail = node;
			} else {
			    tail->next = node;
			    tail = node;
			}
		}
		void traversal(){
			Node *tmp = head;
			while(tmp != NULL){
				cout << tmp->id << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
};
int main(int argc, char** argv) {
	
	LinkedList *list1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	
	list1->head = node1;
	list1->tail = node1;
	
	Node *node2 = new Node();
	node2->id = 'B';
	
	list1->head->next = node2;
	list1->tail = node2;
	
	cout << list1->head->id << endl;
	cout << list1->head->next->id << endl;
	
	Node *nodeX = new Node();
	nodeX->id = 'X';
	
	Node *tmp = list1->head->next;
	list1->head = nodeX;
	nodeX->next = tmp;
	
	list1->insertToTail('C');
	list1->insertToTail('D');
	
	list1->traversal();
	
	return 0;
}
