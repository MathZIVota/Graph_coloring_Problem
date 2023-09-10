#include"Color.hpp"

double Solver(int i, vector<vertex> &V, int max_color){
  cout << "color: ";
  for(auto v: V) cout << v.color << " ";
  cout << endl;
  
  int used_color = 0;
  list<int> temp;
  vector<int> color_used;
  cout << endl;
  for(int j=0; j<max_color; j++) {
    color_used.push_back(0);
    cout << color_used[j] << ", ";
  }
  cout << endl;
  temp.push_back(i);
  V[i].color = 0;
  used_color++;
  int tmp = i;
  while(!temp.empty()){
    cout << "! " << temp.front() << ":\n";
    for(auto v: V[tmp].adj_vert){
      cout << "v-" << v << endl;
      if(V[v].color < 0) temp.push_back(v);
      for(auto w: V[v].adj_vert){
        cout << "w-" << w << " ";
        int tmp_color = V[w].color;
        cout << "tmp->" << tmp_color << endl;
        if(tmp_color >= 0) color_used[tmp_color] = 1;
      }
      cout << endl;
      int s;
      for(s=0; s<max_color && color_used[s] == 1; s++); 
      V[v].color = s;
    }
    for(auto &u: color_used) u = 0;
    temp.pop_front();
    if(!temp.empty()) tmp = temp.front();
    cout << endl;
  }
  cout << "color: ";
  for(auto v: V) cout << v.color << " ";
  cout << endl;
  return 0;
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
  
  int Size = color.size();
  color.resize(max_adj+1);
  Solver(max_adj_index, V, Size);
  
  return max_adj;
}
