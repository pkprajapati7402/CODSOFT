// Task 2 Simple Calculator

// Develop a calculator progrm that performs basic arithemetic operations such as additon, subntraction, multiplication, and division, Allow the user to input two number and choose an operation to perform.

#include <iostream>
using namespace std;
class calc{
    public: 
        int add(int a, int b){
            return (a + b);
        }
        int subtract(int a, int b){
            return (a-b);
        }
        double multiply(int a, int b){
            return (a*b);
        }
        float divide(int a, int b){
            return (a / b);
        }
};
int main(){
    int a, b, n;
    calc obj;
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";
    cout << "Enter your choice: ";
    cin >> n;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    
        switch(n){
        case 1: 
            cout << "Sum = " << obj.add(a,b);
            break;
        case 2:
            cout << "Subtraction =  " << obj.subtract(a,b); 
            break;
        case 3:
            cout << "Multiplication = " << obj.multiply(a,b);
            break;
        case 4:
            if(b == 0){
                cout << "Denominator can't be 0";
                break;
            } else{
                cout << "Division = " << obj.divide(a,b);
                break;
            }
        default:
            cout << "Invalid choice!"; break;
    }
    
}
