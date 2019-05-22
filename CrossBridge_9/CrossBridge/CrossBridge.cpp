// CrossBridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "SolvePuzzle.h"



int main()
{
	string filePath = "c:\\temp\\team.yaml";
	SolvePuzzle solver;
	solver.Solve(filePath);
	cout << "Minimum Time from solver: " << solver.GetMinTime() << endl;
	cout << endl;
	cout << "Members" << endl;
	solver.DisplayMembers();
	cout << endl;
	cout << "Actions" << endl;
	solver.DisplayActions();

	solver.Solve2(filePath);
	cout << endl;
	cout << endl;
	cout << "Minimum Time from solver2: " << solver.GetMinTime() << endl;
	return 0;
}

