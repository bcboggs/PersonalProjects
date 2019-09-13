//Brandy Boggs
//5/29/2019
//A* vs Branch and Bound
//CIS 497 Assignment 2

#include<iostream>
using namespace std;
#include<stdio.h>	
#include<vector>
#include<string>
#include<algorithm>

vector<vector<int>> finalDestination;

//print function that prints the over-arching entire pathway
void printVector(vector<vector<vector<vector<int>>>> expanded) {
	for (int w = 0; w < expanded.size(); w++) {
		cout << "Path:\n";
		for (int j = 0; j < expanded[w].size(); j++) {

			for (int i = 0; i < expanded[w][j].size(); i++) {
				for (int x = 0; x < expanded[w][j][i].size(); x++) {
					cout << expanded[w][j][i][x] << " ";

				}
				cout << endl;
			}
			cout << endl;
		}

	}
}


//print function prints a single pathway 
void printVector(vector<vector<vector<int>>> expanded) {
	for (int j = 0; j < expanded.size(); j++) {

		for (int i = 0; i < expanded[j].size(); i++) {
			for (int x = 0; x < expanded[j][i].size(); x++) {
				cout << expanded[j][i][x] << " ";

			}
			cout << endl;
		}
		cout << endl;
	}
}

//generate function that takes in a pathway and based off the last state on the path, it returns a list of new paths
//does not add pathways that are in the duplicates list.
//if a position is a night then it checks all the possible places it can move to, if it is not a night moves to the next space.
vector<vector<vector<vector<int>>>> generate(vector<vector<vector<int>>> state, vector<vector<vector<int>>> duplicates) {
	vector<vector<vector<vector<int>>>> result;//list to add the found new paths to
	int b = state.size() - 1;

	for (int y = 0; y < state[b].size(); y++) {
		for (int x = 0; x < state[b][y].size(); x++) {//check for each position, loop through positions in the grid.

			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y + 2 <= 2) && (x - 1 >= 0)) {//not off the grid down left
					if ((state[b][y + 2][x - 1] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y + 2][x - 1];
						temp[b + 1][y + 2][x - 1] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}
			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y + 2 <= 2) && (x + 1 <= 2)) {//not off the grid down right
					if ((state[b][y + 2][x + 1] == 0)) {//not a knight there already
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y + 2][x + 1];
						temp[b + 1][y + 2][x + 1] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}
			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y - 2 >= 0) && (x - 1 >= 0)) {//not off the grid up left
					if ((state[b][y - 2][x - 1] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y - 2][x - 1];
						temp[b + 1][y - 2][x - 1] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}
			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y - 2 >= 0) && (x + 1 <= 2)) {//not off the grid up right
					if ((state[b][y - 2][x + 1] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y - 2][x + 1];
						temp[b + 1][y - 2][x + 1] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}

			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y + 1 <= 2) && (x + 2 <= 2)) {//not off the grid right down
					if ((state[b][y + 1][x + 2] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y + 1][x + 2];
						temp[b + 1][y + 1][x + 2] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}

			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y - 1 >= 0) && (x + 2 <= 2)) {//not off the grid right up
					if ((state[b][y - 1][x + 2] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y - 1][x + 2];
						temp[b + 1][y - 1][x + 2] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}

			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y - 1 >= 0) && (x - 2 >= 0)) {//not off the grid left up
					if ((state[b][y - 1][x - 2] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y - 1][x - 2];
						temp[b + 1][y - 1][x - 2] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}

			if (state[b][y][x] != 0) {//if it is a knight
									  //now if statements for if each direction of movement is possible.
				if ((y + 1 <= 2) && (x - 2 >= 0)) {//not off the grid left down
					if ((state[b][y + 1][x - 2] == 0)) {//not a knight there
						vector<vector<vector<int>>> temp = state;
						int tempNum;
						temp.push_back(state[b]);
						tempNum = temp[b + 1][y][x];
						temp[b + 1][y][x] = temp[b + 1][y + 1][x - 2];
						temp[b + 1][y + 1][x - 2] = tempNum;
						bool isDup = false;
						for (int i = 0; i < duplicates.size(); i++) {
							if (duplicates[i] == temp[temp.size() - 1]) {
								isDup = true;
							}
						}
						if (!isDup) {
							result.push_back(temp);
						}
					}
				}
			}
			//brackets
		}
	}

	return result;//return the full result

}

