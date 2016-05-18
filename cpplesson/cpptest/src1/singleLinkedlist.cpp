//
// Single linked list program 
//
#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
}*head;

void insertNode( int data ){

	node *temp;
	node *addNode = new node;
	addNode->data = data;
	addNode->next = NULL;

	temp = head;
	if( temp != NULL ){
		while( temp->next != NULL ){
			temp = temp->next;
		}
		temp->next = addNode;
	}
	else{
		head = addNode;
	}
}

void display(){

	node* temp;
	temp = head;

	if( temp == NULL )
		cout << "No data inside !" << endl;

	while( temp != NULL ){
		cout << "Data : " << temp->data << endl;
		temp = temp->next;
	}
}

int length(){
	node *n;
	int c = 0;

	n = head;
	while( n != NULL ){
		n = n->next;
		c++;
	}
	return c;
}

void insert_position(){
	int pos = 0;
	node *addNode = new node;
	node *temp , *temp1;

	cout << "Enter data to add : ";
	cin  >> addNode->data;

	addNode->next = NULL;

	do{
		cout << "Enter position to add : ";
		cin  >> pos;

		if( pos > length() || pos < 0 ){
			cout << "Invalid length ! " << endl;
		}
	}while( pos > length() || pos < 0 );

		if( head == NULL ){
			head = addNode;
		}
		else{
			temp = head;
			for( int i = 1 ; i < pos - 1 ; i++ ){
				temp = temp->next;
			}
			temp1 = temp->next;
			temp->next = addNode;
			addNode->next = temp1;
		}
}

int main(){

	insertNode( 43 );
	insertNode( 42 );
	insertNode( 93 );
	insertNode( 100 );
	display();
	cout << "size : " << length() << endl;

	insert_position();

	display();

	cout << "size : " << length() << endl;

	//system( "pause" );
        cout << "Press Enter to exit" << endl;
        cin.ignore().get();   // C++ Pause command for Linux 

	return 0;
}

