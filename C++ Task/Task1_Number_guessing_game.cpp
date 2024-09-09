// Create a program that generates a random number and asks the user to guess it.
// Provide feedback on whether the guess is too high or too low untill the user guesses the correct number.

#include <iostream>
using namespace std;
int main(){
    int ll = 1, ul = 20, ans;
    cout << "Enter lower and upper limit: "; 
    cin >> ll >> ul;
    srand(time(0));
    int ranum = ll + rand() % (ul - ll + 1);
    cout << "Guess the number: ";
    cin >> ans;
    while(ans != ranum){
        if(ans < ranum){
            cout << "\nToo Low.";
        } else{
            cout << "\nToo High.";
        }
        cout << "\nGuess the number: ";
        cin >> ans;
    }
    cout << "Yes, value is: " << ranum;
    
    return 0;
}
