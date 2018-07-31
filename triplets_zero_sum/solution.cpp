#include <iostream>
#include <vector>

void solution(const std::vector<int>& input)
{
	for (size_t i = 0;i < input.size()-2;++i) {
		for (size_t j=i+1;j<input.size()-1;++j) {
			for (size_t k=j+1;k<input.size();++k) {
				if (input[i] + input[j] +input[k] == 0) {
					std::cout<<input[i]<<" "<<input[j]<<" "<<input[k]<<std::endl;
				}
			}
		}
	}
}

int main()
{
	std::vector<int> input1{0, -1, 2, -3, 1};
	solution(input1);
	std::cout << "-----------------------"<< std::endl;
	std::vector<int> input2{1, -2, 1, 0, 5};
	solution(input2);
	return 0;
}