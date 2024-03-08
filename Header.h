
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class customer
{
public:
	customer()
	{
		name = "";
		address = NULL;
		phone_details = "";
	}
	void setname(string na)
	{
		name = na;
	}
	void setlocation(char location)
	{
		address = location;
	}
	void setcontact(string contact)
	{
		phone_details = contact;
	}
	string getname()
	{
		return name;
	}
	char getaddress()
	{
		return address;
	}
	string getp_details()
	{
		return phone_details;
	}
	void operator =(const customer& OBJ)
	{
		name = OBJ.name;
		address = OBJ.address;
		phone_details = OBJ.phone_details;
	}
private:
	string name;
	char address;
	string phone_details;
};

class order
{
public:
	order()
	{
		data.setcontact("");
		data.setlocation(NULL);
		data.setname("");
		dish = NULL;
		dishcount = 0;
		time = 0;
	}
	void details()
	{
		cout << "Name:" << data.getname() << endl;
		cout << "Adress:" << data.getaddress() << endl;
		cout << "Phone Details:" << data.getp_details() << endl;
		cout << "Ordered Dishes:" << endl;
		for (int i = 0; i < dishcount; i++)
		{
			cout << "Dishe(" << i + 1 << "):" << dish[i] << endl;
		}
		cout << "Order preparation time:" << time << endl;
	}
	void infosetter(string name, char place, string info, int numOfDishes)
	{
		data.setname(name);
		data.setlocation(place);
		data.setcontact(info);
		dishcount = numOfDishes;
		dish = new string[numOfDishes];
		time = 0;
	}
	void takeorder()
	{
		int dish = 0;
		cout << "Kindly fill out your details below:" << endl;
		string naam = "", phone = "";
		char address = NULL;
		cout << "Name:";
		cin >> naam;
     above:
		cout << "Address:";
		cin >> address;
		if (address == 'a' || address == 'b' || address == 'c' || address == 'd' || address == 'e' || address == 'f' || address == 'g' || address == 'i' || address == 'j' || address == 'k' || address == 'l' || address == 'm' || address == 'n' || address == 'o' || address == 'p')
		{
			cout << "Phone Details:";
			cin >> phone;
			cout << "How many dishes you want to order?";
			cin >> dish;
			int* code = new int[dish];
			cout << "enter the dish codes ,you want to order given corresponding to your dish in the menu above:-" << endl;
			for (int i = 0; i < dish; i++)
			{
				cout << "code(" << i + 1 << "):";
				cin >> code[i];
			}
			infosetter(naam, address, phone, dish);
			setdishes(code);
		}
		else
		{
			cout << "Please enter valid address...";
			goto above;
		}
	}
	void setdishes(int* codes) //codes is a array of codes of dishes that will be passed to it
	{
		for (int i = 0; i < dishcount; i++)
		{
			switch (codes[i])
			{
			case 0:
				dish[i] = "Barbequed Chicken";
				time = time + 20;
				break;
			case 1:
				dish[i] = "Broccoli Bake";
				time = time + 20;
				break;
			case 2:
				dish[i] = "Buttered Potatoes";
				time = time + 20;
				break;
			case 3:
				dish[i] = "Cheese Fondue";
				time = time + 20;
				break;
			case 4:
				dish[i] = "Chow Mein";
				time = time + 25;
				break;
			case 5:
				dish[i] = "chinese Rice";
				time = time + 25;
				break;
			case 6:
				dish[i] = "Spring rolls";
				time = time + 25;
				break;
			case 7:
				dish[i] = "Thai fried noodles";
				time = time + 30;
				break;
			case 8:
				dish[i] = "Spicy shrimp soup";
				time = time + 30;
				break;
			case 9:
				dish[i] = "Red cury";
				time = time + 30;
				break;
			case 10:
				dish[i] = "Pizza";
				time = time + 25;
				break;
			case 11:
				dish[i] = "Lasagna";
				time = time + 25;
				break;
			case 12:
				dish[i] = "Risotto";
				time = time + 25;
				break;
			case 13:
				dish[i] = "Daal makhni";
				time = time + 15;
				break;
			case 14:
				dish[i] = "Qorma";
				time = time + 15;
				break;
			case 15:
				dish[i] = "Biryani";
				time = time + 15;
				break;
			case 16:
				dish[i] = "Fish Cury";
				time = time + 15;
				break;
			}
		}
	}
	int gettime()
	{
		return time;
	}
	void operator =(const order& OBJ)
	{
		data = OBJ.data;
		dish = OBJ.dish;
		dishcount = OBJ.dishcount;
		time = OBJ.time;
	}
	char getadres()
	{
		return data.getaddress();
	}
private:
	customer data;
	string* dish;
	int dishcount;
	int time;
};

class chefs
{
public:
	chefs()
	{
		code = 0;
		odr_time = 0;
	}
	void setter(order variable, int num)
	{
		code = num;
		odr_time = variable.gettime();
	}
	int time()
	{
		return odr_time;
	}
	int givecode()
	{
		return code;
	}
private:
	int odr_time;
	int code;
};
class Graph
{
public:
	Graph()
	{
		vertexcounter();
		adj_matrix = new int* [numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			adj_matrix[i] = new int[numVertices];
		}
		ifstream input;
		input.open("Graph.txt");
		while (!input.eof())
		{
			for (int i = 0; i < numVertices; i++)
			{
				for (int j = 0; j < numVertices; j++)
				{
					input >> adj_matrix[i][j];
				}
			}
		}
		input.close();
		
	}
	void vertexcounter()
	{
		ifstream input;
		input.open("Graph.txt");
		string temp = "";
		int vertex = 0;
		while (!input.eof())
		{
			getline(input, temp);
			vertex++;
		}
		input.close();
		numVertices = vertex;
	}
	void alternatepath1(int s)
	{
		
	}
		
	void alternatepath2(int usernode)
	{
		
	}
	void printgraphdata()
	{
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				cout << adj_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	int** getmatrix()
	{
		return adj_matrix;
	}
	int GetNumVertices()
	{
		return numVertices;
	}
	void operator=(const Graph& map)
	{
		adj_matrix = map.adj_matrix;
		numVertices = map.numVertices;
	}
private:
	int** adj_matrix;
	int numVertices;
};

class riders
{
public:
	riders() {
		odr.infosetter("", NULL, "", 0);
		time = 0;
		code = 0;
	}
	riders(order obj, int t,int c)
	{
		odr = obj;
		time = t;
		code = c;
	}
	void objsetter(order obj)
	{
		odr = obj;
	}
	void timesetter(int t)
	{
		time = t;
	}
	void codesetter(int c)
	{
		code = c;
	}
	order getorder()
	{
		return odr;
	}
	int gettime()
	{
		return time;
	}
	int getcode()
	{
		return code;
	}
private:
	int time;
	order odr;
	int code;
};




