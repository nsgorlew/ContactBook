#include "ContactBook.cpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	ContactList Book;
	bool ferris_booler;
	do{
		int option;
		std::cout<<"------------------------------------"<<std::endl;
		std::cout<<"Welcome to ContactBook!"<<std::endl;
		std::cout<<"Please select an option: "<<std::endl;
		std::cout<<"1. Add new contact"<<std::endl;
		std::cout<<"2. Delete contact"<<std::endl;
		std::cout<<"3. Edit a contact"<<std::endl;
		std::cout<<"4. Check if anyone's birthday is today and generate a birthday card"<<std::endl;
		std::cout<<"5. Check if anyone's anniversary is today and generate an anniversary card"<<std::endl;
		std::cout<<"6. Show a contact's information"<<std::endl;
		std::cout<<"7. Print entire contact book"<<std::endl;
		std::cout<<"0. Exit program"<<std::endl;
		std::cout<<"------------------------------------"<<std::endl;
		std::cin>>option;
		std::cout<<"------------------------------------"<<std::endl;
		switch(option){
			case 1:
				Book.addToBook(Book.createContact());
				ferris_booler = false;
				break;
			case 2:
				Book.delContact();
				break;
			case 3:
				Book.editContact();
				break;
			case 4:
				Book.getBirthdayCard();
				break;
			case 5:
				Book.getAnniversaryCard();
				break;
			case 6:
				Book.showContactInfo();
				break;
			case 7:
				Book.printBook();
				break;
			case 0:
				ferris_booler = true;
				break;
			default:
				std::cout<<"Not a valid option"<<std::endl;
				ferris_booler = false;
		}
	}while(ferris_booler!=true);
	
	return 0;
}
