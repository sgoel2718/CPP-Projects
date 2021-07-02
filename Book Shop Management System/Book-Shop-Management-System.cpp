#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Book{
	private:
		string author,title,publisher;
		float price;
		int stock;
	public:
		bool isLoggedIn();
		void inputData(string,string,string,float,int);
		void showData();
		void search(string);
		void buyBook(string);
};

bool isLoggedIn()
{
	string username,password,un,pw;
	cout<<"Enter Username: ";
	cin>>username;
	cout<<"Enter Password: ";
	cin>>password;
	
	ifstream read;
	read.open("registartion.txt");
	while(!read.eof())
	{
		getline(read,un);
		getline(read,pw);
	}
	
	
	if(un==username && pw==password)
	{
		return true;
	}
	else{
		return false;
	}
}

void Book::inputData(string author, string title, string publisher, float price, int stock){
//	cin.ignore();	
//	cout<<"\nEnter Author name: ";
//	getline(cin,author);
//	cout<<"Enter Book Title: ";
//	getline(cin,title);
//	cout<<"Enter Publisher name: ";
//	getline(cin,publisher);
//	cout<<"Enter Price: ";
//	cin>>price;
//	cout<<"Enter Stock: ";
//	cin>>stock;
	ofstream file;
	file.open("books.txt" ,ios::out | ios::app);
	file<<endl<<author<<endl<<title<<endl<<publisher<<endl<<price<<endl<<stock;
	file.close();
}

void Book::showData(){
	string auth,ti,pub;
	float cost;
	int valid;
	ifstream read;
	read.open("books.txt");
	while(!read.eof())
	{
		read>>auth>>ti>>pub;
		read>>cost;
		read>>valid;
		cout<<"\nAuthor Name: "<<auth;
		cout<<"\nBook Name: "<<ti;
		cout<<"\nPublisher Name: "<<pub;
		cout<<"\nPrice: "<<cost;
		cout<<"\nStock: "<<valid;
	}
}

void Book::search(string titleName){
	string auth,ti,pub;
	float cost;
	int valid;
	ifstream read;
	read.open("books.txt");
	while(!read.eof())
	{	
		read>>auth>>ti>>pub;
		read>>cost;
		read>>valid;
		if(ti==titleName)
			{
				cout<<"\nAuthor Name: "<<auth;
				cout<<"\nBook Name: "<<ti;
				cout<<"\nPublisher Name: "<<pub;
				cout<<"\nPrice: "<<cost;
				cout<<"\nStock: "<<valid;
				break;
			}
	}
	if(read.eof())
	{
		cout<<"Sorry! There is no such book in the stock...";
	}
	
}

void Book::buyBook(string titleName){
	string auth,ti,pub;
	float cost;
	int valid;
	ifstream read;
	read.open("books.txt");
	while(!read.eof())
	{	
		read>>auth>>ti>>pub;
		read>>cost;
		read>>valid;
		if(ti==titleName)
			{
				int count;
				cout<<"\nEnter number of books to buy: ";
				cin>>count;
				if(count<=valid)
				{
					valid-=count;
					cout<<"\nBooks purchased Successfully";
					cout<<"\nTotal Amount: "<<(cost)*count;
				}
				else
					cout<<"\nRequired books are not in stock";
						}
				}
}

int main()
{
	Book book;
login:
	int choice;
	cout<<"1: Register\n";
	cout<<"2: Login\n";
	cout<<"Your choice: ";
	cin >>choice;
	if(choice==1)
	{
		string username,password;
		cout<<"Create a Username: ";
		cin>>username;
		cout<<"Create a Password: ";
		cin>>password;
		
		ofstream file;
		file.open("registartion.txt");
		file<<username<<endl<<password;
		file.close();
		
		main();
	}
	else if(choice==2)
	{
		bool status=isLoggedIn();
		if(!status)
		{
			cout<<"Invalid Login"<<endl;
			system("PAUSE");
			return 0;
		}
		else{
			cout<<"Succedssfully Logged in"<<endl;
			Book book;
	int  i=0,r,t,choice;
		while(1)	{
		cout<<"\n\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Exit"
		<<"\n\nEnter your Choice: ";
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: {
				string auth,ti,pub;
				float cost;
				int valid;
				int i,n;
				cout<<"Enter number of books you want to Add in System: ";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"\nEnter Author name: ";
					cin>>auth;
					cout<<"\nEnter Title name: ";
					cin>>ti;
					cout<<"\nEnter Publisher name: ";
					cin>>pub;
					cout<<"\nEnter Cost: ";
					cin>>cost;
					cout<<"\nEnter Stock: ";
					cin>>valid;
					book.inputData(auth,ti,pub,cost,valid);
				}
				break;
			}
			case 2: {
				cout<<"Enter name of book to buy: ";
				string name;
				cin>>name;
				book.buyBook(name);
				break;
			}
			
			case 3: {
				cout<<"Enter Title of the Book You want to Search: ";
				string title;
				cin>>title;
				book.search(title);
				break;
			}
				
			case 4: exit(0);
			default: cout<<"\nInvalid Choice Entered";
		}
	}
		}
	}
}
