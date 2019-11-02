/************************************************************************************************

	Author: Ali Faisal
	Fucntion: Add Two Polynomials
	Data Structure: Linked List with subscript operator overloading.
	Input: Two Strings with no Spaces. Break and add them in form nodes in Linked List. Then add two Linked List.
	Time Complexity: Big-O(m x n) for addition function	: m = length Of List 1, n = Length Of List 2
	
*************************************************************************************************/

#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Node{
	
	public:
		
		int coeff;
		int power;
		bool sign; // 1 for neg, 0 for pos
		Node *addrOfNext;
		
		Node(int c, int p)
		{
			this->coeff = c;
			this->power = p;
			this->sign = (coeff<0)? sign=1 : sign=0;
			this->addrOfNext = 0;
		}
		
		void setNode(int c, int p)
		{
			this->coeff = c;
			this->power = p;
			this->sign = (coeff<0)? sign=1 : sign=0;
			this->addrOfNext = 0;
		}
		
		void displayNode(Node *tempnode)
		{
			cout<<"{coeff: "<<tempnode->coeff<<", power: "<<tempnode->power<<"}->";
		}
};

class List{
	
	public:
		
		Node *tail, *head;
		
		List()
		{
			tail = 0;
			head = 0;
		}
		
		void addNodeToHead(int c, int p)
		{
			Node *newnode = new Node(c, p);
			
			if(head == 0)
			{
				head = tail = newnode;
			}
			else
			{
				newnode->addrOfNext = head;
				head = newnode;
			}
		}
		
		void addNodeToTail(int c, int p)
		{
			Node *newnode = new Node(c, p);
			
			if(head == 0)
			{
				head = tail = newnode;
			}
			else
			{
				tail->addrOfNext = newnode;
				tail = newnode;
			}
		}
		
		int lenList()
		{
			int i=0;
			Node* tempnode = head;
			
			while(tempnode != 0)
			{
				i++;
				tempnode = tempnode->addrOfNext;
			}
			
			return i;
		}
		
		void displayList()
		{
			Node* tempnode = head;
			
			while(tempnode != 0)
			{
				cout<<"{coeff: "<<tempnode->coeff<<", power: "<<tempnode->power<<"}->";
				tempnode = tempnode->addrOfNext;
			}
			cout<<endl;
		}
		
		Node& operator[](int i)
		{
			if(i < this->lenList() && i >= 0)
			{
				int j=0;
				Node* tempnode = this->head;
				
				while(tempnode != 0 && j < i)
				{
					j++;
					tempnode = tempnode->addrOfNext;
				}
				
				if(i == j)
				{
					return *tempnode;
				}
			}
		}
		
		~List()
		{
			Node *temp;
			while(head != tail)
			{
				temp = new Node(4, 2);
				temp = head;
				head = head->addrOfNext;
				delete temp;
				temp = 0;
			}
			
			if(head != 0)
			{
				delete head;
				head = 0;
				tail = 0;
			}
		}
	
};
