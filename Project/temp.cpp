string Engine::OpenFile(int i, int j) {//Viet
	string group = NumberToString(i), txt = NumberToString(j);
	if (i < 10 && j < 10) return ("Group0" + group + "_0" + txt + ".txt");
	else if (i < 10) return ("Group0" + group + "_" + txt + ".txt");
	else if (i >= 10 && j < 10 && i < 15) return ("Group" + group + "_0" + txt + ".txt");
	else if (i >= 10 && j >= 10 && i < 15) return ("Group" + group + "_" + txt + ".txt");
	else return ("Data" + txt + ".txt");
}

