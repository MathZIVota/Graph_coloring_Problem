#pragma once
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct vertex{
  vector<int> adj_vert;
};

void input_func(vector<vertex>&, string);
double Solution(vector<vertex>&);
double Solver(int, vector<vertex>);
