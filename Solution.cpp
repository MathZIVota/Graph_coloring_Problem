#include"Color.hpp"

int UsedColors(vertex v, vector<vertex> V, vector<int> &used){
  for(auto w: v.adj_vert){
    int tmp_color = V[w].color;
    if(tmp_color >= 0) used[tmp_color] = 1;
  }
  int s;
  for(s=0; used[s] == 1; s++); 
  for(auto &u: used) u = 0;
  return s;
}

int Solver(int i, vector<vertex> &V, int max_color){
  list<int> temp;
  vector<int> color_used;
  for(int j=0; j<max_color; j++) color_used.push_back(0);
  

  temp.push_back(i);
  V[i].color = 0;
  int tmp = i;
  while(!temp.empty()){
    for(auto v: V[tmp].adj_vert){
      if(V[v].color < 0) temp.push_back(v);
      V[v].color = UsedColors(V[v], V, color_used);
    }
    temp.pop_front();
    if(!temp.empty()) tmp = temp.front();
  }
  for(auto v: V) {
    
  }
  int num_color = -1;
  for(auto &v: V) {
    if(v.color < 0) v.color = UsedColors(v, V, color_used);
    if(num_color < v.color) num_color = v.color;
  }
  
  return (num_color+1);
};

int Solution(vector<vertex>&V){
  list<int> color;
  int max_adj = V.front().adj_vert.size();
  int max_adj_index = 0;
  for(size_t i=0; i<V.size(); i++) color.push_back(i);
  for(size_t i=1; i<V.size(); i++){
    int tmp_adj = V[i].adj_vert.size();
    if(max_adj < tmp_adj) {
      max_adj = tmp_adj;
      max_adj_index = i;
    }
  }
  color.resize(max_adj+1);
  int num_color = Solver(max_adj_index, V, max_adj);
  
  return num_color;
}
