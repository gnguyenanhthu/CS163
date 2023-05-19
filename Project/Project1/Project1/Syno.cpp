#include "syno.h"

void syno::inputSynonym()
{
	ifstream fin("Synonyms.txt");
	if (!fin)
	{
		cout << "Can not open file " << endl;
		return;
	}
	int count = 0;
	vector<string> tokens;
	string line;
	while (getline(fin, line))
	{
		count++; // count line number
		istringstream is(line); //split word
		string word;
		while (is >> word)
		{
			//cout << "DM " << word << " at " << count <<endl;
			tokens.push_back(word);
			pos.insert(pair<string, int>(word, count)); // map use to store the position of each word(line number)

		}
		group.push_back(tokens);// group: a 2D vector that store all synonyms 
	}
	fin.close();}

vector<string> syno::getSyno(string key)
{
	map<string, int>::iterator it = pos.find(key);
	//cout << "ENTER " << endl;
	vector <string> word;
	if (it == pos.end())// if key not found
	{
		return vector <string>(1, key);
	}
	//cout << "HERE " << endl;
	int id = it->second;

	for (string a : group.at(id))
		//cout << "GET SYNO " << id << endl;
		word.push_back(a);

	return word;
}