#include "Trie.h"

void InputStopwords(vector<string> stopwords)
{
	ifstream fin;
	fin.open("Stopwords_List.txt");
	if (!fin.is_open())
	{
		cout << "Can not open file" << endl;
		return;
	}
	string str;
	while (getline(fin, str))
	{
		if (str.size() > 0)
			stopwords.push_back(str);
	}
	cout << "Stopwords List.txt" << endl;
	fin.close();
}

bool isStopwords(string query, vector<string> stopwords){
	for (vector<string>::iterator i = stopwords.begin(); i != stopwords.end(); ++i)
	{
		if (query == *i)
			return true;
	}
	return false;
}
