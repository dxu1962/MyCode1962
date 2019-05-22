#include "stdafx.h"
#include "SolvePuzzle.h"

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

SolvePuzzle::SolvePuzzle()
{
}

//Read input from a mapping in a TAML file (better to find a YAML parser to re-implement this function
//The key value pairs are stored in a map
//The map then is converted to a sorted vector<pair<string, int>> ordered by pair's second part (time to cross the bridge)
pair_vec SolvePuzzle::ReadYAMLFile(string filepath)
{
	map<string, int> team;

	string inputfile = filepath;
	string line, line2, key, value;
	int i_value;
	size_t found, length;
	ifstream file(inputfile);
	bool firstLine = true;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			if (firstLine)
			{
				firstLine = false;
				continue;
			}
			line2 = ltrim(line);
			found = line2.find(':');
			if (found != std::string::npos)
			{
				length = line2.length();
				key = line2.substr(0, found);
				value = line2.substr(found + 1, length - found);
				stringstream conv(value);
				conv >> i_value;
				team.insert(std::pair<string, int>(key, i_value));
			}
		}
		file.close();
	}
	pair_vec vec;
	copy(team.begin(), team.end(), std::back_inserter<vector<pair<string, int>>>(vec));
	sort(vec.begin(), vec.end(),
		[](const pair<string, int>& l, const pair<string, int>& r)
	{
		if (l.second != r.second)
			return l.second < r.second;
		return false;
	});
	return vec;
}

int SolvePuzzle::Solve(string filePath)
{
	pair_vec vec = ReadYAMLFile(filePath);
	int n = vec.size();
	pCB = new  CrossBridgeN(vec, n);
	m_MinTime = pCB->TimetoTake();
	return m_MinTime;
}

int SolvePuzzle::Solve2(string filePath)
{
	pair_vec vec = ReadYAMLFile(filePath);
	int n = vec.size();
	pCB = new  CrossBridgeN2(vec, n);
	m_MinTime = pCB->TimetoTake();
	return m_MinTime;
}

SolvePuzzle::~SolvePuzzle()
{
	delete pCB;
	delete pCB2;
}
