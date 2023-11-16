#include<iostream> using namespace std;
// Define a struct named Node to represent a contact. struct Node
{
string name; // Member variable to store the contact's name
long long int phone_number; // Member variable to store the contact's phone number. Node *next;// Pointer to the next contact (linked list).
Node *prev;// Pointer to the previous contact (doubly linked list).
};
class ContactBook
{
Node *head; string x;
long long int y; public:
//constructor to intialise the values.
ContactBook()
{
head=NULL; x="";
y=0;
}
void CreateNode()
{// Create a new node when the contact book is empty. if(head==NULL)
{
Node *newer= new Node; cout<<" Name of Contact: "; cin>>x;
 
newer->name=x;
cout<<" Phone Number: "; cin>>y;
newer->phone_number=y; newer->next=NULL; head=newer;
cout<<" Contact Added"<<endl;
}
else
// Create a new node when the contact book is not empty.
{
Node *newer= new Node; cout<<" Name of Contact: ";
cin>>x;
newer->name=x; cout<<" Phone Number: "; cin>>y;
newer->phone_number=y; newer->next=NULL;
//using a temporary pointer to transver the ll and add new node.
Node *temp=head; while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newer; newer->prev=temp;
cout<<" Contact Added"<<endl;
}
}
 
void Display()
{
Node *temp=head;// Start at the beginning of the contact book
int count=0;// we have Used this to show the no. of contact in the ll.
// If the contact book is empty if(temp==NULL)
{
cout<<" No Contacts... Please Add Some Contacts"<<endl;
}
else// If there are contacts in the book, sort them and display the list
{
BubbleSort();// Sort the contacts
cout<<" Name: "<<"	Number: \n"<<endl; while(temp!=NULL)
{
count++;
cout<<" "<<temp->name;
cout<<"	"<<temp->phone_number<<endl; temp=temp->next;
}
cout<<" Total contacts: "<<count<<endl;
}
}
void Search()
{
bool check=false;
Node *temp=head;
cout<<"***********"<<endl;
cout<<" Press 1 for Search By Name."<<endl; cout<<" Press 2 for Search By Number."<<endl;
 
int choice;
cout<<" Enter the Choice: "; cin>>choice;
if(choice==1 && temp!=NULL)
{
cout<<" Enter the Name to Search: ";
cin>>x;// Looping through the contact book to search by name. while(temp!=NULL)
{
if(temp->name==x)
{
cout<<" Name: "<<temp->name<<endl;
cout<<" Phone Number:"<<temp->phone_number<<endl; check=true;
break;
}
temp=temp->next;
}
if(check==false)
{
cout<<" Name Not Found"<<endl;
}
}
else if(choice==2)
{
cout<<" Enter the Number to Search: "; cin>>y;
// Loop through the contact book to search by phone number. while(temp!=NULL)
{
 
if(temp->phone_number==y)
{
cout<<" Name: "<<temp->name<<endl;
cout<<" Phone Number: "<<temp->phone_number<<endl; check=true;
break;
}
temp=temp->next;
}
if(check==false)
{
cout<<" Number Not Found"<<endl;
}
}
}
void DeleteAllContacts()
{
Node *temp=head;// Initialize a temporary pointer Node *temp2;// Another temporary pointer for deletion. if(head==NULL)
{
// If the contact book is already empty
cout<<" Already Contact Book is Empty"<<endl; cout<<"***********"<<endl;
}
else// If the contact book is not empty
{
while(temp!=NULL)
 
{
temp2=temp;// Store the current contact in temp2. temp=temp->next;// Move to the next contact. delete temp2;// Delete the contact stored in temp2.
}
head=NULL;
cout<<" Successfully Deleted All Contacts"<<endl; cout<<"Thanks For Using "<<endl;
}
}
void DeleteContactBySearch()
{


Node *temp=head;
cout<<" Press 1 for Search By name"<<endl; cout<<" Press 2 for Search By Number"<<endl; int command;
cout<<" Enter the Command: "; cin>>command; if(command==1)
{
bool Dcheck=false;
cout<<" Enter the Name to Delete: "; cin>>x;
while(temp!=NULL)
{
if(temp->name==x)
 
{
cout<<" Name: "<<temp->name<<endl;
cout<<" Phone Number: "<<temp->phone_number<<endl; Dcheck=true;
break;
}
temp=temp->next;
}
if(Dcheck==true)
{
int command;
cout<<" Press 1 to Delete the Contact: "; cin>>command;
if((command==1)&(temp==head))//if contact is the starting node
{
Node *temp1; temp1=temp; temp=temp->next; delete temp1;

 








the last node
 
temp->prev=NULL; head=temp;
cout<<" Contact Deleted Success Fully"<<endl;
}
else if((command==1)&(temp->next==NULL))//if contact is

{
temp->prev->next=NULL; delete temp;
cout<<" Contact Deleted Success Fully"<<endl;
 
}
else if(command==1)//if contact is the middle node
{
 










}
else
{


}
}
 
Node *temp1; temp1=temp;
temp->prev->next=temp1->next; temp->next->prev=temp1->prev; delete temp1;
cout<<" Contact Deleted Success Fully"<<endl;





cout<<" You Enter Wrong Command"<<endl;
 
else if(Dcheck==false)
{
cout<<" Contact of This Name Not Found."<<endl;//if
there is no contact by this name.
}
}
else if(command==2)
{
bool Dcheck=false;
cout<<" Enter the Number to Delete: "; cin>>y;
while(temp!=NULL)
{
if(temp->phone_number==y)
{
 
cout<<"name: "<<temp->name<<endl;
cout<<"Phone Number: "<<temp->phone_number<<endl; Dcheck=true;
break;
}
temp=temp->next;
}
if(Dcheck==true)
{
int command;
cout<<" Press 1 to Delete the Contact: "; cin>>command;
if((command==1)&(temp==head))//if contact is the starting node
{
Node *temp1; temp1=temp;
temp=temp->next; delete temp1;
temp->prev=NULL;
head=temp;
cout<<" Contact Deleted Success Fully"<<endl;
}
 

the last node
 
else if((command==1)&(temp->next==NULL))//if contact is

{
temp->prev->next=NULL; delete temp;
cout<<" Contact Deleted Success Fully"<<endl;
 
}
else if(command==1)//if contact is the middle node
 
{










}
else
{


}
}
 


Node *temp1; temp1=temp;
temp->prev->next=temp1->next; temp->next->prev=temp1->prev;
delete temp1;
cout<<" Contact Deleted Success Fully"<<endl;





cout<<" You Enter Wrong Command"<<endl;
 
else if(Dcheck==false)
{
 



}
else
{
 
cout<<" Contact of This Name Not Found."<<endl;
}
 

this phone number


}
 
cout<<" You Enter wrong Command"<<endl;//if there is no contact by

}
 
void BubbleSort()// we will check adjacent element if adjacent element is greater we will swap.
{
Node *temp=head;
Node *i,*j;
string n;
 
long long int n2;
if(temp==NULL)//if contact book is empty
{
cout<<" Empty contact Book"<<endl;
}
else//if contact book is not empty
{
for(i=head;i->next!=NULL;i=i->next)
{
for(j=i->next;j!=NULL;j=j->next)
{
if(i->name>j->name)
{
n=i->name;
i->name=j->name; j->name=n;

n2=i->phone_number;
i->phone_number=j->phone_number; j->phone_number=n2;
}
}
}
}
}




void EditContacts()
{
Node *temp=head; // Initialize a temporary pointer
 
cout<<" Press 1 for search By Name"<<endl; cout<<" Press 2 for search By Number"<<endl; int Ecommand;
cout<<" Enter the Command: "; cin>>Ecommand;

if(Ecommand==1)
{
 






the specified name.
 
bool Echeck=false;
cout<<" Enter the Name to Edit: "; cin>>x;
while(temp!=NULL)// Iterate through the contacts to find the one with

{
if(temp->name==x)
{
 
cout<<"***********"<<endl; cout<<"Name: "<<temp->name<<endl;
cout<<"Phone Number: "<<temp->phone_number<<endl; Echeck=true;
break;
}
temp=temp->next;
}
if(Echeck==true)
{
int command;
cout<<" Press 1 to Edit the Contact: "; cin>>command;
if(command==1)
 
{
cout<<" Enter New Name: "; cin>>x;
cout<<" Enter New Number: "; cin>>y;
// Update the contact's name and phone number with the new values. temp->name=x;
temp->phone_number=y;


cout<<" Contact Edited Success Fully"<<endl;
}
else
{
cout<<" You Enter Wrong Command ... Try
Again"<<endl;
}
}
else if(Echeck==false)
{
 

name.
 
cout<<" Contact Not Found"<<endl;//There is no contact by this

}
}
else if(Ecommand==2)
{
 
bool Echeck=false;
cout<<" Enter the Number to Edit: "; cin>>y;
while(temp!=NULL)// Iterate through the contacts to find the one with the specified phone number.
 
{
if(temp->phone_number==y)
{
cout<<"***********"<<endl; cout<<"Name: "<<temp->name<<endl;
cout<<"Phone Number: "<<temp->phone_number<<endl; Echeck=true;
break;
}
temp=temp->next;
}
if(Echeck==true)
{
int command;
cout<<" Press 1 to Edit the Contact: "; cin>>command;
if(command==1)
{
cout<<" Enter New Name: "; cin>>x;
cout<<" Enter New Number: "; cin>>y;
// Update the contact's name and phone number with the new values. temp->name=x;
temp->phone_number=y;


cout<<" Contact Edited Success Fully"<<endl;
}
else
{
cout<<" You Enter Wrong Command"<<endl;
 
}
}
else if(Echeck==false)
{
cout<<" There is No Contact of this Number."<<endl;// There is no contact by this phone number.
}
 
}
else





}
 



{
cout<<" You Enter Wrong Command Try Again"<<endl;
}
 
void Structure()
{
cout<<"	"<<endl;
cout<<" 1. Add Contact"<<endl; cout<<" 2. Edit the Contact"<<endl; cout<<" 3. Delete Contact"<<endl; cout<<" 4. Search Contact"<<endl; cout<<" 5. Display All Contacts"<<endl; cout<<" 6. Delete All Contacts"<<endl; cout<<"	"<<endl;

int Scommand;
cout<<" Enter the Command: "; cin>>Scommand;
try
{
if(Scommand>=1&&Scommand<=6)
 
{
if(Scommand==1)
{
CreateNode();// Execute the method to add a new contact.
Structure();// Present the menu again.
}
else if(Scommand==2)
{
EditContacts();// Execute the method to edit a contact. Structure();// Present the menu again.
}
else if(Scommand==3)
{
DeleteContactBySearch();// Execute the method to delete a contact. Structure(); // Present the menu again.
}
else if(Scommand==4)
{
Search(); // Execute the method to search for a contact. Structure();
}
else if(Scommand==5)
{
Display();// Execute the method to display all contacts. Structure();
}
else if(Scommand==6)// Execute the method to delete all contacts.
{
DeleteAllContacts(); Structure();
 




exception.
 
}
}
else // If the entered command is out of range, throw an

{
throw(Scommand);
}
}
 
catch(int Scommand)
{
 

Again"<<endl; again.
}


};
int main()
{
 
cout<<" You Enter wrong Command Run the Code Structure();// Handle the exception by presenting the menu
}
 
ContactBook cb;// Create an instance of the ContactBook class string n;// Declariung a stringto store the user's name. cout<<" What is Your Name: ";
cin>>n;


cout<<"DSA MINI PROJECT"<<endl;
cout<<" "<<n<<" WELCOME TO CONTACTBOOK	"<<endl;
cout<<"This thing makes our life easier"<<endl;
cb.Structure();// Call the Structure method of the ContactBook to start the contact book interface.
return 0;
}
