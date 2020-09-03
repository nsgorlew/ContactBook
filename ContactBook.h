#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H
#include<iostream>

struct Node{
	std::string firstname;
	std::string lastname;
	int birthdate[2];
	int annidate[2];
	Node* next = NULL;
};
class ContactList{
	private:
		Node* head;
	public:
		ContactList(); //constructor
		Node* createContact(); //prompts for user input and creates new contact node.....maybe auto-gen keys?
		Node* getContact(); //prompts for user input for info
		void editContact(); //prompts for a contact to search for and edit their information
		void getBirthdayCard(); //gets current date and if it finds someone with today as bday, will generate a card
		void getAnniversaryCard(); //gets current date and if it finds someone with today as anniversary, will generate a card
		void showContactInfo(); //prompts for user input and if it finds someone with matching information, displays that contact's info
		void addToBook(Node* n); //takes a node as a parameter and adds it to the linked list
		void delContact(); //takes a node as a parameter and deletes it from the linked list
		void printBook(); //will print address book with keys
		void giveInfo(); //takes a key as input as then searches for that key and gives that contact's name
		int getLength(); //get length of linked list
		void bubbleSortLast(struct Node** headNode,int counter); //bubble sorts by last name
		void bubbleSortFirst(struct Node** headNode,int counter); //bubble sorts by first name after sorted by surname
		Node* swapFunc(struct Node* ptr1,struct Node* ptr2); //swaps two nodes in the list

};
#endif
