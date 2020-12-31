#include <iostream>
#include <string>

#include <metaf/metaf.hpp>

using namespace metaf;


std::string report = 
	  "KDDC 112052Z AUTO 19023G34KT 7SM CLR 33/16 A2992"
	  " RMK AO2 PK WND 20038/2033 SLP096 T03330156 58018";


int main() {
  	std::cout << "Parsing report: " << report << "\n";
  	const auto result = Parser::parse(report);
  	std::cout << "Parse error: "; 
  	std::cout << errorMessage(result.reportMetadata.error) << "\n";	
  	std::cout << "Detected report type: "; 
  	std::cout << reportTypeMessage(result.reportMetadata.type) << "\n";
  	std::cout << result.groups.size() << " groups parsed\n"
}
