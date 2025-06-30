#include<iostream>
#include<string>

using namespace std;

class Book
{
    public:
  string book_title;
  int id;
  string author;
  Book* head = NULL;
  Book *next;
};

class issuedBook
{
   public:
  string title;
  int id;
  issuedBook* rear = NULL;
  issuedBook* front = NULL;
  issuedBook* next;
};

void addBook()
{
    Book* newBook = new Book();
    cout << " please enter the book ID : " ; 
    cin >> newBook->id;
    
}
int func(int a){
  a++ ;
  return a ;
}