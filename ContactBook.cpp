#include "ContactBook.h"
#include<string>
#include<iostream>
#include<ctime>
#include<cstdlib>

ContactList::ContactList(){ //creates constructor 
	head = NULL;
}

Node* ContactList::createContact(){ //creates node and returns it to use in addToBook function
	struct Node* newNode = new Node;
	std::cout<<"Enter first name: ";
	std::cin>>newNode->firstname;
	std::cout<<"Enter surname: ";
	std::cin>>newNode->lastname;
	std::cout<<"Enter day of contact's birthdate (1-31): ";
	std::cin>>newNode->birthdate[0];
	std::cout<<"Enter month of contact's birthdate (1-12): ";
	std::cin>>newNode->birthdate[1];
	std::cout<<"Enter day of contact's anniversary. Enter 0 if not married: ";
	std::cin>>newNode->annidate[0];
	std::cout<<"Enter month of contact's anniversary. Enter 0 if not married: ";
	std::cin>>newNode->annidate[1];
	newNode->next = NULL;
	return newNode;
}

Node* ContactList::getContact(){ //returns a node to use in other functions
	struct Node* searchNode = new Node;
	std::cout<<"Enter the first name of the contact to find: ";
	std::cin>>searchNode->firstname;
	std::cout<<"Enter the surname of the contact to find: ";
	std::cin>>searchNode->lastname;
	return searchNode;
}

void ContactList::editContact(){ //edit the information of a contact
	bool found = false;
	struct Node* searchNode = new Node;
	std::cout<<"Enter the first name of the contact to find: ";
	std::cin>>searchNode->firstname;
	std::cout<<"Enter the surname of the contact to find: ";
	std::cin>>searchNode->lastname;
	while(head!=NULL){
		if(head->firstname == searchNode->firstname && head->lastname == searchNode->lastname){
			found = true;
			break;
		}else{
			head = head->next;
		}
	}
	if(found = true){
		int option;
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"Contact Found! Please choose what you would like to edit: "<<std::endl;
		std::cout<<"1. Edit first name"<<std::endl;
		std::cout<<"2. Edit surname"<<std::endl;
		std::cout<<"3. Edit birthdate"<<std::endl;
		std::cout<<"4. Edit anniversary date"<<std::endl;
		std::cout<<"5. Go back to main menu"<<std::endl;
		std::cout<<"------------------------------------"<<std::endl;
		std::cin>>option;
		do{			
			switch(option){
				case 1:
					std::cout<<"Re-enter what you would like the new first name to be: ";
					std::cin>>head->firstname;
					std::cout<<"Contact first name changed to "<<head->firstname<<std::endl;
					std::cout<<"------------------------------------"<<std::endl;
					option = 5;
					break;
				case 2:
					std::cout<<"Re-enter what you would like the new surname to be: ";
					std::cin>>head->lastname;
					std::cout<<"Contact surname changed to "<<head->lastname<<std::endl;
					std::cout<<"------------------------------------"<<std::endl;
					option = 5;
					break;
				case 3:
					std::cout<<"Re-enter what you would like the new birth day to be(1-31): ";
					std::cin>>head->birthdate[0];
					std::cout<<"Re-enter what you would like the new birth month to be(1-12): ";
					std::cin>>head->birthdate[1];
					std::cout<<"Contact birth date changed to "<<head->birthdate[0]<<"/"<<head->birthdate[1]<<std::endl;
					std::cout<<"------------------------------------"<<std::endl;
					option = 5;
					break;
				case 4:
					std::cout<<"Re-enter what you would like the new anniversary day to be (1-31): ";
					std::cin>>head->annidate[0];
					std::cout<<"Re-enter what you would like the new anniversary month to be (1-12): ";
					std::cin>>head->annidate[1];
					std::cout<<"Contact anniversary date changed to "<<head->annidate[0]<<"/"<<head->annidate[1]<<std::endl;		
					option = 5;			
					break;
				case 5:
					option = 5;
					break;
				default:
					std::cout<<"Not a valid option"<<std::endl;
					option = 5;
					break;
			}
		}while(option!=5);
	}else{
		std::cout<<"That contact is not in the book "<<std::endl;
	}
	delete searchNode;
}

