/**
   *@file 1212.cpp
   *@version 0.1
   *@date 28.05.15
   *@title Release template with list
   */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;
/**
	*@brief Шаблоны (англ. template) — средство языка C++, предназначенное для кодирования обобщённых алгоритмов, без привязки к некоторым параметрам (например, типам данных, размерам буферов, значениям по умолчанию).
*/
template<class T>
struct Spisok
{
	///data - информационное поле
	T data;
	///*next - указатель на следующий элемент
	Spisok *next;
	///*pred - указатель на предыдуший элемент
	Spisok *pred;
};
template<class T>
class SSpisok: public Spisok<T>
{
	Spisok<T>*head;
public:
	SSpisok()
	{
		head=0;
		next=0;
		pred=0;
	}
	void AddSpisok(int position, T value);
	void PrintSpisok();
};
/** 
  *@func Функция добавления элемента
	 */
template<class T> 
void SSpisok<T>::AddSpisok(int position, T value)
{
///Spisok<T> *node=new Spisok<T> создание нового элемента	
		Spisok<T> *node=new Spisok<T>; 
///node->data=value присвоение элементу значения
node->data=value; 
///if (head==NULL) если список пуст
if (head==NULL) 
{
 ///node->next=node установка указателя next
 node->next=node;
 ///node->pred=node установка указателя prev
 node->pred=node; 
 ///определяется голова списка
 head=node; 
}
else
{
 Spisok<T> *p=head;
for(int i=position; i>1; i--) p=p->next;
 p->pred->next=node;
 node->pred=p->pred;
 ///node->next=p добавление элемента
 node->next=p; 
p->pred=node;
}
cout<<"\nElement dobavlen..."<<endl;
}
/** 
  *@func Функция печати списка
	 */
template<class T>
void SSpisok<T>::PrintSpisok()
	{
if (head==NULL) cout<<"Spisok pust\n";
else
{
 Spisok<T> *a=head;
cout<<"\nElementi spiska: ";
do
{
	
cout<<a->data<<" ";
 a=a->next;
} while(a!=head); cout<<"\n";
}
}

void main()
{
	
	int value1, index=0;
	char value2[10];
	int N;
	SSpisok<int> Arr;
	SSpisok<char*> Arr1;
	cout<<"Chislo obchodov bolshogo zikla: ";
	cin>>N;
   for (int i=0; i<N; i++)
   {
      int n;
      char tip;
      cout<<"Tip peremennoi: i ili s"<<endl;
      cin>>tip;
      cout<<"Chislo obchodov malogo zikla: ";
      cin>>n; 
	  if(tip=='i')
		 {
				for (int j=0; j<n; j++)
				{
					cout<<"Vvedite index elementa = ";
					cin>>index;
					cout<<"Vvedite znachenie: ";
					cin>>value1;
					Arr.AddSpisok(index,value1);
				}
				Arr.PrintSpisok();
	  }
	if(tip=='s')
	{
			for (int j=0; j<n; j++)
				{
					cout<<"Vvedite index elementa = ";
					cin>>index;
					cout<<"Vvedite znachenie: ";
					cin>>value2;
					Arr1.AddSpisok(index,value2);
				}
		 Arr1.PrintSpisok();
      }
 }
   
}  




