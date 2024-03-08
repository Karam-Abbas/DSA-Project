#include"Header.h"
#include"functions.h"
int main()
{
	cout << "--------------------------------------------------Favourite Panda--------------------------------------------------" << endl;
	menu();
	cout << "Do you want to order?(1==Yes/0==No)";
	bool ans;
	int numberOfCustomers = 0;
	cin >> ans;
	cout << "Number of customers:";
	cin >> numberOfCustomers;
	if (ans == true)
	{
		queue<order> for_chef;
		order* orders_array = new order[numberOfCustomers];

		for (int i = 0; i < numberOfCustomers; i++)//takes orders
		{
			cout << "Customer " << i + 1 << "'s data:" << endl;
			orders_array[i].takeorder();
			for_chef.push(orders_array[i]);
			cout << endl;
		}
		system("CLS");

		queue<order> for_rider;
		chefappointer(for_chef, for_rider, numberOfCustomers);//appoints chefs
		
		/*riderappointer(for_rider,numberOfCustomers,map);*///appoints riders
	}
	else
	{
		return 0;
	}
	Graph map;
	map.alternatepath1(0);
	system("pause");
	return 0;
}

