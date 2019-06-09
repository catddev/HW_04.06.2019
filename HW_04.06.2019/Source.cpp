#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<fstream>
#include"Train.h"
#include"Filter.h"
#include"Sort_by.h"
using namespace std;

bool asc(train t1, train t2) {
	return(t1.getNumber() < t2.getNumber());
}

int main() {

	ifstream in_file("in.txt");
	vector<train> tss;
	int n;
	string str1, str2;
	string feature;

	if (!in_file)
		cerr << "file open error" << endl;
	else {
		while (in_file >> n >> str1 >> str2) {
			tss.push_back(train(n, str2, str1));
		}
	}

	//sort by number
	sort(tss.begin(), tss.end(), asc);//our own predicator asc

	cout << "Enter feature to sort by: number, departure, destination" << endl;
	cin >> feature;
	//outer method SortBy
	sort(tss.begin(), tss.end(), SortBy(feature));//functor SortBy, класс при вызове круглых скобок становится функтором
	for_each(tss.begin(), tss.end(), [](train tr) {cout << tr << endl; });

	//or with filter!

	cout << "Enter \"number\" to search by number" << endl;
	cout << "Enter \"dep_time\" to search by departure time" << endl;
	cout << "Enter \"destination\" to search by destination" << endl;
	cin >> feature;
	train tr;


	if (feature == "number") {
		cin >> n;
		tr.getNumber() = n;
	}
	else if (feature == "dep_time") {
		cin >> str1;
		tr.getDepartureTime() = str1;
	}
	else if (feature == "destination") {
		cin >> str2;
		tr.getDestination() = str2;
	}
	for_each(tss.begin(), tss.end(), filter(feature, tr));

	system("pause");
	return 0;
}