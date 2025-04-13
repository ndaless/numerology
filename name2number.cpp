# include <iostream>
# include <string>
# include <cctype>
# include <map>

using namespace std;

class Numerologia{
    map<char, int> char2num;
public:
    Numerologia(){
        char2num[' '] = 0;
        for(int i = 0; i < 26; i++){
            char c = 'a' + i;
            char2num[c] = i + 1;
        }

        // printMap();
    }

    void printMap(){
        for(const auto par : char2num){
            cout << "{" << par.first << ", " << par.second << "}" << endl;
        }
    }

    int sumNum(int number){
        int sum = 0;
        while(number > 0){
            sum += number%10;
            number /= 10;
        }
        return sum;
    }

    int n2n(const string& name){
        int number = 0;
        for(const auto c : name){
            number += char2num[tolower(c)];
        }
        while(number > 10){
            // cout << number << endl; // para imprimir cada numero
            number = sumNum(number);
        }

        return number;
    }
};


int main(){
    string name;
    Numerologia myNum;

    cout << "Nombre: "; getline(cin, name);
    while(name != "exit"){
        cout << "Numero: " << myNum.n2n(name) << endl << endl;
        // aquí se pueden introducir varias cosas, pe el anio en el q esta, etc.
        cout << "Nombre: "; getline(cin, name);
    }

    return 0;
}
