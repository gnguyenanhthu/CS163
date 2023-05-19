////Final Project: Mini Search Engine
////Course: CS163_17CTT
////Group: 14
//
//#include "Trie.h"
//#include "Syno.h"
//
//int main() {
//
//	//Anh Thu
//
//	trieNode *root = newNode();
//	string searchkey;
//	string continuee = "y";
//	bool first = true;
//	int choice;
//	syno synonym;
//	vector<string>stopwords;
//	clock_t startSearch, endSearch, searchTime;
//
//	cout << "Loading data...Please wait a moment..." << endl;
//	//Kieu Phuong
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	auto start1 = std::chrono::high_resolution_clock::now(); //start counting trie-building time
//
//	InputData(root);  //trie is being built
//
//	auto end1 = std::chrono::high_resolution_clock::now(); //end counting trie-building time
//
//	//synonym.inputSynonym();
//	InputStopwords(stopwords);
//
//	while (continuee == "y" || continuee == "Y") {
//		cout << "Input search key: "; 
//		if (!first)
//		{
//			cin.ignore();
//		}
//		getline(cin, searchkey, '\n');//--------------UPDATED
//		first = false;
//		//searchkey = std::string(searchkeyArr);
//		//cout << "CHECKING " << searchkey << endl;
//		//cout << "My searchkey: " << searchkey << endl;
//
//	Menu:;
//		cout << "Menu: " << endl;
//		cout << "1. Search" << endl;
//		cout << "2. Suggest history" << endl;
//		cout << "3. Clear history" << endl;
//		cout << "Your choice: ";
//		cin >> choice;
//		if (choice == 1)
//		{
//			startSearch = clock();
//			//if (searchkey[0] == '~')
//			//{
//			//	vector<string>syno;
//			//	syno=synonym.getSyno(searchkey);
//			//	for (int i = 0; i < syno.size(); i++)
//			//	{
//			//		if (!search(root, syno[i]))
//			//			continue;
//			//		else {
//			//			makeColor(10);
//			//			cout << endl << "SEARCH RESULT(S): '" << syno[i] << endl << endl;
//			//			makeColor(7);
//			//			//Display function goes here
//			//			//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
//			//			vector<displayedItem> display;
//			//			retrieval(syno[i], display);
//			//		}
//			//		endSearch = clock();
//			//		searchTime = endSearch - startSearch;
//			//		makeColor(13);
//			//		cout << "Searching time: " << (float)searchTime / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//			//		makeColor(7);
//			//		cout << "\nDo you want to continue? (y/n)  ";
//			//		cin >> continuee;
//			//		cout << endl;
//			//	}	
//			//}
//			double a, b;
//			bool range = isRange(searchkey, a, b);
//			if(range)
//			bool check = intitle(searchkey); //SEARCH INTITLE
//			bool exact = checkexact(searchkey);
//			bool temp = search(root, searchkey);
//		
//			if (exact) temp = true;
//			if (!temp) { //switch yes & no statement
//				makeColor(10);
//				cout << endl << "KEYWORD DOES NOT EXIT!" << endl << endl;
//				makeColor(7);
//			}
//			else {
//				makeColor(10);
//				cout << endl << "SEARCH RESULT(S):" << endl << endl;
//				makeColor(7);
//				//Display function goes here
//				//For each KEY/QUERY, creat a vector of potential displayed items then choose 5 highest score files to display
//				vector<displayedItem> display;
//				retrieval(searchkey, display, check, exact);
//			}
//			endSearch = clock();
//			searchTime = endSearch - startSearch;
//			makeColor(13);
//			cout << "Searching time: " << (float)searchTime / CLOCKS_PER_SEC * 1000 << "ms" << endl;
//			makeColor(7);
//			OutputHistory(searchkey); //this word has been search
//			cout << "\nDo you want to continue? (y/n)  ";
//			cin >> continuee;
//			cout << endl;
//		}
//		if (choice == 2)
//		{
//			cout << endl << "History: " << endl;
//			History(searchkey);
//			cout << endl;
//			goto Menu;
//		}
//		if (choice == 3)
//		{
//			clearHistory();
//			cout << endl << "History has been cleared." << endl << endl;
//			goto Menu;
//		}
//	}
//
//	//Kieu Phuong
//
//	std::chrono::duration<double> diff1 = end1 - start1; //double, duration
//	makeColor(13);
//	cout << "Trie-building time: " << chrono::duration <double, milli>(diff1).count() << "ms" << endl;
//
//	cin.get();
//	cin.get();
//	return 0;
//}
#include "menu.h"
#include "button.h"
int main()
{

	Menu menu;
	_getch();

	return 0;
}