void ContactList::getBirthdayCard(){ //look at today's date and compare for possible birthdays
	struct Node* nodecompare = new Node;
	int todaysdate[2];
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	todaysdate[0] = local_time->tm_mday;
	todaysdate[1] = local_time->tm_mon + 1;
	std::string owner;
	std::cout<<"Who is this card from?: ";
	std::cin>>owner;
	bool marker = false;
	nodecompare = head;
	while(nodecompare!=NULL){
		if(todaysdate[0] == nodecompare->birthdate[0]){
			if(todaysdate[1] == nodecompare->birthdate[1]){
				marker = true;
				std::cout<<"------------------------------------"<<std::endl;
				std::cout<<"Dear "<<nodecompare->firstname<<","<<std::endl;
				std::cout<<"\n";
				std::cout<<"Hope your birthday is really wonderful and this coming year is the best yet!"<<std::endl;
				std::cout<<"\n";
				std::cout<<"From, "<<std::endl;
				std::cout<<"\n";
				std::cout<<owner<<'\n';
			}
		}
		nodecompare = nodecompare->next;
	}
	if(marker==false){
	std::cout<<"No birthdays today!"<<std::endl;		
	}
	delete nodecompare;		
}

void ContactList::getAnniversaryCard(){ //look at today's date and compare for possible anniversaries
	int todaysdate[2];
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	todaysdate[0] = local_time->tm_mday;
	todaysdate[1] = local_time->tm_mon + 1;
	std::string owner;
	std::cout<<"Who is this card from?: ";
	std::cin>>owner;
	bool marker;
	struct Node* nodecompare = new Node;
	nodecompare = head;
	while(nodecompare!=NULL){
		if(todaysdate[0] == nodecompare->annidate[0]){
			if(todaysdate[1] == nodecompare->annidate[1]){
				marker = true;
				std::cout<<"------------------------------------"<<std::endl;
				std::cout<<"Dear "<<nodecompare->firstname<<","<<std::endl;
				std::cout<<"\n";
				std::cout<<"Hope your anniversary is really special and that there are many more!"<<std::endl;
				std::cout<<"\n";
				std::cout<<"From, "<<std::endl;
				std::cout<<"\n";
				std::cout<<owner<<'\n';
			}
		}
		nodecompare = nodecompare->next;
	}
	if(marker==false){
	std::cout<<"No anniversaries today!"<<std::endl;		
	}
	delete nodecompare;
}

int ContactList::getLength(){ //gets length of the list
	int i=0;
	struct Node* curr = new Node;
	curr = head;
	while(curr!=NULL){
		curr = curr->next;
		i++;
	}
	return i;
}

Node* ContactList::swapFunc(struct Node* ptr1,struct Node* ptr2){ //swaps two nodes in the list
	struct Node* temp = ptr2->next;
	ptr2->next=ptr1;
	ptr1->next=temp;
	return ptr2;
}

void ContactList::bubbleSortLast(struct Node** headNode,int counter){
	struct Node** h;
	int i,j,swapped;
	for(i=0;i<=counter;i++){
		h = headNode;
		swapped = 0;
		for(j=0;j<counter-i-1;j++){
			struct Node* p1 = *h;
			struct Node* p2 = p1->next;
			if(p1->lastname > p2->lastname){
				//update links
				*h = ContactList::swapFunc(p1,p2);
				swapped = 1;
			}
			h = &(*h)->next;
		}
		if(swapped==0)
			break;
	}
}

