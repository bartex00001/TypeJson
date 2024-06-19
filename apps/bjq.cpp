#include <iostream>
#include <unordered_map>

#include <BetterJson/json.hpp>


int main()
{
	json::Array arr;
	arr.push_back(json::Int(123));
	arr.push_back(json::String("Hello there"));
	arr.push_back(json::Float(1.0));

	std::shared_ptr< json::Json > newOwner{arr.getOwner(0)};
	json::Int copy{arr[0].as< json::Int >()};
	json::Int& ref{arr[0].as< json::Int >()};

	json::Json::castTo< json::Bool >(arr.getOwner(0));
	arr[0].as< json::Bool >() = true;

	std::cout << arr;

	std::cout
		<< "\ncopy: " << copy
		<< "\nowner: " << *newOwner
		<< "\nref: " << ref;
}
