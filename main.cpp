#include"Color.hpp"

vector < pair<string, double>> Tests{
	//first - filename, second - значение теста, к которому стремимся
{"4_1 ", 2 },
{"20_1 ", 3 },
{"20_3 ", 5 },
{"20_5 ", 6 },
{"20_7 ", 8 },
{"20_9 ", 11 },


{"50_1 ", 5 },
{"50_3 ", 8 },
{"50_5 ", 11 },
{"50_7 ", 16 },
{"50_9 ", 24 },

{"70-1 ", 5 },
{"70_3 ", 10 },
{"70_5 ", 15 },
{"70_7 ", 21 },
{"70_9 ", 32 },

{"100_1 ", 6 },
{"100_3 ", 13 },
{"100_5 ", 20 },
{"100_7 ", 26 },
{"100_9 ", 44 },

{"250_1 ", 10 },
{"250_3 ", 24 },
{"250_5 ", 38 },
{"250_7 ", 60 },
{"250_9 ", 94 },

{"500_1 ", 17 },
{"500_3 ", 43 },
{"500_5 ", 66 },
{"500_7 ", 104 },
{"500_9 ", 172 },

{"1000_1 ", 29 },
{"1000_3 ", 71 },
{"1000_5 ", 121 },
{"1000_7 ", 185 },
{"1000_9 ", 306 },
};

int main() {
  vector<vertex> V;
  string filename;
  int flag = 0;
  cout << "1:All files, 2:One file, 3:Console input\n/--> ";
  cin >> flag;
  if (flag == 1) {
	  for (auto t : Tests) {
		  cout << t.first << ": ";
		  input_func(V, t.first);
		  double min_dist = Solution(V);
		  float procent = round(abs(min_dist - t.second) / t.second * 100);
		  cout << min_dist << " " << t.second << " " << procent << endl;
	  }
  }
  if (flag == 2) {
		  cout << "Enter the filename:";
		  cin >> filename;
		  input_func(V, filename);

		  cout << Solution(V) << endl;
	  }
  if(flag == 3) {
     input_func(V, "null");
  }
  cout << "End\n";
  return 0;
}