void ContactList::bubbleSortFirst(struct Node** headNode,int counter){
	struct Node** h;
	int i,j,swapped;
	for(i=0;i<=counter;i++){
		h = headNode;
		swapped = 0;
		for(j=0;j<counter-i-1;j++){
			struct Node* p1 = *h;
			struct Node* p2 = p1->next;
			if((p1->firstname > p2->firstname) && (p1->lastname == p2->lastname)){
				//update links
				*h = ContactList::swapFunc(p1,p2);
				swapped = 1;
			}
			h = &(*h)->next;
		}
		//if no need to swap, break
		if(swapped==0)
			break;
	}
}

void ContactList::addToBook(Node* n){ //takes node returned by createContact as parameter and adds to book
	struct Node* curr = new Node;
	curr = head;
	//if book is empty
	if(head==NULL){
		head = curr = n;
		std::cout<<"Contact added at head"<<std::endl;
	} //if book is not empty
	else{
		n->next = head;
		head = n;
		ContactList::bubbleSortLast(&head,ContactList::getLength());
		ContactList::bubbleSortFirst(&head,ContactList::getLength());
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"Contact added"<<std::endl;
	}
}

void ContactList::delContact(){ //deletes specified  user
	struct Node* n = new Node;
	std::cout<<"Enter the first name of the contact to delete: ";
	std::cin>>n->firstname;
	bool found = false;
	std::cout<<"Enter the surname of the contact to delete: ";
	std::cin>>n->lastname;
	struct Node* trailer = head;
	struct Node* current = head->next;
	//if it is the only item in the list
	if(trailer->firstname==n->firstname&&trailer->lastname==n->lastname){
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"Contact "<<trailer->firstname<<" "<<trailer->lastname<<" deleted from the book\n";
		head = head->next;
	}else{ //if not the only item in the list
		while(current!=NULL){
			if(current->firstname==n->firstname&&current->lastname==n->lastname) //if we find a node equivalent to the input, break
				break;
			else{
				//list traversal
				trailer = current;
				current = current->next;
			}
		}
		if(current->firstname==n->firstname&&current->lastname==n->lastname){
			trailer->next=current->next;
			std::cout<<"------------------------------------"<<std::endl;
			std::cout<<"Contact "<<current->firstname<<" "<<current->lastname<<" deleted from the book\n";
			delete current;
		}else if(current==NULL){
			std::cout<<"That contact is not in the book!\n";
		}
	}
}

void ContactList::showContactInfo(){ //asks for a contact name and prints their information
	bool found = false;
	struct Node* searchNode = new Node;
	struct Node* curr = new Node;
	curr = head;
	std::cout<<"Enter the first name of the contact to find: ";
	std::cin>>searchNode->firstname;
	std::cout<<"Enter the surname of the contact to find: ";
	std::cin>>searchNode->lastname;
	while(curr!=NULL){
		if(curr->firstname == searchNode->firstname && curr->lastname == searchNode->lastname){
			found = true;
			break;
		}else{
			curr = curr->next;
			found = false;
		}
	}
	if(found == true){
		int option;
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"Contact Found!"<<std::endl;
		std::cout<<"First name: "<<curr->firstname<<std::endl;
		std::cout<<"Surname: "<<curr->lastname<<std::endl;
		std::cout<<"Birthday: "<<curr->birthdate[0]<<"/"<<curr->birthdate[1]<<std::endl;
		if(curr->annidate[0]==0&&curr->annidate[1]==0)
			std::cout<<"Anniversary: This contact is not married"<<std::endl;
		else{
			std::cout<<"Anniversary: "<<curr->annidate[0]<<"/"<<curr->annidate[1]<<std::endl;
		}
	}else{
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"That contact is not in the book "<<std::endl;
	}
	delete searchNode;
}

void ContactList::printBook(){ //print entire book
	if(head==NULL){
		std::cout<<"The book is empty!"<<std::endl;
	}else{
		struct Node* printer = new Node;
		printer = head;
		while(printer!=NULL){
			std::cout<<printer->firstname<<" "<<printer->lastname<<std::endl;
			printer = printer->next;
		}
		delete printer;
	}
}

