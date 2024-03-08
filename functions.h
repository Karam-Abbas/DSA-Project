void menu()
{
	cout << "we serve 5 types of cuisines given below:" << endl;
	cout << endl;
	cout << "    Continental                       Indian          " << endl;
	cout << "  0-Barbequed Chicken                13-Daal makhni    " << endl;
	cout << "  1-Broccoli Bake                    14-korma          " << endl;
	cout << "  2-Buttered Potatoes                15-Biryani        " << endl;
	cout << "  3-Cheese Fondue                    16-fish curry     " << endl;
	cout << endl;
	cout << "     Chinese                           Thai            " << endl;
	cout << "  4-Chow Mein                        7-Thai fried noodles" << endl;
	cout << "  5-chinese Rice                     8-Spicy shrimp soup" << endl;
	cout << "  6-Spring rolls                     9-Red cury        " << endl;
	cout << endl;
	cout << "                     Italian   " << endl;
	cout << "                  10-Pizza   " << endl;
	cout << "                  11-Lasagna " << endl;
	cout << "                  12-Risotto " << endl;
}

int char2intMapFunc(char a)
{
	if (a == 'a' || a == 'A') { return 0; }
	else if (a == 'b' || a == 'B') { return 1; }
	else if (a == 'c' || a == 'C') { return 2; }
	else if (a == 'd' || a == 'D') { return 3; }
	else if (a == 'e' || a == 'E') { return 4; }
	else if (a == 'f' || a == 'F') { return 5; }
	else if (a == 'g' || a == 'G') { return 6; }
	else if (a == 'h' || a == 'H') { return 7; }
	else if (a == 'i' || a == 'I') { return 8; }
	else if (a == 'j' || a == 'J') { return 9; }
	else if (a == 'k' || a == 'K') { return 10; }
	else if (a == 'l' || a == 'L') { return 11; }
	else if (a == 'm' || a == 'M') { return 12; }
	else if (a == 'n' || a == 'N') { return 13; }
	else if (a == 'o' || a == 'O') { return 14; }
	else if (a == 'p' || a == 'P') { return 15; }
	else
	{
		cout << "invalid character  :/";
		return 0;
	}
}

char int2charMapFunc(int A)
{
	if (A == 0) { return 'a'; }
	else if (A == 1) { return 'b'; }
	else if (A == 2) { return 'c'; }
	else if (A == 3) { return 'd'; }
	else if (A == 4) { return 'e'; }
	else if (A == 5) { return 'f'; }
	else if (A == 6) { return 'g'; }
	else if (A == 7) { return 'h'; }
	else if (A == 8) { return 'i'; }
	else if (A == 9) { return 'j'; }
	else if (A == 10) { return 'k'; }
	else if (A == 11) { return 'l'; }
	else if (A == 12) { return 'm'; }
	else if (A == 13) { return 'n'; }
	else if (A == 14) { return 'o'; }
	else if (A == 15) { return 'p'; }
	else
	{
		cout << "invalid character :/";
		return NULL;
	}
}

void chefappointer(queue<order> orders, queue<order> forrider, int size)
{
	chefs* arr = new chefs[4];
	for (int i = 0; i < 4; i++)
	{
		arr[i].setter(orders.front(), i + 1);
		cout << "Your order is being prepared by Chef" << arr[i].givecode() << endl;
		cout << "Customer Details:" << endl;
		orders.front().details();
		forrider.push(orders.front());
		orders.pop();
		cout << endl;
		if (orders.empty())
		{
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (arr[i].time() > arr[j].time())
			{
				swap(arr[i], arr[j]);
			}
		}
	}
	if (size > 4 && size <= 8)
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Your order is being prepared by Chef" << arr[i].givecode() << endl;
			arr[i].setter(orders.front(), i + 1);
			cout << "Customer Details:" << endl;
			orders.front().details();
			forrider.push(orders.front());
			orders.pop();
			cout << endl;
			if (orders.empty())
			{
				return;
			}
		}
	}
}

void riderappointer(queue<order> forrider, int size, Graph naksha)
{
	char location;
	riders* deliveryboy = new riders[5];
	for (int i = 0; i < 5; i++)
	{
		deliveryboy[i].objsetter(forrider.front());
		deliveryboy[i].codesetter(i+1);
		cout << "Your order has been given to the Rider no."<< deliveryboy[i].getcode()<<endl;
		cout << "And will be delivered in " << deliveryboy[i].gettime() << "mins" << endl;
		location = forrider.front().getadres();
		forrider.pop();
		// here the paths will be displayed
		//set the time and path 
		cout << endl;
		if (forrider.empty())
		{
			return;
		}
	}
	for (int i = 0; i < 5; i++)//on the basis of time the riders are being sorted
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (deliveryboy[i].gettime() > deliveryboy[j].gettime())
			{
				swap(deliveryboy[i], deliveryboy[j]);
			}
		}
	}
	if (size>5&&size<10)
	{
		loop:
		for (int i = 0; i < 5; i++) 
		{
			cout << "Your order has been given to the Rider no." << deliveryboy[i].getcode() << endl;
			deliveryboy[i].objsetter(forrider.front());
			deliveryboy[i].codesetter(i + 1);
			//set time and path
			cout << "And will be delivered in " << deliveryboy[i].gettime() << "mins" << endl;
			location = forrider.front().getadres();
			forrider.pop();
			// here the paths will be displayed
			cout << endl;
			if (forrider.empty())
			{
				return;
			}
		}

	}
	if (size>=10)
	{
		goto loop;
	}
}



