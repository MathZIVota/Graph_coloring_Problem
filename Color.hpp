#pragma once
#include<iostream>
#include<list>
#include<vector>
#include<cmath>
using namespace std;

struct vertex{
  int color;
  vector<int> adj_vert;
};

void input_func(vector<vertex>&, string);
int Solution(vector<vertex>&);
double Solver(int, vector<vertex>);
