#include"Color.hpp"
#include<fstream>

void input_func(vector<vertex>&V, string filename){
  int N, M, s, f; //N-кол-во вершин, M-кол-во ребер, текщее ребро из s в f
  vertex W; 
  if(filename == "null"){
    cin >> N;
    for (size_t i = 0; i < N; i++) {
      V.push_back(W);
    }
    cin >> M;
    for(size_t i=0; i<M; i++){
      cin >> s >> f;
      V[s].adj_vert.push_back(f);
      V[f].adj_vert.push_back(s);
    }
  }
  else{
    ifstream input_file(filename); 
    if (input_file.is_open()) {
      input_file >> N;
      for (size_t i = 0; i < N; i++) {
        V.push_back(W);
      }
      input_file >> M;
      for(size_t i=0; i<M; i++){
        input_file >> s >> f;
        V[s].adj_vert.push_back(f);
        V[f].adj_vert.push_back(s);
      }
    }
  input_file.close();
  }
  
}
