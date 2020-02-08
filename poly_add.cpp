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
#include "linkedlist.h"

using namespace std;

void addToList(string str, List &list);
int strToInt(string str);
void addPolynomials(List &list1, List &list2, List &res);

int main()
{
	string pol1 = "13x^8-7x^5+32x^2+54x^0";
	string pol2 = "3x^12+17x^5+3x^3+98x^0";
	
	cout<<"Polynomial 1: "<<pol1<<endl<<"Polynomial 2: "<<pol2;
	
	List p1;
	List p2;
	
	addToList(pol1, p1);
	addToList(pol2, p2);
	
	//p1.displayList();
	//p2.displayList();
	
	cout<<"\n\n";
	
	List resL;	// resultant list
	
	cout<<"\n\nResultant Polynomial: ";
	addPolynomials(p1, p2, resL);
	
	//resL.displayList();
}

void addPolynomials(List &list1, List &list2, List &res)
{
	int lenL1 = list1.lenList();
	int lenL2 = list2.lenList();
	int count = 0;	// controls iteration on list2 which is j;
	
	for(int i=0; i<lenL1; i++) // list1
	{
		Node m = list1[i];
		
		for(int j=count; j<lenL2; j++) // list2
		{
			Node n = list2[j];
			
			// if equal power, add and movie forward on both lists.
			if(m.power == n.power)
			{
				int c = m.coeff + n.coeff;
				int p = m.power;
				
				if(c < 0)
				{
					cout<<" - "<<c<<"x^"<<p;
				}
				else
				{
					cout<<" + "<<c<<"x^"<<p;
				}
				
				res.addNodeToTail(c, p);
				
				j=lenL2;
				
				count++;	// count++ means don`t visit this node in list2 again.
			}
			// if power of node in list1 > power of node in list2, then move forward on list1
			else if(m.power > n.power)
			{
				if(m.coeff < 0)
				{
					cout<<" - "<<m.coeff<<"x^"<<m.power;
				}
				else
				{
					cout<<" + "<<m.coeff<<"x^"<<m.power;
				}
				
				res.addNodeToTail(m.coeff, m.power);
				
				j=lenL2;	// after this, j loop breaks and i increments and j starts from count
			}
			// if power of node in list2 is greater, then move forward in list2 and don`t come to this node.
			// count++ insures that.
			// that means other values for i+1 will not be matched with this j if ith nodes power < jth nodes power
			else
			{
				if(n.coeff < 0)
				{
					cout<<" - "<<n.coeff<<"x^"<<n.power;
				}
				else
				{
					cout<<" + "<<n.coeff<<"x^"<<n.power;
				}
				
				res.addNodeToTail(n.coeff, n.power);
				
				count++;
			}
		}
	}
}

void addToList(string str, List &list)
{
	if(str[0] >= '0' && str[0] <= '9')
	{
		// left padding string with + to get position i that has + or - sign initially or after every iteration.
		str = "+" + str;
	}
	
	for(int i=0; i<str.length(); i++)
	{
		string coeff = "";
		string power = "";
		
		// here padding is used so, // str[i] is position pointing to + or - sign
		bool sign = (str[i] == '-')?1:0;	// 1 for neg, 0 for pos
		
		i+=1;	// str[i+1] is position pointing to number (coefficient)
		
		// str[i] is position pointing to variable number
		
		while(str[i] != 'x')
		{
			// append every number get after increment untill variable x is reached: str[i] is some number
			coeff += str[i];
			i++;
		}
		
		// str[i] is position pointing to variable x
		// str[i+1] is position pointing to ^ power sign
		
		i += 2;	// str[i+2] is position pointing to variable number (power)
		
		while(str[i] != '+' && str[i] != '-')
		{
			// append every number get after increment untill + or - is reached: str[i] is some number
			power += str[i];
			i++;
		}
		
		// str[i] is position pointing to + or - sign
		
		int c = strToInt(coeff);
		int p = strToInt(power);
		
		if(sign)	// if negative
		{
			c = c * -1;	// coefficient is negative
		}
		
		// adding to list
		list.addNodeToTail(c, p);
		
		i--;
		// str[i] is position pointing to last digit of power
	}
}

int strToInt(string str)
{
	stringstream ss;
	int num;
	
	ss << str;
	
	ss >> num;
	
	return num;
}
