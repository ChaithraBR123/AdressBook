/*
Name : Chaithra B R
Date : 20/08/2024
Description: AdressBook
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Print header
    printf("%-20s %-15s %-30s\n", "Name", "Contact", "Email ID");
    printf("---------------------------------------------------------------\n");

    // Loop through and print all contacts
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("%-20s %-15s %-30s\n", 
               addressBook->contacts[i].name, 
               addressBook->contacts[i].phone, 
               addressBook->contacts[i].email);
    }

    // Separator after all contacts are displayed
    printf("---------------------------------------------------------------\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void createContact(AddressBook *addressBook)
{
    //creating contact by name
printf("enter your name: ");
getchar();
scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].name);
getchar();
//creating contact by phone number
printf("enter your phone number: ");
while(1) {
    int flag=0;
    scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].phone);
    getchar();
    int len=strlen(addressBook->contacts[addressBook->contactCount].phone);
    if(len!=10) {
        printf("Entered number must contain 10 digits\n"); 
        continue;
    }
    for(int i=0;i<len;i++)
    {
        if(addressBook->contacts[addressBook->contactCount].phone[i]<'0' || addressBook->contacts[addressBook->contactCount].phone[i]>'9')
        {
            printf("Phone must contain only digits\n");
            flag=1;
            break;
        }
    }
    if(flag==1){
        continue;
    }
    for(int i=0;i<addressBook->contactCount;i++) {
        if(strcmp(addressBook->contacts[addressBook->contactCount].phone,addressBook->contacts[i].phone)==0){
            printf("the entered phone number is already exist,enter new phone number");
            flag=2;
            break;
        }
    }
    if(flag==2) {
        continue;
 }
 break;
}
//creating contact by email
printf("enter your email:");
while(1){
int flag=0;
scanf("%[^\n]",addressBook->contacts[addressBook->contactCount].email);
getchar();
if(strchr(addressBook->contacts[addressBook->contactCount].email,'@')==NULL)
{
    printf("email should contain @");
    continue;
}
if(strstr(addressBook->contacts[addressBook->contactCount].email,".com")==NULL)
{
    printf("email should contain .com");
    continue;
}
for(int i=0;i<addressBook->contactCount;i++){
    if(strcmp(addressBook->contacts[addressBook->contactCount].email,addressBook->contacts[i].email)==0){
        printf("entered email is already exist");
        flag=2;
        break;
    }
}
if(flag==2){
    continue;
}
break;
}
addressBook->contactCount++;
}       
//search contact in addressbook
void searchContact(AddressBook *addressBook) 
{
 printf("1.search by name\n:");
 printf("2.search by phone\n:");
 printf("3.search by email\n:");
 printf("enter your choice:");
int choice;
scanf("%d", &choice);
getchar();
switch(choice)
{
    // search contact by name
    case 1: {
    char name[40];
    printf("Enter name to be searched: ");
    scanf("%[^\n]",name);
    getchar();
    int res=0;
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(name,addressBook->contacts[i].name)==0)
        {
            printf("Name: %s\n",addressBook->contacts[i].name);
            printf("phone: %s\n",addressBook->contacts[i].phone);
            printf("Email: %s\n",addressBook->contacts[i].email);
            res=1;
            break;
        }
    }
    if(res==0)
    {
        printf("No contact found\n");
    }
    break;
}
//search contact by phone number
    case 2: {
    char number[40];
    printf("Enter phone number to be searched: ");
    scanf("%[^\n]",number);
    getchar();
    int res=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(number,addressBook->contacts[i].phone)==0)
        {
            printf("Name: %s\n",addressBook->contacts[i].name);
            printf("phone: %s\n",addressBook->contacts[i].phone);
            printf("Email: %s\n",addressBook->contacts[i].email);
            res=1;
            break;
        }
    }
    if(res==0)
    {
        printf("No contact found\n");
    }
    break;
    }
    //search contact by email
    case 3: {
    char email[40];
    printf("Enter email to be searched: ");
    scanf("%[^\n]",email);
    getchar();
    int res=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(email,addressBook->contacts[i].email)==0)
        {
            printf("Name: %s\n",addressBook->contacts[i].name);
            printf("phone: %s\n",addressBook->contacts[i].phone);
            printf("Email: %s\n",addressBook->contacts[i].email);
            res=1;
            break;
        }
    }
    if(res==0)
    {
        printf("No contact found\n");
    }
    break;
    }
default:
printf("Invalid choice\n");
break;
}
}
//edit contacts in addressbook
void editContact(AddressBook *addressBook)
{
	printf("1.edit a name\n");
    printf("2.edit a phone\n");
    printf("3.edit a email\n");
    printf("enter your choice:");
    int choice;
    scanf("%d",&choice);
    getchar();
    switch(choice){
        //edit contact by name
        case 1: {
        printf("name of the contact want to be edit:");
        char Editname[20];
        scanf("%[^\n]",Editname);
        getchar();
        int found=0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(Editname,addressBook->contacts[i].name)==0){
                printf("name: %s, phone: %s ,email: %s\n", 
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
                printf("contact was found,enter new name:");
                char Ename[30];
                scanf("%[^\n]",Ename);
                getchar();
                strcpy(addressBook->contacts[i].name,Ename);
                printf("updated contact-name: %s, phone: %s, email: %s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
                found=1;
                break;
            }
        }
        if(!found){
            printf("contact not found\n");
        }
        break;
    }
    //edit contact by phone number
        case 2 : {
        printf("enter the number of the contact to be edit:");
        char Editnum[20];
        scanf("%[^\n]",Editnum);
        getchar();
        int found=0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(Editnum,addressBook->contacts[i].phone)==0){
      printf("name: %s, phone: %s, email: %s\n",
      addressBook->contacts[i].name,
      addressBook->contacts[i].phone,
      addressBook->contacts[i].email);
        printf("contact was found,enter new number:");
        while(1) {
            char newphone[20];
            int valid=1;
        scanf("%[^\n]",newphone);
        getchar();
        if(strlen(newphone)!=10) {
        printf("phone number must contain 10 digits\n:" );
        continue;
        }
        for(int j=0;j<10;j++){
        if(newphone[j]<'0' || newphone[j]>'9'){
        printf("phone number must contain only digits\n:");
        valid=0;
        break;
        }
        }
        if(valid){
        strcpy(addressBook->contacts[i].phone,newphone);
        printf("updated contact - name: %s, phone: %s, email: %s\n", 
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
        found=1;
        break;
    }
    }
    break;
    }
   }
    if(!found){
        printf("contact not found in list\n");
    }
    break;
     }
     //edit contact by email
case 3: {
printf("enter the email of the contact to be edit:");
char Editemail[20];
scanf("%[^\n]",Editemail);
getchar();
int found=0;
for(int i=0;i<addressBook->contactCount;i++){
    if(strcmp(Editemail,addressBook->contacts[i].email)==0){
        printf("name: %s, phone: %s, email: %s\n", 
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
        printf("contact was found,enter new email:");
        while(1){
        char newEmail[30];
            scanf("%[^\n]",newEmail);
            getchar();
            if(strchr(newEmail,'@')==NULL){
                printf("email should contain '@'\n");
                continue;
                }
                if(strstr(newEmail,".com")==NULL){
                    printf("email should contain .com\n");
                    continue;
                }
        strcpy(addressBook->contacts[i].email,newEmail);
 printf("Upadted contact - name: %s, phone: %s, email: %s\n", 
 addressBook->contacts[i].name,
 addressBook->contacts[i].phone,
 addressBook->contacts[i].email);        
   found=1;
   break;
    }
    break;
}
}
if(!found){
    printf("contact not found\n");
}
break;
}
default:
printf("invalid choice");
break;
    }
    }
    //delete contacts in addressbook
void deleteContact(AddressBook *addressBook)
{
	printf("1.delete contact by name\n");
   printf("2.delete contact by phone\n");
   printf("3.delete contact by email\n");
   printf("enter your choice:");
   int choice;
   scanf("%d",&choice);
   getchar();
   switch(choice){

    //delete contact by name
    case 1: {
        printf("enter the name of the contact you want to delete:");
        char Editname[20];
        scanf("%[^\n]",Editname);
        getchar();
        //validate dupliacte name and ask user to delete that by using index
        int foundIndices[MAX_CONTACTS];
        int foundCount=0;
        //find all the contact with the matching name 
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(Editname,addressBook->contacts[i].name)==0){
               foundIndices[foundCount++]=i;
            }
        }
        if(foundCount==0) {
            printf("No conatct with that name '%s' was found\n",Editname);
        }
        else if(foundCount==1){
            //if only one contact is found delete it directly
            int index=foundIndices[0];
            printf("Deleted contact- name: %s,phone: %s, email: %s\n",
            addressBook->contacts[index].name,
            addressBook->contacts[index].phone,
            addressBook->contacts[index].email);
            for(int j=index;j<addressBook->contactCount-1;j++){
                addressBook->contacts[j]=addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
        }
        else{
            printf("Multiple contacts with the name '%s' were found\n",Editname);
            for(int i=0;i<foundCount;i++){
                int index=foundIndices[i];
                printf("%d, name: %s,phone: %s,email: %s\n",i+1,
                addressBook->contacts[index].name,
                addressBook->contacts[index].phone,
                addressBook->contacts[index].email);
            }
            printf("enter the number of the contact you want to delete:");
            int selectedIndex;
            scanf("%d",&selectedIndex);
            getchar();
            if(selectedIndex>=1&&selectedIndex<=foundCount){
                int index=foundIndices[selectedIndex-1];
                printf("deleted contact-name: %s,phone: %s,email: %s\n",
                addressBook->contacts[index].name,
                addressBook->contacts[index].phone,
                addressBook->contacts[index].email);
                for(int j=index;j<addressBook->contactCount-1;j++){
                    addressBook->contacts[j]=addressBook->contacts[j+1];
                }
                addressBook->contactCount--;
            }
            else {
                printf("Invalid selection\n");
            }
        }
        break;
    }
                
        //delete contact by phone number
        case 2: {
        printf("enter the phone number of the contact you want to delete:");
        char Editphone[20];
        scanf("%[^\n]",Editphone);
        getchar();
        int flag2=1;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(Editphone,addressBook->contacts[i].phone)==0){
            flag2=0;
            for(int j=i;j<addressBook->contactCount;j++){
            if(i==j){
            printf("Deleted contacts-name: %s,phone: %s,email: %s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
            addressBook->contacts[j]=addressBook->contacts[j+1];
                         }
                         break;
                }
            }
            if(flag2){
                printf("entered phone number was not found\n");
            }
            else
            {
                addressBook->contactCount--;
            }
            break;
        }
        //delete contact by email
            case 3: {

            printf("enter the email of the contact you want to delete:");
        char Editemail[20];
        scanf("%[^\n]",Editemail);
        getchar();
        int found=0;
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(Editemail,addressBook->contacts[i].email)==0){
                found=1;
        printf("Deleted contacts-name: %s,phone: %s,email: %s\n",
        addressBook->contacts[i].name,
        addressBook->contacts[i].phone,
        addressBook->contacts[i].email);
    for(int j=i;j<addressBook->contactCount-1;j++){
    addressBook->contacts[j]=addressBook->contacts[j+1];
    }
          addressBook->contactCount--;
          break;
            }
        }               
            if(!found){
                printf("entered email was not found\n");
            }
            break;
            }
            default:
            printf("Invalid choice\n");
            break;
        }
        }
        }
    
   





                
    

