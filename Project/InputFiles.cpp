string IntToString(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

string FloatToString(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

bool IsNumber(char key)
{
	if(key >= 48 && key <= 57) return true;
	return false;
}
bool IsWord(char key)
{
	if ((key >= 65 && key <= 90) || (key >= 97 && key <= 122)) return true;
	return false;
}


void InputStopword(Trie *&root) //vua input vua tao cay
{
	ifstream fin;
	string sw; //sw: stop word
	fin.open("Stopword List.txt");
	if (!fin.is_open()) return;
	while (!fin.eof())
	{
		//tao cai cay
	}
	fin.close();
}

void InputData(Trie *&root)
{
	ifstream fin;
	string FileName;
	for (int i=1;i<=25;i++)
		for (int j = 1; j <= 100; j++)
		{
			FileName = CreateFileName(i, j); //tao ten file
			fin.open(FileName);
			if (!fin.is_open())
			{
				cout << "Can't open file " << FileName << endl; //ko mo file dc
				continue;
			}
			cout << FileName << endl;
			//tao cai cay title
			//tao cai cay o day
			fin.close();
		}
}

string CreateFileName(int i, int j)
{
	string GroupNumber = IntToString(i), TxtNumber = IntToString(j);
	if (1 <= i && i <= 9)  
	{
		if (1 <= j && j <= 9)
			return "Group0" + GroupNumber + "News0" + TxtNumber + ".txt"; //Group01News01.txt
		else
			return "Group0" + GroupNumber + "News" + TxtNumber + ".txt"; //Group01News10.txt
	}
	else 
	{
		if (1 <= j && j <= 9)g
			return "Group" + GroupNumber + "News0" + TxtNumber + ".txt"; //Group10News01.txt
		else
			return "Group" + GroupNumber + "News" + TxtNumber + ".txt"; //Group10News10.txt
	}
}