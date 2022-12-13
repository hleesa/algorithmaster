#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

	vector<int> choiceToScore = {0, 3, 2, 1, 0, 1, 2, 3, 0};
	vector<int> typeToScore(256, 0);
	for (int i = 0; i < choices.size(); ++i)
	{
		int choice = choices[i];
		int typeIdx = choice / 4;
		int type = survey[i][typeIdx];
		typeToScore[type] += choiceToScore[choice];
	}
	vector<string> toType = {"RT", "CF", "JM", "AN"};
	string answer;
	for (int i=0; i<toType.size(); ++i)
	{
		if (typeToScore[toType[i][0]] >= typeToScore[toType[i][1]])
			answer.append(1, toType[i][0]);
		else
			answer.append(1, toType[i][1]);
	}
	return answer;
}
