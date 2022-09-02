#include <iostream>
#include <vector>
#include <armadillo>

int main() {
	std::vector<double> vec{3.141, 2.718, 1.414};
	for (auto e : vec) {
		std::cout << e << std::endl;
	}
	std::cout << vec[5] << std::endl;
//	std::cout << vec.at(5) << std::endl;
	arma::mat A = arma::randu(3,4);
	A.print("pirnt matrix A:");
	std::cout << "print A(5,6)" << std::endl;
	std::cout << A[5,6] << std::endl;
//	std::cout << A(5,6) << std::endl;

	return 0;
}
