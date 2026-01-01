#include <iostream>
#include <vector>


// ask user for 5 ints. store in vector
void userInput(std::vector<int>& numberInput) {
  const size_t COUNT{5}; // numbers of integers to input
  int number{};

  for (size_t i = 1; i <= COUNT; ++i) {
    std::cout << "Input " << i << " integer: ";
    
    std::cin >> number;
    numberInput.push_back(number);
  }
}


void display(const std::vector<int>& numberInput) {
  int sum{};
  double average{};
  int smallestNum{};
  int largestNum{};
  int evenCount{};
  int oddCount{};

  std::cout << "You entered: ";
  for (int num : numberInput) {
    std::cout << num << " ";
    sum += num;

    if (num < smallestNum || smallestNum == 0) {
      smallestNum = num;
    }
    if (num > largestNum) {
      largestNum = num;
    }
    
    if (num % 2 == 0) {
       evenCount++;
    }
    else {
      oddCount++;
    }
  }
  average = static_cast<double>(sum) / numberInput.size();
  std::cout << std::endl;
  
 


  std::cout << "\n!!Display Menu!!\n\n";
  std::cout << "Total Sum: " << sum << std::endl;
  std::cout << "Average: " << average << std::endl;
  std::cout << "Smallest Number: " << smallestNum << std::endl;
  std::cout << "Largest Number: " << largestNum << std::endl;
  std::cout << "Even numbers: " << evenCount << std::endl;
  std::cout << "Odd numbers: " << oddCount << std::endl;
}




int main() {
  std::vector<int> numberInput{};
  userInput(numberInput);

  display(numberInput);
}