//takes in a pathway, checks the last state in the path, uses some values i came up with to try and estimate that
//states distance from the destination. It is not a perfect and always correct estimation by far.
//checks where each knight is and guess how far they are from the goal, this could be 
//way better with a better distance funciton.
int distance(vector<vector<vector<int>>> check, vector<vector<int>> goal) {
	int tdist = 0;

	int b = check.size() - 1;
	for (int y = 0; y < check[b].size() - 1; y++) {
		for (int x = 0; x < check[b][y].size() - 1; x++) {
			if (check[b][y][x] != 0) {

				if (check[b][y][x] == 1) {
					if ((y == 0 && x == 0) || (y == 0 && x == 2)) {
						tdist = tdist + 2;
					}
					else if ((y == 1) && (x == 2 || x == 0)) {
						tdist = tdist + 1;
					}
					else if ((x == 1) && (y == 0)) {
						tdist = tdist + 1;
					}
					else if ((y == 2 && x == 0) || (y == 2 && x == 2)) {
						tdist = tdist + 0;
					}
					else {
						tdist = tdist + 2;
					}
				}

				if (check[b][y][x] == 2) {
					if ((y == 2 && x == 0) || (y == 2 && x == 2)) {
						tdist = tdist + 2;
					}
					else if ((y == 1) && (y == 0 || x == 2)) {
						tdist = tdist + 1;
					}
					else if ((x == 1) && (y == 2)) {
						tdist = tdist + 1;
					}
					else if ((y == 0 && x == 0) || (y == 0 && x == 2)) {
						tdist = tdist + 0;
					}
					else {
						tdist = tdist + 2;
					}
				}

			}

		}
	}
	return tdist;
}




// Removes all of the branches that end in a state that are in the duplicates vector.
//things are added to the duplicates vector when they are expanded on.
//so you never expanded on the same state twice.
vector<vector<vector<int>>> remDup(vector<vector<vector<vector<int>>>>& path, vector<vector<vector<int>>> duplicates) {
	bool xDeleted = false;
	for (int x = 0; x < path.size(); x++) {
		if (xDeleted) {
			x--;
			xDeleted = false;
		}
		if ((path.size() - x) > 1) {
			for (int i = 0; i < duplicates.size(); i++) {
				if (!xDeleted) {
					if (path[x][path[x].size() - 1] == duplicates[i]) {
						path.erase(path.begin() + x);
						xDeleted = true;
						continue;
					}
				}
			}
		}
	}
	return duplicates;
}






 //predicate function for the sort function in branch and bound. 
 //just finds the cost by taking the size of pathways.
bool isLess(vector<vector<vector<int>>> g1, vector<vector<vector<int>>> g2) {
	return g1.size() < g2.size();
}

//predicate function for sorting in a* sorts based off of cost and the distance to the goal.
//we multiply the for distane by a higher value than the cost because we are underestimating the distance, so that is a more
//important metric, we want to attempt to take the search down a good path before branching out more.
bool isLess2(vector<vector<vector<int>>> g1, vector<vector<vector<int>>> g2) {
	return (g1.size() * 3 + distance(g1, finalDestination) * 4) < (g2.size() * 3 + distance(g2, finalDestination) * 4);
}//dont currently have adistance thing




//the search function that searches with a* method using the above functions.
void astar(vector<vector<vector<vector<int>>>> source, vector<vector<int>> goal, int generationCount, vector<vector<vector<int>>> duplicates) {

	if (source.empty()) {
		cout << "There is no solution" << endl;
	}//if the first path ends with the goal state, you have found the answer.
	else if (source[0][source[0].size() - 1] == goal) {
		cout << "Path found, it is: " << endl;
		printVector(source[0]);
	}
	else {//otherwise generate new paths, add them in, sort them and remove the duplicates.
		vector<vector<vector<vector<int>>>> temp;
		if (true)
			duplicates.push_back(source[0][source[0].size() - 1]);//add the state to the list of duplicates before we expand on it.
		temp = generate(source[0], duplicates);
		vector<vector<vector<vector<int>>>> sourcetemp;
		sourcetemp.reserve(temp.size() + source.size() - 1);
		sourcetemp.insert(sourcetemp.end(), temp.begin(), temp.end());
		sourcetemp.insert(sourcetemp.end(), source.begin() + 1, source.end());//adding the results of the generate back to start1
		cout << "Concurrent Set " << generationCount << endl;//counts how many generations have been uh, you know, generated

		remDup(sourcetemp, duplicates);//removing duplicates
		sort(sourcetemp.begin(), sourcetemp.end(), isLess2);//sorting the paths with the predicate function
		printVector(sourcetemp);	//printing
		astar(sourcetemp, goal, generationCount + 1, duplicates);//another recursive call, pass in the list so far. increase count of generates, duplicates
	}
}






