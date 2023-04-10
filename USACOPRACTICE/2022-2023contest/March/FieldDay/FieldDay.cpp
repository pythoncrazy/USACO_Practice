#include <iostream>
#include <vector>
#include <string>

int main(){
	int c=0;
	int n=0;
	std::cin>>c>>n;
	std::vector<int> oneCount(n);
	std::string cowss;
	
	for(int i=0;i<n;++i){
		std::cin>>cowss;
		oneCount[i] = std::count(cowss.begin(),cowss.end(), 'G');
	}
	
	return 0;
}