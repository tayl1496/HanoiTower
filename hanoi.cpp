#include<iostream>
#include<vector>

struct move{
  std::string origin;
  std::string dest;
};
//#define INTERATE
void hanoi(int, std::string, std::string, std::string);
void moveAndIncrement(std::string, std::string);
void getNumOfDiscs(int&, bool&);
void printSoln();

const std::string LINE = "-------------------------------------------";
std::vector<move> moveList;

int main(){

  bool choice = true;
  int numOfDisc = 0;

  getNumOfDiscs(numOfDisc,choice);

  while (choice) {
    #ifdef INTERATE
      for (int i = 1; i <= numOfDisc; ++i) {
        moveList = new std::vector();
        moves = 0;
        std::cout<<std::endl;
        hanoi(i, "A","B","C");
        printSoln();
        std::cout<<std::endl<<LINE<<std::endl
        <<"Final Solution | Number Of Discs: " << i
        <<"  |  Number of Moves: " << moveList.size()
        <<std::endl <<LINE <<std::endl;
      }
    #endif
    #ifndef INTERATE
      std::cout<<std::endl;
      hanoi(numOfDisc, "A","B","C");
      printSoln();
      std::cout<<std::endl<<LINE<<std::endl
      <<"Final Solution | Number Of Discs: " << numOfDisc
      <<"  |  Number of Moves: " << moveList.size()
      <<std::endl <<LINE <<std::endl;
    #endif
    getNumOfDiscs(numOfDisc,choice);
  }

  std::cout<<"Program finished"<<std::endl;
  return 0;
}

void hanoi(int numOfDisc, std::string origin, std::string helper, std::string end) {
  if (numOfDisc > 0) {
      hanoi(numOfDisc - 1, origin, end, helper);
      moveAndIncrement(origin, end);
      hanoi(numOfDisc - 1, helper, origin, end);
  }
}

void moveAndIncrement(std::string from, std::string to) {
  move mov;
  mov.origin = from;
  mov.dest = to;
  moveList.push_back(mov);
  //std::cout<<"move disc from " << from << " to " << to <<std::endl;
}

void getNumOfDiscs(int& num, bool& choice) {
  std::cout<<std::endl
          <<"enter number of discs to use. or a negative number to stop"
          <<std::endl <<": ";
  std::cin>>num;
  if (num < 0) {
    choice = false;
  } else {
    choice = true;
  }

  std::cout<<LINE<<std::endl;
}

void printSoln(){
  for (int i = 0; i < moveList.size(); i++){
    move temp = moveList[i];
    std::cout<<"move disc from " << temp.origin << " to " << temp.dest <<std::endl;
  }
}
