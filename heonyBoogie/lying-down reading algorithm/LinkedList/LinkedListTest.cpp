#include "LinkedList.h"
#include <cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	LinkedList myList = LinkedList();
	
	for (int i = 0; i < 5; i++) {
		myList.AddNode(rand() % 100);
	}
	myList.Show();

	//insert node
	cout << "\n[insert node]" << endl;
	myList.InsertNode(530, 3);
	myList.Show();
	myList.InsertNode(1997, 0);
	myList.Show();
	myList.InsertNode(1217, 7);
	myList.Show();

	//delete node
	cout << "\n[delete node]" << endl;
	myList.DeleteNode(4);
	myList.Show();
	myList.DeleteNode(0);
	myList.Show();
	myList.DeleteNode(5);
	myList.Show();

	return 0;
}