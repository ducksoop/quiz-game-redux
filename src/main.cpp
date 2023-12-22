#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;

int main()
{
	// Create a JSON object
	nlohmann::json j;

    // Add data to it
    j["name"] = "John Doe";
    j["age"] = 30;
    j["is_student"] = false;
    j["skills"] = { "C++", "Python", "JSON" };

    // Serialize it to a string
    std::string serialized = j.dump();  // You can also use dump(4) for pretty printing

    // Output the serialized string
    std::cout << serialized << std::endl;

    return 0;
}
