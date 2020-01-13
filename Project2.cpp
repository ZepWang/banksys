// name: Zeping Wang
// filename: Project1.cpp
// due date: 12/07/2018
// problem: Design a bank program.


#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>
using namespace std;

class Account{
public:
   string clientName;
   string accountNumber;
   string accountType;
   int balance;
};
class Admain{
    public:
   string username;
   string password;
};
class BranchStaff{
public:
   string username;
   string password;
};
class Client{
public:
   string name;
   string address;
   string socialSecurityNumber;
   string employer;
   string annualIncome;

};

using namespace std;

vector<Admain>admains;
vector<BranchStaff>branchstaffs;
vector<Client>clients;
vector<Account>accounts;
void readFile();
void saveFile();
void clientAndAccount();
void addBranchStaff();
void deleteBranchStaff();
void displayStaff();
void addClient();
void addAccount();
void editClient();
void manageAccount();
void saveClientAndAccount();
void changePassword(string name,string password,int type);
int judgeCorrentAccount(string username,string password);

int main() {
   
   readFile();
   while(true){
      cout << endl;
      cout<<"==================================================="<<endl;
      cout<<"|   Welcome to the Auburn Branch of Tiger Bank!   |"<<endl;
      cout<<"==================================================="<<endl;
      cout<<"1) Login"<<endl;
      cout<<"2) Quit"<<endl;
      cout<<"  Please choose an option: ";
      string choice;
      cin>>choice;
      int type;
      string username;
      string password;
      if (choice=="2")
         break;
      if (choice=="1"){
      
         while(true){
            cout<< endl;
            cout<<"==================================================="<<endl;
            cout<<"|   Login to Access the Teller Terminal System    |"<<endl;
            cout<<"==================================================="<<endl;
            cout<<"User Name: ";
         
            cin>>username;
            cout<<"Password: ";
            cin>>password;
            type=judgeCorrentAccount(username,password);
            if (type==0){
               cout<<"The user name or password is incorrect.Try again!"<<endl;
            }
            else{
               break;
            
            }
         }
         if (type==1){
            
            while(true){
               cout << endl;
            cout<<"==================================================="<<endl;
            cout<<"|  Teller Terminal System - System Administration  |"<<endl;
            cout<<"==================================================="<<endl;
               cout<<"1) Client and Account Management"<<endl;
               cout<<"2) Add a branch staff member"<<endl;
               cout<<"3) Delete a branch staff member"<<endl;
               cout<<"4) Display branch staff"<<endl;
               cout<<"5) Change password"<<endl;
               cout<<"6) Exit"<<endl;
               cout<<"Please choose an option: ";
               int choice;
               cin>>choice;
               int f1=0;
               switch(choice){
                  case 1:
                     clientAndAccount();
                     break;
                  case 2:
                     addBranchStaff();
                     break;
                  case 3:
                     deleteBranchStaff();
                     break;
                  case 4:
                     displayStaff();
                     break;
                  case 5:
                     changePassword(username,password,1);
                     break;
                  case 6:
                     f1=1;
                     break;
                  default:
                     cout<<"Please input again!"<<endl;
                     break;
               }
               if (f1==1)
                  break;
            
            }
         }
         else{
            while(true){
               cout<<"1) Client and Account Management"<<endl;
               cout<<"2) Change Password"<<endl;
               cout<<"3) Exit"<<endl;
               cout<<"Please choose an option: ";
               int choice;
               cin>>choice;
               int f1=0;
               switch(choice){
                  case 1:
                     clientAndAccount();
                     break;
                  case 2:
                     changePassword(username,password,2);
                     break;
                  case 3:
                     f1=1;
                     break;
                  default:
                     cout<<"Please input again!"<<endl;
                     break;
               
               }
               if (f1==1)
                  break;
            }
         
         }
      }
   }
   saveFile();
   
}
void clientAndAccount(){

   while(true){
      cout<< endl;
      cout<<"==========================================================="<<endl;
      cout<<"|  Teller Terminal System - Client and Account Management |"<<endl;
      cout<<"==========================================================="<<endl;
      cout<<"1) Add a client"<<endl;
      cout<<"2) Add an account"<<endl;
      cout<<"3) Edit Client Information"<<endl;
      cout<<"4) Manage an account"<<endl;
      cout<<"5) Save client and account information"<<endl;
      cout<<"6) Exit"<<endl;
      cout<<"Please choose an option: ";
      int choice;
      cin>>choice;
      int f1=0;
      switch(choice){
         case 1:
            addClient();
            break;
         case 2:
            addAccount();
            break;
         case 3:
            editClient();
            break;
         case 4:
            manageAccount();
            break;
         case 5:
            saveClientAndAccount();
            break;
         case 6:
            f1=1;
            break;
         default:
            cout<<"Please input again!"<<endl;
            break;
      
      }
      if (f1==1)
         break;
   }




}
void saveClientAndAccount(){
   ofstream outfile("client-info.txt");
   int i;
   for(i=0;i<clients.size();i++){
      outfile<<clients[i].name<<endl;
      outfile<<clients[i].address<<endl;
      outfile<<clients[i].socialSecurityNumber<<endl;
      outfile<<clients[i].employer<<endl;
      outfile<<clients[i].annualIncome<<endl;
      outfile<<endl;
   }
   ofstream outfile2("account-info.txt");
   for(i=0;i<accounts.size();i++){
      outfile2<<accounts[i].clientName<<endl;
      outfile2<<accounts[i].accountNumber<<endl;
      outfile2<<accounts[i].accountType<<endl;
      outfile2<<accounts[i].balance<<endl;
      outfile2<<endl;
   }
   cout << "Client information has been saved in the client-info file; " << endl;
   cout << "account information has been saved in the account-info file!" << endl;
   cout << "Press any key to continue...";
   cin.ignore().get();
}
void addClient(){
   cout<<"A new Client will be added: "<<endl;
   cout<<"Client Name: ";
   cin.get();
   string name;
   getline(cin,name);
   cout<<"Address: ";
   string address;
   getline(cin,address);
   cout<<"Social security number: ";
   string socialSecurityNumber;
   getline(cin,socialSecurityNumber);
   cout<<"Employer: ";
   string employer;
   getline(cin,employer);
   cout<<"Annual income: ";
   string annualIncome;
   getline(cin,annualIncome);
   Client client;
   client.address=address;
   client.annualIncome=annualIncome;
   client.employer=employer;
   client.name=name;
   client.socialSecurityNumber=socialSecurityNumber;
   clients.push_back(client);
   cout<<"A new client was added!"<<endl;
   
   cout << "Press any key to continue...";
   cin.ignore().get();

}
void addAccount(){
   cout<<"Choose a client: ";
   string name;
   cin.get();
   getline(cin,name);
   int i=-1;
   int f1=0;
   for(i=0;i<clients.size();i++){
      if (clients[i].name==name){
         cout<<"A new account will be created for "<<name<< "..." <<endl;
         f1=1;
         break;
      }
   }
   if (f1==0){
      cout<<"Error - the client is not in the system"<<endl;
      return;
   }
   
   else{
      cout<<"Account Number: ";
      string accountNumber;
      cin>>accountNumber;
      cout<<"Account Type: ";
      string type;
      cin>>type;
      cout<<"Balance: ";
      int balance;
      cin>>balance;
      Account account;
      account.accountNumber=accountNumber;
      account.accountType=type;
      account.balance=balance;
      accounts.push_back(account);
      cout<<"A new account was created for "<<name<<"!" <<endl;
      
      cout << "Press any key to continue...";
      cin.ignore().get();
   }

}
void editClient(){
   int i;
   int pos=-1;
   while(true){
      cin.get();
      cout<<"Choose a client: ";
      string name;
      getline(cin,name);
   
      for(i=0;i<clients.size();i++)
      {
         Client client=clients[i];
         if (client.name==name){
            pos=i;
            break;
         }
      
      }
      if (pos!=-1){
         break;
      }
      else{
         cout<<"Error-client is not exit!"<<endl;
      }
   
   }
   Client client=clients[pos];
   cout<<"Display "<<client.name<<"'s information:"<<endl;
   cout<<"Address: ";
   cout<<client.address<<endl;
   cout<<"Social security number: ";
   cout<<client.socialSecurityNumber<<endl;
   cout<<"Employer: ";
   cout<<client.employer<<endl;
   cout<<"Annual income: ";
   cout<<client.annualIncome<<endl;
   cout<<"Client "<<client.name<<"'s information will be updated..."<<endl;

   cout<<"1) confirm"<<endl;
   cout<<"2) cancel"<<endl;
   cout<<"Please choose an option:";
   string choice;
   cin>>choice;
   if (choice=="1")
   {
      cin.get();
      cout<<"Address:";
   
      string address;
      getline(cin,address);
      cout<<"Social security number: ";
      string socialSecurityNumber;
      getline(cin,socialSecurityNumber);
      cout<<"Employer: ";
      string employer;
      getline(cin,employer);
      cout<<"Annual income: ";
      string annualIncome;
      getline(cin,annualIncome);
    
      clients[pos].address=address;
      clients[pos].annualIncome=annualIncome;
      clients[pos].employer=employer;
   
      clients[pos].socialSecurityNumber=socialSecurityNumber;
      cout<<"Client "<<client.name<<"'s information was updated!"<<endl;
      
      cout << "Press any key to continue...";
      cin.ignore().get();
   
   }


}
void manageAccount(){
   int pos=-1;
   string accountNumber;

   while(true){
      cout<<"Which account will be managed?";
      cin.get();
      cin>>accountNumber;
      int i;
      for(i=0;i<accounts.size();i++){
         Account account=accounts[i];
         if (account.accountNumber==accountNumber){
            pos=i;
            break;
         }
      
      
      }
      if (pos!=-1){
         break;
      
      }
      else{
         cout<<"Error - Account "<<accountNumber<<"is not in the system!"<<endl;
         cout<<"1) Manage an account"<<endl;
         cout<<"2) Cancel"<<endl;
         cout<<"Please choose an option: ";
         string ch;
         cin>>ch;
         if (ch!="1")
            break;
      }
   }
   Account account=accounts[pos];
   cout<<"Manage account "<<accountNumber<<" for "<<account.clientName<<"..."<<endl;
   while(true){
      cout<<"1) Deposit"<<endl;
      cout<<"2) Withdraw"<<endl;
      cout<<"3) Cancel"<<endl;
      cout<<"Please choose an option: ";
      string ch;
      cin>>ch;
      if (ch=="3")
         break;
      if (ch=="1"){
         cout<<"Deposit amount: ";
         int amount;
         cin>>amount;
         account.balance+=amount;
         cout<<"Balance of account "<<account.accountNumber<<" is: "<<account.balance<<endl;
      }
      if (ch=="2"){
         cout<<"Withdraw amount: ";
         int amount;
         cin>>amount;
         account.balance-=amount;
         cout<<"Balance of account "<<account.accountNumber<<" is: "<<account.balance<<endl;
      }
      if (ch!="1"&&ch!="2"&&ch!="3"){
         cout<<"Please input again!"<<endl;
      }
   
   }
}
void changePassword(string username,string password,int type){
   string newPassword;
   while(true){
      cout<<"New Password: ";
      cin>>newPassword;
      if (newPassword==password){
         cout<<"Error-Your new password must be different from old one"<<endl;
         continue;
      }
      
      
      else{
         break;
      }
   
   }
   if (type==1){
      int i;
      for(i=0;i<admains.size();i++){
         Admain admain=admains[i];
         if (admain.username==username){
            admains[i].password=newPassword;
            cout<<"Password was changed!"<<endl;
            
            cout << "Press any key to continue...";
            cin.ignore().get();
            return;
         }
      
      }
   
   }
   else{
      int i;
      for(i=0;i<branchstaffs.size();i++){
         BranchStaff branchStaff=branchstaffs[i];
         if (branchStaff.username==username){
            branchstaffs[i].password=newPassword;
            cout<<"Password was changed!"<<endl;
            
            cout << "Press any key to continue...";
            cin.ignore().get();
            return;
         }
      }
   }
}
void displayStaff(){
   cout<<"There are "<<branchstaffs.size()+admains.size()<<" users in the system"<<endl;
   int i;
   for(i=0;i<admains.size();i++){
      cout<<i+1<<". User Name: "<<admains[i].username<<"  Role: System Administrator"<<endl;
   }
   for(i=0;i<branchstaffs.size();i++){
      cout<<admains.size()+i+1<<". User Name: "<<branchstaffs[i].username<<" Role: Branch Staff"<<endl;
   }
   
   cout << "Press any key to continue...";
   cin.ignore().get();
}
void addBranchStaff(){
   string userName;
   string password;
    
   cout<<"User Name: ";
   cin>>userName;
   cout<<"Password: ";
   cin>>password;
   cout<<"Role (1 - Administrator;2 - Branch Staff): ";
   string choice;
   cin>>choice;
   if (choice=="1"){
      Admain admain;
      admain.username=userName;
      admain.password=password;
      admains.push_back(admain);
      cout<<"1) Confirm"<<endl;
      cout<<"2) Cancel"<<endl;
      cout<<"Please choose an option: ";
      string ch;
      cin>>ch;
      if (ch=="1"){
      cout<<"A new branch staff member is added! "<<endl;
      cout<<"User Name: "<<userName;
      cout<<" Role: ";
      cout<<"System Administrator"<<endl;
      
      cout << "Press any key to continue...";
      cin.ignore().get();
      }
   }
   else{
      BranchStaff branchstaff;
      branchstaff.username=userName;
      branchstaff.password=password;
      cout<<"1) Confirm"<<endl;
      cout<<"2) Cancel"<<endl;
      cout<<"Please choose an option: ";
      string ch;
      cin>>ch;
      if (ch=="1"){
         cout<<"A new branch staff member is added! "<<endl;
         cout<<"User Name: "<<userName;
         cout<<" Role: ";
         cout<<"Branch Staff"<<endl;
         branchstaffs.push_back(branchstaff);
         
         cout << "Press any key to continue...";
         cin.ignore().get();
      }
   }

}
void deleteBranchStaff(){
   cout<<"Delete a user - User Name: ";
   string userName;
   cin>>userName;
   int i;
   for(i=0;i<admains.size();i++){
      if (admains[i].username==userName){
         cout<<"1) Confirm"<<endl;
         cout<<"2) Cancel"<<endl;
         cout<<"Please choose an option: ";
         string ch;
         cin>>ch;
         if (ch=="1"){
            cout<<"User "<<userName<<" was deleted!"<<endl;
            admains.erase(admains.begin()+i);
            
            cout << "Press any key to continue...";
            cin.ignore().get();
         }
         return;
      }
   }
   for(i=0;i<branchstaffs.size();i++){
      if (branchstaffs[i].username==userName){
         cout<<"1) Confirm"<<endl;
         cout<<"2) Cancel"<<endl;
         cout<<"Please choose an option:";
         string ch;
         cin>>ch;
         if (ch=="1"){
            cout<<"User "<<userName<<" was deleted!"<<endl;
            branchstaffs.erase(branchstaffs.begin()+i);
            
            cout << "Press any key to continue...";
            cin.ignore().get();
         
         }
         return;
      }
   }
   cout<<"Warning - User "<< userName<<" is not in the system. No user is deleted! "<<endl;
    
}
int judgeCorrentAccount(string username,string password){
   int i;
   for(i=0;i<admains.size();i++){
      Admain admain=admains[i];
      if (admain.username==username&&admain.password==password)
         return 1;
   }
   for(i=0;i<branchstaffs.size();i++){
      BranchStaff branchstaff=branchstaffs[i];
      if (branchstaff.username==username&&branchstaff.password==password)
         return 2;
   }
   return 0;
}
void readFile(){

   ifstream infile("data.txt");
   string data;
   int admainNumbers;
   int branchStaffNumbers;
   int accountNumbers;
   int clientNumbers;
   infile>>admainNumbers>>branchStaffNumbers>>accountNumbers>>clientNumbers;
   int i;
   
   infile.get();
   for(i=0;i<admainNumbers;i++)
   {
   
       
      getline(infile,data);
      istringstream ss(data);
      string name;
      string password;
      ss>>name>>password;
      Admain admain;
      admain.username=name;
      admain.password=password;
    
      admains.push_back(admain);
   }
   for(i=0;i<branchStaffNumbers;i++){
       
      getline(infile,data);
      istringstream ss(data);
      string name;string password;
      ss>>name>>password;
      BranchStaff branchStaff;
      branchStaff.username=name;
      branchStaff.password=password;
      branchstaffs.push_back(branchStaff);
   }
   for(i=0;i<accountNumbers;i++){
        
      getline(infile,data);
      istringstream ss(data);
      string clientName;string accountName;string checkType;
      int price;
      ss>>clientName>>accountName>>checkType>>price;
      Account account;
      account.clientName=clientName;
      account.accountNumber=accountName;
      account.accountType=checkType;
      account.balance=price;
      accounts.push_back(account);
   }
   for(i=0;i<clientNumbers;i++){
       // getline(infile,data);
       // istringstream ss(data);
      string name;
      string address;
      string socialSecurityNumber;
      string employer;
      string annualIncome;
       
      getline(infile,name);
    
      getline(infile,address);
   
      getline(infile,socialSecurityNumber);
      
      getline(infile,employer);
   
      getline(infile,annualIncome);
      Client client;
      client.name=name;
      client.address=address;
      client.socialSecurityNumber=socialSecurityNumber;
      client.employer=employer;
      client.annualIncome=annualIncome;
      clients.push_back(client);
   }
}
void saveFile(){
   ofstream outfile("data.txt");
    
   outfile<<admains.size()<<" "<<branchstaffs.size()<<" "<<accounts.size()<<" "<<clients.size()<<endl;
   int i;
   for(i=0;i<admains.size();i++){
      Admain admain=admains[i];
      outfile<<admain.username<<" "<<admain.password<<endl;
   }
   for(i=0;i<branchstaffs.size();i++){
      BranchStaff branchstaff=branchstaffs[i];
      outfile<<branchstaff.username<<" "<<branchstaff.password<<endl;
   }
   for(i=0;i<accounts.size();i++){
      Account account=accounts[i];
      outfile<<account.clientName<<" "<<account.accountNumber<<" "<<account.accountType<<" "<<account.balance<<endl;
   }
   for(i=0;i<clients.size();i++){
      Client client=clients[i];
      outfile<<client.name<<endl;
      outfile<<client.address<<endl;
      outfile<<client.socialSecurityNumber<<endl;
      outfile<<client.employer<<endl;
      outfile<<client.annualIncome<<endl;
   
   }

}
