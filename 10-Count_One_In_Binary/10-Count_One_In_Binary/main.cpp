#include <iostream>
using namespace std;

int countOne(int  number){
    int result = 0;
    while(number)
    {
        result++;
        number = (number - 1) & number;
    }
    return result;
}

int main(){
    int number = 9;
    int result = countOne(number);
    printf("The Count of One in %d is %d\n", number, result);
    getchar();
    return 0;
}