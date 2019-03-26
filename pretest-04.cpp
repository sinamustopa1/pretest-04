/*
Nama :Sina Mustopa
Kelas : A
NPM : 140810180017
Deskripsi : Singly Linked List
*/

#include<iostream>
using namespace std;
struct ElemtList{
 char npm;
 char nama[40];
 float ipk;
 ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First)
{
 First=NULL;
}

void createElement(pointer& pBaru)
{
 pBaru=new ElemtList;
 cout << "Masukan data \n";
 cout << "Nama : "; cin >> pBaru->nama;
 cout << "NPM : "; cin >> pBaru->npm;
 cout << "IPK : "; cin >> pBaru->ipk;
 pBaru->next=NULL;
}
void insertFirst (List& First, pointer pBaru)
{
 if (First==NULL){  //list kosong
  First=pBaru;
 }
 else{     //list ada isinya
  pBaru->next=First;
  First=pBaru;
 }
}
void insertSortNPM(List& First, pointer pBaru)
{
 pointer pBantu;
 pointer tuker;
 pBantu=First;
 while(pBantu!=NULL){
  if(pBantu->npm > pBantu->next->npm){
   tuker=pBantu->next;
   pBantu->next=tuker->next;
   tuker->next=pBantu;
   pBantu=tuker;
  }
  pBantu=pBantu->next;
 }
}
void traversal (List First)
{
 int i=1;
 pointer pBantu;
 pBantu=First;
 cout << "\t\tData Mahasiswa\n";
 cout << "=================================================\n";
 cout << "No.\tNPM\tNama\tIPK\n";
 cout << "-------------------------------------------------\n";
 while(First!=NULL){
  cout <<i<<"\t"<<pBantu->npm<<"\t"<<pBantu->nama<<"\t"<<pBantu->ipk<<endl;
  First=First->next; 
  i++;
 }
}
int main()
{
 pointer p;
 List First;
 createList(First);
 for (int i=0; i<2; i++)
 {
  createElement(p);
  insertFirst(First, p);
 }
 insertSortNPM(First, p);
 traversal(First);
}
