#include"Color.hpp"

double Solver(int i, vector<vertex> &V, int max_color){
  int used_color = 0;
  list<int> temp;
  temp.push_back(i);
  V[i].color = 0;
  used_color++;
  for(auto v: V[i].adj_vert){
    temp.push_back(v);
    V[v].color = used_color;
      
  }
  return 0;
};

int Solution(vector<vertex>&V){
  list<int> color;
  int max_adj = V[0].adj_vert.size();
  int max_adj_index = 0;
  for(size_t i=0; i<V.size(); i++) color.push_back(i);
  
  for(size_t i=1; i<V.size(); i++){
    int tmp_adj = V[i].adj_vert.size();
    if(max_adj < tmp_adj) {
      max_adj = tmp_adj;
      max_adj_index = i;
    }
  }
  
  int Size = color.size();
  color.resize(max_adj+1);
  
  return max_adj;
}
