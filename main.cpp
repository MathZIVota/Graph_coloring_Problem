#include"Color.hpp"

vector < pair<string, int>> Tests{
	//first - filename, second - значение теста, к которому стремимся
{"gc_4_1", 2 },
{"gc_20_1", 3 },
{"gc_20_3", 5 },
{"gc_20_5", 6 },
{"gc_20_7", 8 },
{"gc_20_9", 11 },
{"gc_50_1", 5 },
{"gc_50_3", 8 },
{"gc_50_5", 11 },
{"gc_50_7", 16 },
{"gc_50_9", 24 },
{"gc_70_1", 5 },
{"gc_70_3", 10 },
{"gc_70_5", 15 },
{"gc_70_7", 21 },
{"gc_70_9", 32 },
{"gc_100_1", 6 },
{"gc_100_3", 13 },
{"gc_100_5", 20 },
{"gc_100_7", 26 },
{"gc_100_9", 44 },
{"gc_250_1", 10 },
{"gc_250_3", 24 },
{"gc_250_5", 38 },
{"gc_250_7", 60 },
{"gc_250_9", 94 },
{"gc_500_1", 17 },
{"gc_500_3", 43 },
{"gc_500_5", 66 },
{"gc_500_7", 104 },
{"gc_500_9", 172 },
{"gc_1000_1", 29 },
{"gc_1000_3", 71 },
{"gc_1000_5", 121 },
{"gc_1000_7", 185 },
{"gc_1000_9", 306 },
};

int main() {
  vector<vertex> V;
  string filename;
  int var = 0;
  cout << "1:All files, 2:One file, 3:Console input\n/--> ";
  cin >> var;
  ofstream output_file;
  
  cout.setf(ios::fixed);
  switch (var)
  {
  case 1:
	  output_file.open("Result_all");
	  output_file.setf(ios::fixed);
	  cout << setw(11) << "Filename:";
	  cout << setw(5) << "My" << setw(5) << "MVS" << setw(4) << "%\n";
	  output_file << setw(11) << "Filename:";
	  output_file << setw(5) << "My" << setw(5) << "MVS" << setw(4) << "%\n";
		
	  for (auto test : Tests) {
		  output_file << setw(10) << test.first << ": ";
		  cout << setw(10) << test.first << ": ";
		  input_graph(V, test.first);
		  int num_color = Solution(V);

		  float procent = round(abs((float)num_color - test.second) / (float)test.second * 100);
		  
		  output_file << setw(4) << num_color << " ";
		  output_file << setw(4) << test.second << " ";
		  output_file << setprecision(0) << procent << endl;
		  cout << setw(4) << num_color << " ";
		  cout << setw(4) << test.second << " ";
		  cout << setw(3) << setprecision(0) << procent << endl;
		  V.clear();
	  }
	  
	  break;
  case 2:
	  output_file.open("Result_one");
	  output_file.setf(ios::fixed);
	  cout << "Enter the filename:";
	  cin >> filename;
	  input_graph(V, filename);
	  cout << Solution(V) << endl;
	  output_file << Solution(V) << endl;
	  for (auto v : V) {
		  output_file << v.color << " ";
		  cout << v.color << " ";
	  }
	  cout << endl;
	  break;
  case 3:
	  input_graph(V, "null");
	  cout << Solution(V) << endl;
	  break;
  default:
	  cout << "";
	  break;
  }
  output_file.close();
  cout << "\nEnd\n";
  return 0;
}
