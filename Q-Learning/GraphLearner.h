#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include "Graph.h"
#include "Node.h"
#include <fstream>

#include "LinkedList.h"
#include "LinkNode.h"

#define GREEDY		1
#define NONGREEDY	0

struct state
{
	Node* current_node;
	wchar_t visited_nodes;
};

enum action { GOTO0, GOTO1, GOTO2, GOTO3, GOTO4, GOTO5, GOTO6, GOTO7, GOTO8, GOTO9, GOTO10, GOTO11, GOTO12, GOTO13, GOTO14, GOTO15 };
static action actions[] = { GOTO0, GOTO1, GOTO2, GOTO3, GOTO4, GOTO5, GOTO6, GOTO7, GOTO8, GOTO9, GOTO10, GOTO11, GOTO12, GOTO13, GOTO14, GOTO15 };

class GraphLearner
{
public:
	GraphLearner();

	void QLearning();

	state GetNextState(state s, action a);
	float GetReward(state state, action a);
	action GetNextAction(state s);
	action GetNextGreedyAction(state s);
	float GetHighestActionValue(state s);

	bool greedy_or_nongreedy(float epsilon);

	void print_route();

	float GetRandomReward(float mean, float std_deviation);

	std::vector<int> get_xplot();
	std::vector<float> get_yplot();
	std::vector<int> get_zplot();

	~GraphLearner();
private:
	state cstate;
	// Random return of TRUE or FALSE - is used to determine which action to take, if multiple actions have the same action-value estimate.
	bool random_choice();

	Graph graph;
	void init_environment();
	int amount_nodes = 0;

	LinkNode* head = new LinkNode( 0, 0, 0, 0 );
	LinkedList* Q = new LinkedList(*head);
	

	float discount_factor = 0.9;
	float learning_rate = 0.5;
	float alpha = 0.5;
	float epsilon = 0.1;

	std::vector<int> xplot;
	std::vector<float> yplot;
	std::vector<int> zplot;

	std::string action_text[16] = { "GOTO0", "GOTO1", "GOTO2", "GOTO3", "GOTO4", "GOTO5", "GOTO6", "GOTO7", "GOTO8", "GOTO9", "GOTO10", "GOTO11", "GOTO12", "GOTO13", "GOTO14", "GOTO15" };
};

