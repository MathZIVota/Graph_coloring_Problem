#pragma once
#include<iostream>
#include<fstream>
#include <iomanip>
#include<list>
#include<vector>
#include<cmath>
using namespace std;

struct vertex{
  int color;
  vector<int> adj_vert;
};

void input_graph(vector<vertex>&, string);
int UsedColors(vertex, vector<vertex>, vector<int>&);
int Solution(vector<vertex>&);
double Solver(int, vector<vertex>);
