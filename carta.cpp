# include <iostream>
# include <string>
# include <cctype>
# include <ctime>
# include <map>

using namespace std;

class CartaNum{
private:
    map<char, int> char2num;
    string name; int dia, mes, anio;

    void fillMap(){
        char2num[' '] = 0;
        for(int i = 0; i < 26; i++){
            char c = 'a' + i;
            char2num[c] = (i % 9) + 1;
        }
    }

    void printMap(){
        for(const auto par : char2num){
            cout << "{" << par.first << ", " << par.second << "}" << endl;
        }
    }

    int sumNum(int& number){ // suma los digitos de un numero
        int sum = 0;
        while(number > 0){
            sum += number%10;
            number /= 10;
        }
        return sum;
    }

    int reduceNum(int& number){ // suma los digitos del numero hasta reducirlo < 10
        while(number >= 10){
            // cout << number << endl; // para imprimir cada numero
            if(number == 11 || number == 22 || number == 33) break;
            number = sumNum(number);
        }
        return number;
    }

public:
    CartaNum(string& _name, const int& _dia, const int& _mes, const int& _anio){
        name = _name; dia = _dia; mes = _mes; anio = _anio;

        fillMap();

        // printMap();
    }

    int getAlma(){
        int number = 0;
        for(auto& c : name){
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                number += char2num[c];
        }

        return reduceNum(number);
    }

    int getPersonalidad(){
        int number = 0;
        for(auto c : name){
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                number += char2num[c];
                // cout << c << "=" << char2num[c] << " ";
            }
        }

        return reduceNum(number);
    }

    int getMision(){
        int number = 0;
        for(auto c : name){
            number += char2num[c];
        }

        return reduceNum(number);
    }

    int getSendero(){
        int number = 0;

        number += (dia + mes + anio);

        return reduceNum(number);
    }

    int getNumPotencial(){
        int number = getSendero() + getMision();
        
        return reduceNum(number);
    }

    int getAnioPersonal(){
        int number = 0;

        time_t t = time(nullptr); // obtienen el tiempo actual
        tm* now = localtime(&t); // convierte el tiempo a formato local

        int thisYear = now -> tm_year + 1900;
        
        number = dia + mes + thisYear;

        return reduceNum(number);
    }

    void getCarta(){
        cout << "Para " << name << " obtenemos:" << endl;

        cout << "- Alma: " << getAlma() << endl;
        cout << "- Personalidad: " << getPersonalidad() << endl;
        cout << "- Mision: " << getMision() << endl;
        cout << "- Sendero de Vida: " << getSendero() << endl;
        cout << "- Numero Potencial: " << getNumPotencial() << endl;
        cout << "- Año Personal: " << getAnioPersonal() << endl;
        
    }
};


int main(){
    string name; int dia, mes, anio;

    // leemos todo los datos necesarios para generar la carta
    cout << "Nombre: "; getline(cin, name);
    cout << "Dia (dd): "; cin >> dia;
    cout << "Mes (mm): "; cin >> mes;
    cout << "Año (yyyy): "; cin >> anio;
    cout << endl;

    // obtenemos la carta
    CartaNum myNum(name, dia, mes, anio);
    myNum.getCarta();

    return 0;
}