//another overload functions to allow for different formats of input
void astar(vector<vector<vector<int>>> start, vector<vector<int>> goal, vector<vector<vector<int>>> duplicates) {
	vector<vector<vector<vector<int>>>> temp;
	temp.push_back(start);
	int generationCount = 0;
	astar(temp, goal, generationCount, duplicates);
}

//overload function to allow different formats of input to search
void astar(vector<vector<int>> start, vector<vector<int>> goal, vector<vector<vector<int>>> duplicates) {
	vector<vector<vector<int>>> temp;
	temp.push_back(start);
	astar(temp, goal, duplicates);
}




//the search function that searches with the branch and bound method of searching
void branchandbound(vector<vector<vector<vector<int>>>> start, vector<vector<int>> goal, int generationCount, vector<vector<vector<int>>> duplicates) {

	if (start.empty()) {
		cout << "There is no solution" << endl;
	}//if the first path ends with the goal state, you have found the answer.
	else if (start[0][start[0].size() - 1] == goal) {
		cout << "Path found, it is: " << endl;
		printVector(start[0]);
	}
	else {
		vector<vector<vector<vector<int>>>> temp;

		temp = generate(start[0], duplicates);
		vector<vector<vector<vector<int>>>> start1;
		start1.reserve(temp.size() + start.size() - 1);
		start1.insert(start1.end(), temp.begin(), temp.end());
		start1.insert(start1.end(), start.begin() + 1, start.end());
		cout << "Next Set " << generationCount << endl;

		sort(start1.begin(), start1.end(), isLess);
		//printVector(start1);
		branchandbound(start1, goal, generationCount + 1, duplicates);
	}
}

void branchandbound(vector<vector<vector<int>>> start, vector<vector<int>> goal, vector<vector<vector<int>>> duplicates) {
	vector<vector<vector<vector<int>>>> temp;
	temp.push_back(start);
	int generationCount = 0;
	branchandbound(temp, goal, generationCount, duplicates);
}

void branchandbound(vector<vector<int>> start, vector<vector<int>> goal, vector<vector<vector<int>>> duplicates) {
	vector<vector<vector<int>>> temp;
	temp.push_back(start);
	branchandbound(temp, goal, duplicates);
}




int main() {

	vector<vector<vector<int>>> duplicates;
	vector<vector<int>> start;//initialize the starting position.
	for (int i = 0; i < 3; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			temp.push_back(0);
		}
		start.push_back(temp);
	}
	start[0][0] = 1;
	start[0][2] = 1;
	start[2][0] = 2;
	start[2][2] = 2;

	vector<vector<int>> solution;//initialize the ending position.
	for (int i = 0; i < 3; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			temp.push_back(0);
		}
		solution.push_back(temp);
	}
	solution[0][0] = 2;
	solution[0][2] = 2;
	solution[2][0] = 1;
	solution[2][2] = 1;


	//global variable for the goal
	//used because sort predicate function could not use a third parameter for goal.
	finalDestination = solution;//this needs to be a global variable to be used in the predicate sorting function.
	string wsearch;
	cout << "Which Search: ";
	cin >> wsearch;

	//search selection
	if (wsearch.compare("astar") == 0)
		astar(start, solution, duplicates);
	if (wsearch.compare("bnb") == 0)
		branchandbound(start, solution, duplicates);


	//breakpoint for the end of the function.
	cout << "done";
	cin >> wsearch;
}
//change var names
//change how main selects which search 
//reorganize functions
//change parameter names
///change finalDestination to a different name
