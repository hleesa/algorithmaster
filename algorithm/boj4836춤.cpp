#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

enum danceNum
{
	JIGGLE,
	DIP,
	TWIRL,
	HOP,
	CLAP,
	STOMP,
};

bool rule1(vector<string>& dance, vector<string> toStr)
{
	bool ret = true;
	for(int i=0; i<dance.size(); ++i)
	{
		if (dance[i] == toStr[DIP])
		{
			if ( (i > 0 && dance[i-1] == toStr[JIGGLE])
			|| (i > 1 && dance[i-2] == toStr[JIGGLE])
			|| (i + 1 < dance.size() && dance[i+1] == toStr[TWIRL]))
				continue;
			else
			{
				transform(dance[i].begin(), dance[i].end(), dance[i].begin(),::toupper);
				ret = false;
			}
		}
	}
	return ret;
}

bool rule2(vector<string>& dance, vector<string> toStr)
{
	if(dance.size() < 3)
		return false;
	vector<string>::reverse_iterator rit = dance.rbegin();
	if (*rit == toStr[CLAP] && *(rit+1) == toStr[STOMP] && *(rit+2) == toStr[CLAP])
		return true;
	return false;
}

bool rule3(unordered_set<string>& isAct, vector<string> toStr)
{
	if (isAct.find(toStr[TWIRL]) == isAct.end())
		return true;
	if (isAct.find(toStr[HOP]) == isAct.end())
		return false;
	return true;
}

bool rule4(vector<string>& dance, string& danceName)
{
	if (dance.empty() || dance.front() == danceName)
		return false;
	return true;
}

bool rule5(unordered_set<string>& isACt, string& danceName)
{
	if (isACt.find(danceName) == isACt.end())
		return false;
	return true;
}

vector<int> checkRules(vector<string>& dance, vector<string> toStr,unordered_set<string>& isAct)
{
	vector<bool> isFollowRules(6);
	isFollowRules[1] = rule1(dance, toStr);
	isFollowRules[2] = rule2(dance, toStr);
	isFollowRules[3] = rule3(isAct, toStr);
	isFollowRules[4] = rule4(dance, toStr[JIGGLE]);
	isFollowRules[5] = rule5(isAct, toStr[DIP]);
	vector<int> ret;
	for (int i=1; i<=5; ++i)
	{
		if (isFollowRules[i])
			continue;
		ret.push_back(i);
	}
	return ret;
}

vector<string> split(string input)
{
	vector<string> ret;
	stringstream sstream;
	sstream.str(input);
	string str;
	while (sstream >> str)
		ret.push_back(str);
	return ret;
}
void setIsAct(vector<string>& dance, unordered_set<string>& isAct)
{
	for(string d : dance)
		isAct.insert(d);
}

void print(vector<int> errors, vector<string>& dance)
{
	vector<string> out(2);
	out[0] = "form ";
	if (errors.size() == 0)
		out[1] = "ok: ";
	else if (errors.size() == 1)
		out[1] = "error " + to_string(errors.front()) + ": ";
	else
	{
		out[1] = "errors ";
		for (int i = 0; i + 1 < errors.size(); ++i)
		{
			out[1] += to_string(errors[i]);
			if(i+2 < errors.size())
				out[1] += ", ";
			else
				out[1] += " ";
		}
		out[1] += "and " + to_string(errors.back()) + ": ";

	}
	cout << out[0] << out[1];
	for(int i=0; i + 1< dance.size(); ++i)
		cout << dance[i] << " ";
	cout << dance.back() << '\n';
}

int main()
{
	vector<string> toStr = {"jiggle", "dip", "twirl", "hop",
							  "clap", "stomp"};
	string input;
	while (getline(cin, input))
	{
		vector<string> dance = split(input);
		unordered_set<string> isAct;
		setIsAct(dance, isAct);
		vector<int> errors = checkRules(dance, toStr, isAct);
		print(errors, dance);
	}
	return (0);
}