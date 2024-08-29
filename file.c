/*
Name : Chaithra B R
Date : 20/08/2024
Description: AdressBook
*/
#include <stdio.h>
#include<stdlib.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    FILE *ptr;
    ptr=fopen("contact.csv","w");
    if(ptr==NULL)
    {
        printf("file does not exist\n");
        return;
    }
    fprintf(ptr,"%c %d\n",'#',addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(ptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } 
    fclose(ptr);
    return; 
}

void loadContactsFromFile(AddressBook *addressBook) {
    addressBook->contactCount=0;
    FILE*ptr;
    ptr=fopen("contact.csv","r");
    if(ptr==NULL)
    {
        printf("File does not open");
        return;
    }
    fseek(ptr,1,SEEK_SET);

    char arr[8];
    fgets(arr,8,ptr);
    int count=atoi(arr);
    for(int i=0;i<count;i++)
    {
        fscanf(ptr,"%30[^,],%30[^,],%30[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    addressBook->contactCount=count;
    fclose(ptr);
}
