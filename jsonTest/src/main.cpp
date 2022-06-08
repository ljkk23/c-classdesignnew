#include <iostream>
#include "json.hpp"
using namespace std;

// for convenience
using json = nlohmann::json;
int main(int argc, char *argv[])
{
		// create an empty structure (null)
	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 123;

		// add a Boolean that is stored as bool
	j["happy"] = true;
	std::cout << j << std::endl;
	std::string s = j.dump(); 
	int s2=j["pi"].get<int>();
	std::cout <<  s2<< std::endl;
	std::cout << s << std::endl;

	auto j4 = json::parse(s);
	auto j3 = json::parse(R"({"happy": true, "pi": 3.141})");
	std::cout << j3 << std::endl;
	int s4=j4["pi"].get<int>();
	std::cout << s4<< std::endl;
	bool color=true;
	for (int i = 0; i < 5; i++)
	{
		/* code */

     cout << "(" << s4 << ", " << (color ? "black" : "red") << ") ";
	}
	string s5="ddd";
	string str;
	for (int i = 0; i < 5; i++)
	{
		/* code */

     str+="(" + s5 + ", " + (color ? "black" : "red") + ") "+"\n";
	}
	cout<<str<<endl;

	



}