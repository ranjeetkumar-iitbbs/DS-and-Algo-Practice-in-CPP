/*@	Ranjeet Kumar - 20CS06011
	Assignment : 2
	Round Robin Elimination	
*/

#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

class queue{
	private:
		node* front;
		node* rear;
		int size;
		
	public:
		queue(){
			front = NULL;
			rear = NULL;
			size = 0;
		}
		
		void enqueue(int data, int n){
			node *newNode = new node(data);
			
			if(data == 1){
				front = newNode;
				rear = newNode;
				size++;
			}
			else{
				if(data == n){
					rear -> next = newNode;
					rear = newNode;
					rear -> next = front;
					size++;
				}
				else{
					rear -> next = newNode;
					rear = newNode;
					size++;
				}
			}
			
		}
		
		int print(){
			return front -> data;
		}
		
		int getSize(){
			return size;
		}
		void dequeue(int index){
			node* temp;
			int i = 1;
			while(i < index){
				temp = front;
				front = front -> next;
				i++;
			}
			
			temp -> next = front -> next;
			delete front;
			front = temp -> next;
			size--;
		}
};

int main(){
	int n, k;
	
	cout << "Enter the value of N and K seperated by space :: ";
	cin >> n;
	cin >> k;
	
	queue q;
	
	for(int i = 1; i <= n; i++){
		q.enqueue(i, n);
	}
	
	if(n <= 0 || k <= 0){
		cout << "Please enter value of N and K greater than or equal to 1";
		return 0;
	}
	
	if(n == 1){
		cout << "Winner is :: 1";
		return 0;
	}
	else{
		while(q.getSize() != 1){
			q.dequeue(k);
		}
		cout << "Winner is :: " << q.print();
	}
	
}
