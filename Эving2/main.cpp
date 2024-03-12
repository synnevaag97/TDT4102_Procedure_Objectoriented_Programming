#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

void inputAndPrintInteger(){
    int input;
    cout << "Give me a number: " << endl;
    cin >> input;
    cout << input << endl;
}

int inputInteger(){
    int input;
    cout << "Give me a number: " << endl;
    cin >> input;
    return input;
}

void inputIntegersAndPrintSum(){
    int number1 = inputInteger();
    int number2 = inputInteger();

    cout << number1+number2 << endl;
}

bool isOdd(int number){
    if(number%2==0){
        return true;
    }else{
        return false;
    }
}

void printHumanReadableTime(int seconds){
    int hours = seconds/(60*60);
    seconds = seconds % (60*60);
    int minutes = seconds/60;
    seconds = seconds%60;
    cout << "Hours: " << hours << " Minutes: " << minutes << " Seconds: "<< seconds << endl;
}


void summingNumbersPrintTotal(){
    int numbers;
    int number;
    int total = 0;
    cout << "How many numbers? " << endl;
    cin >> numbers;
    for(int i = 1; i<=numbers; ++i){
        cout << "Give a number: " << endl;
        cin >> number;
        total += number;
    }
    cout << total << endl;
}

void summingNumberTillBreak(){
    int number;
    int total = 0;
    do{
        cout << "Give a number: " << endl;
        cin >> number;
        total += number;
    }while(number != 0);

    cout << total << endl;
}


double inputDouble(){
    double number;
    cout << "Give us a desimal number: " << endl;
    cin >> number;
    return number;
}

void convertNOKToEURO(){
    double euro = inputDouble();
    double NOK = euro*9.75;
    cout << fixed << setprecision(3) << NOK << endl;
}

void gangetabell(){
    int height;
    int width;
    cout << "Give height: " << endl;
    cin >> height;
    cout << "Give width: " << endl;
    cin >> width;
    for(int i = 1; i<=height; ++i){
        for(int j = 1; j<=width;++j){
            cout << i*j << endl;
        }
    }
}

double discriminant(double b, double a, double c){
    return (pow(b,2.0)-4.0*a*c);
}

void printRealRoots(double b, double a, double c){
    double y; 
    double root1;
    double root2;
    y = discriminant(b,a,c);
    if (y == 0) {
        root1 = -b/2*a;
        cout << root1 << endl;
    } else if (y < 0) {
        cout << "There is no real solution." << endl;
    } else if (y > 0) {
        root1 =  (-b+y)/2*a;
        root2 = (-b-y)/2*a;
        cout << "Root 1 is: " << root1 << ", root2 is: " << root2 << endl;
    }
}

void solveQuadraticEquation(){
    double a;
    double b;
    double c;
    cout << "Give us three decimal numbers: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    printRealRoots(b,a,c);
}


void pythagoras(){
    using namespace Graph_lib;
    Simple_window win{Point{100,100},400,400,"Pythagoras"};

    Polygon rightTriangle;
    rightTriangle.add(Point{150,150});
    rightTriangle.add(Point{250,150});
    rightTriangle.add(Point{150,250});
    rightTriangle.set_fill_color(Color::red);
    win.attach(rightTriangle);

    Polygon square1;
    square1.add(Point{150,150});
    square1.add(Point{250,150});
    square1.add(Point{250,100});
    square1.add(Point{150,100});
    square1.set_fill_color(Color::green);
    win.attach(square1);

    Polygon square2;
    square2.add(Point{150,150});
    square2.add(Point{150,250});
    square2.add(Point{100,250});
    square2.add(Point{100,150});
    square2.set_fill_color(Color::green);
    win.attach(square2);

    Polygon square3;
    square3.add(Point{250,150});
    square3.add(Point{150,250});
    square3.add(Point{200,300});
    square3.add(Point{300,200});
    square3.set_fill_color(Color::green);
    win.attach(square3);


    win.wait_for_button();
}

vector<int> calculateBalance(int initialsaldo, int rente, int aar){
    vector<int> balance;
    int saldo;
    for(int i = 0;i <= aar; ++i){
        saldo = initialsaldo*pow(1+static_cast<double>(rente)/100,i);
        balance.push_back(saldo);
    }
    return balance;
}

void printBalance(vector<int> balance){
    cout << setw(4) << "År: " << setw(7) << "Saldo: " << endl;
    for(unsigned int i = 0; i < balance.size(); ++i){
        cout <<setw(3) << i << setw(7) << balance[i] << endl;
    }
}

int main(){
    int choice = -1;

    while(choice != 0){
            cout << "0) Avslutt \n"
             << "1) Print integer\n"
             << "2) Return integer\n"
             << "3) Summer to tall\n"
             << "4) Test oddetallsfunksjonen\n"
             << "5) Konverter sekunder\n"
             << "6) Summer flere tall (for)\n"
             << "7) Summer flere tall (do-while)\n"
             << "8) Print desimal number\n"
             << "9) Konverter NOK til EURO\n"
             << "10) Skriv ut gangetabell\n"
             << "11) Los kvadratiske ligninger\n"
             << "12) Pythagoras\n"
             << "13) Regn ut renter\n";

        cout << "Angi valg (0-13): " << endl;
        cin >> choice;

        switch (choice){
            case 0:
                break;
            case 1:
                inputAndPrintInteger();
                break;
            case 2:
                int number;
                number = inputInteger();
                cout << "Number is: " << number << endl;
                break;
            case 3:
                inputIntegersAndPrintSum();
                break;
            case 4:
                for(int i=0; i<=15; ++i){
                    cout << isOdd(i) << endl;
                }
                break;
            case 5: 
                cout << "How many seconds do you want to convert? " << endl;
                int seconds;
                cin >> seconds;
                printHumanReadableTime(seconds);
                break;
            case 6:
                summingNumbersPrintTotal();
                break;
            case 7:
                summingNumberTillBreak();
                break;
            case 8:
                cout << inputDouble();
                break;
            case 9:
                convertNOKToEURO();
                break;
            case 10:
                gangetabell();
                break;
            case 11:
                solveQuadraticEquation();
                break;
            case 12:
                pythagoras();
                break;
            case 13:
                vector<int> balance; 
                balance = calculateBalance(10000,5,10);
                printBalance(balance);
                break;
        }
    }
}