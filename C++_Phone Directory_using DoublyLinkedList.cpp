//213060
//Muhammad Hassaan Nizaal
#include <iostream>
using namespace std;


class DoublyNode
{
	private:
		
		DoublyNode *next,*prev;
		string name;
		string cont;
	public:
	
		
		
		void setName(string n){
			name = n;
		}
		string getName(){
			return name;
		}
		void setContact(string c){
			cont = c;
		}
		string getContact(){
			return cont;
		}
	
		
		void setNext(DoublyNode *n){
			next = n;
		}
	
		DoublyNode* getNext(){
			return next;
		}
		void setPrev(DoublyNode *p){
			prev = p;
		}
		DoublyNode* getPrev(){
			return prev;
		}	
		
		
		Node()
		{
			name   = " ";
			cont = " ";
			next    = NULL;
			prev    = NULL;	
		}	
};
class List
{
	private:
		int size;
		DoublyNode *head;
		DoublyNode *current, *lastCurrent;
	public:
		List()
		{
			size = 0;
			head       = NULL;
			current    = NULL;
			lastCurrent = NULL;
		}
		
		void add(string n,string c);
		void deleteCont();
		void search();
		void edit();
		void print();
	
};

void List::add(string n, string c)
		{
			DoublyNode *newPtr = new DoublyNode();
			newPtr->setName(n);
			newPtr->setContact(c);
			if(head == NULL) 
			{
				newPtr->setNext(NULL);
				newPtr->setPrev(NULL);
				head        = newPtr;
				current     = newPtr;
				lastCurrent = newPtr;
				size++;
			}
			else 
			{
				newPtr->setNext(NULL);
				newPtr->setPrev(current);
				current->setNext(newPtr);
				lastCurrent = current;
				current     = newPtr;
				size++;
			}
		} 	
		
	void List :: print()
	{
			{
			if(head == NULL)
			{
				cout<<"Empty List"<<endl;
			}
			else
			{
				
				DoublyNode *temp = head;
				for(int i=0; i<size; i++)
				{
		    		cout<<"Contact# "<<i+1<<"  "<<endl;
		    		cout<<"Name of the Person    : "<<temp->getName()<<endl;
		    		cout<<"PhoneNumber : "<<temp->getContact()<<endl;
		    		cout<<endl;
					temp = temp->getNext();
				}
			}
		}			
		}	
	
	void List::deleteCont()
			{
			if(head == NULL)
			{
				cout<<"EMPTY!! "<<endl;
		
		
				
			}
			else
			{
				DoublyNode *temp = head;
				while(head != NULL)
				{
					head = head->getNext();
					delete temp;
					temp = head;
				}
				cout<<"DELETED!!  "<<endl;			    
					
			}
		}
	void List::edit	()
			{
		//	x:
			DoublyNode *ptr = head;
			string search,name,number;
			if(head == NULL)
			{
				cout<<"EMPTY!!"<<endl;

			  
			}
			else
			{
			
			    cout<<"Enter the name of the contact that you wish to EDIT: "<<endl;
				getline(cin, search);
				bool flag = false;
				while(ptr != NULL)
				{
					if(search == ptr->getName())
					{
						flag = true;
						cout<<"Enter Updated Name : "<<endl;
						getline(cin,name);
						ptr->setName(name);
						cout<<"Enter Updated Number : "<<endl;
						getline(cin,number);
						ptr->setContact(number);
					
						cout<<"Successfully Updated!!"<<endl;
					
						
					}
					ptr = ptr->getNext();
				}
				
			}
			
		}	
	
	void List::search()
		{
			DoublyNode *temp = head;
			string n;
		    if(head == NULL)
			{
				cout<<"NULL "<<endl;
			  
		    	
			}
			else
			{
				
			    bool flag = false;
			//	cin.ignore();
		   		cout<<"Enter The Name : ";
		    	getline(cin, n);
			    for(int i=0;i<size;i++)
			    {
		        	if(n==temp->getName())
		    		{
		    			flag = true;
		    			cout<<"Contact Number# "<<i+1<<endl;
		    			cout<<"Person Name    : "<<temp->getName()<<endl;
		    			cout<<"PhoneNumber: "<<temp->getContact()<<endl;

			    
					}
					temp = temp->getNext();
			   }
			   if(flag == false)
			   {

			    cout<<"NOT FOUND!! "<<endl;
			    cout<<endl;
			   }
			}
			
			
	    }

int main(){
	List l1;
	int choice;
	string n,c;
	do
	{
		
 		cout<<endl;
		cout<<"PHONEBOOK DIRECTORY"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"1--Add Contact "<<endl;
		cout<<"2--Search Contact "<<endl;
		cout<<"3--Delete Contact "<<endl;
		cout<<"4--Display all the contacts "<<endl;
		cout<<"5--Edit a contact "<<endl;
		cout<<endl;
		cout<<"Enter your choice  "<<endl;
		cin>>choice;
   		switch(choice)
		{
			case 1:
			{
				static int size;
				cin.ignore();
				cout<<"Contact# "<<++size<<" "<<endl;
				cout<<endl;
				cout<<"Enter the name of Person    : ";
				getline(cin,n);
				cout<<"Enter the PhoneNumber : ";
				getline(cin,c);
				l1.add(n,c);
				cout<<"Contact was saved successfuly "<<endl;
			    cout<<endl;
			    cout<<endl;
			
				break;
			}
			case 2:
			{
			
					l1.search();
				break;
			}
    		case 3:
    		{
				l1.deleteCont();
				break;
			
			}
			case 4:
			{
				l1.print();
				break;
			}
			case 5:
			{
				l1.edit();
				break;
			
			}
			
		}
	}while(choice != 6);
}
