/*
 Meno a priezvisko:
 
 POKYNY:
 (1)  Subor premenujte na Priezvisko_Meno_ID_du01.cpp (pouzite vase udaje bez diakritiky).
 (2)  Implementujte funkcie tak, aby splnovali popis pri ich deklaraciach.
 (3)  Cela implementacia musi byt v tomto jednom subore.
 (4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
 (5)  Program musi byt kompilovatelny.
 (6)  Globalne a staticke premenne su zakazane.
 (7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
 (8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
 (9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
 Testovaci kod ale nebude hodnoteny.
 (10) Funkcia 'main' musi byt v zdrojovom kode posledna.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Bod v rovine
struct Point {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Usecka v rovine
struct Line {
    Point start; // zaciatocny bod
    Point end;   // koncovy bod
};

// Student
struct Student {
    char *name; // meno studenta
    int year;  // rocnik studia
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

// Matematicka funkcia
enum class Operation {
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE
};

// Vstup pre matematicky vypocet funkcie s dvoma parametrami
struct CalculationInput {
    int operand1; // prvy parameter
    int operand2; // druhy parameter
    Operation operation; // funkcia
};

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vytlaci obsah pola na standardny vystup (cout/stdout).
 Format tlace:
 - prvky pola (cisla) su oddelene jednou medzerou
 - pred prvym prvkom je gulata otvaracia zatvorka (medzi zatvorkou a cislom nesmie byt medzera)
 - za poslednym prvkom je gulata zatvaracia zatvorka (medzi cislom a zatvorkou nesmie byt medzera)
 
 PARAMETRE:
 [in] data - pole cisiel
 [in] length - dlzka pola 'data'
 
 VSTUPNE PODMIENKY:
 'length' moze mat lubovolnu hodnotu
 'data' ukazuje na platne pole
 
 PRIKLADY:
 prazdne pole: ()
 jednoprvkove pole: (10)
 10 prvkove pole: (8 -5 100000 2 1 2 4 5 -20 345)
 */
void printArray(const int * data, int length) {
    // TODO
    cout<<"(";
    for (int i=0; i<length; ++i) {
        if (i==length-1) {
            cout<<data[i];
        }
        else cout<<data[i]<<" ";
    }
    cout<<")"<<endl;
    
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Zo standardneho vstupu nacita dve cele cisla (typu 'int') a vrati ich sucet.
 
 RETURN:
 sucet cisiel nacitanych zo standardneho vstupu (cin/stdin)
 
 VSTUPNE PODMIENKY:
 Textovy vstup zadany na standardny vstup programu obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
 Nemusite osetrovat moznost chybnych udajov zadanych na standardny vstup.
 
 PRIKLADY:
 Ak je na standardny vstup zadany text "10 20\n" (bez uvodzoviek), tak funkcia vrati 30.
 Ak je na standardny vstup zadany text " 10 \n 20 \n" (bez uvodzoviek), tak funkcia vrati 30.
 */
int sumOfTwoNumbersFromConsole(){
    // TODO
    int a,b;
    cout<<"Zadaj 2 čísla:"<<endl;
    cin>>a>>b;
    return a+b; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vrati 'true' ak 'text' obsahuje velke pismeno, inak vrati 'false'.
 
 PARAMETER:
 [in] text - textovy retazec ukonceny '\0'
 
 RETURN:
 'true' - ak 'text' obsahuje aspon jedno velke pismeno
 'false' - ak 'text' neobsahuje ani jedno velke pismeno (plati aj pre prazdny retazec)
 
 POZNAMKA:
 Pri implementacii pouzite funkciu 'std::isupper'.
 */
bool containsUpperCase(const char *text) {
    // TODO
    size_t p=strlen(text);
    for (int i=0; i<p; ++i) {
        if (isupper(*(text+i))) {
            return true;
        }
    }
    return false; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vrati 'true' ak 'data' obsahuje stupajucu postupnost, inak vrati 'false'.
 
 PARAMETRE:
 [in] data - pole hodnot
 [in] length - pocet prvkov pola 'data'
 
 RETURN:
 'true' - ak 'data' obsahuje stupajucu postupnost hodnot, alebo pocet prvkov pola je mensi ako 2
 'false' - v opacnom pripade
 
 PRIKLADY:
 data = {10, 11, 15, 20} => vysledok je 'true'
 data = {10, 15, 15, 20} => vysledok je 'false'
 data = {10, 11, 15, 12} => vysledok je 'false'
 data = {10}             => vysledok je 'true'
 data = {}               => vysledok je 'true'
 */
bool isAscending(const int *data, int length) {
    // TODO
    if (length<2) {
        return true;
    }
    for (int i=0; i<length-1; ++i) {
        if (data[i]>=data[i+1]) {
            return false;
        }
    }
    return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Posunie hodnoty pola 'data' o 1 miesto vyssie. Hodnotu posledneho prvku presunie na zaciatok.
 
 PARAMETRE:
 [in,out] data - pole hodnot, ktore bude preusporiadane
 [in] length - pocet prvkov pola 'data'
 
 PRIKLADY:
 {10, 20, 30, 40, 50} => {50, 10, 20, 30, 40}
 {10} => {10}
 {} => {}
 */
void shiftUp(int *data, int length) {
    // TODO
    if (length<2) {
        return;
    }
    int tmp=data[length-1];
    for (int i=length-2; i>=0; i--) {
        data[i+1]=data[i];
    }
    data[0]=tmp;
    
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Preusporiada pole 'data' tak, ze jeho prvky budu v opacnom poradi.
 
 PARAMETRE:
 [in, out] data - pole hodnot, ktore bude preusporiadane
 [in] lenght - pocet prvkov pola 'data'
 
 PRIKLADY:
 {10, 20, 30, 40, 50} => {50, 40, 30, 20, 10}
 {10, 20, 30, 40} => {40, 30, 20, 10}
 {10} => {10}
 {} => {}
 */
void reverse(int * data, int length) {
    // TODO
    int tmp;
    for (int i=0; i<length/2; ++i) {
        tmp=data[i];
        data[i]=data[length-i-1];
        data[length-i-1]=tmp;
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vrati dlzku usecky 'line'
 
 PARAMETER:
 [in] line - usecka
 
 RETURN:
 dlzka usecky 'line'
 
 PRIKLAD:
 line:
 start:
 x=10
 y=20
 end:
 x=100
 y = 50
 return 94.868329805
 */
double length(const Line * line) {
    // TODO
    double x=line->end.x - line->start.x;
    double y=line->end.y - line->start.y;
    return sqrt(x*x+y*y); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vrati dlzku usecky 'line'
 
 PARAMETER:
 [in] line - usecka
 
 RETURN:
 dlzka usecky 'line'
 
 PRIKLAD:
 line:
 start:
 x=10
 y=20
 end:
 x=100
 y = 50
 return 94.868329805
 */
double length(const Line & line) {
    // TODO
    double x=line.end.x-line.start.x;
    double y=line.end.y-line.start.y;
    return sqrt(x*x+y*y); // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vytvori noveho studenta s menom 'name' a rocnikom studia 'year'.
 Vrati smernik na vytvoreneho studenta.
 
 PARAMETRE:
 [in] name - meno studenta
 [in] year - rocnik v ktorom student studuje
 
 RETURN:
 vytvoreny student
 
 VSTUPNE PODMIENKY:
 'name' je textovy retazec ukonceny '\0'
 */
Student * createStudent(const char *name, int year) {
    // TODO
    Student *std1 = new Student{(char*)name,year};
    return std1; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
 Vypocita celociselny matematicky vypocet zadany parametrom 'input'.
 Vysledok ulozi do 'output'.
 
 PARAMETRE:
 [in] input - vstupne udaje pre matematicky vypocet
 [out] output - vystupna hodnota vypoctu (v pripade moznosti vypoctu)
 
 RETURN:
 Result::SUCCESS - ak je mozne vypocitat vyslednu hodnotu
 Result::FAILURE - ak nie je mozne vypocitat vyslednu hodnotu (v pripade delenia nulou)
 
 VYSTUPNE PODMIENKY:
 - Vysledok vypoctu je celociselny.
 - Ak je mozne vykonat vypocet, tak sa vysledok ulozi do 'output' a funkcia vrati 'Result::SUCCESS',
 inak (v pripade delenia nulou) sa hodnota 'output' nemeni a funkcia vrati 'Result::FAILURE'.
 */
Result calculate(int *output, const CalculationInput * input) {
    // TODO
    if (input->operation==Operation::DIVIDE && input->operand2==0)return Result::FAILURE;

    else {
        switch (input->operation) {
            case Operation::DIVIDE:
                *output=input->operand1/input->operand2;
                break;
            case Operation::MULTIPLY:
                *output=input->operand1*input->operand2;
                break;
            case Operation::PLUS:
                *output=input->operand1+input->operand2;
                break;
            case Operation::MINUS:
                *output=input->operand1-input->operand2;
                break;
            default:
                break;
        }
        return Result::SUCCESS;
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main(int argc, char** argv) {
    // tu mozete doplnit testovaci kod
    //int array[]={1,2,3,4,5,6,7,8,9,10};
//    int data[] = {10,11,12,13,14,15};
//    Line ciara={.end.x=100,.end.y=50,.start.x=10,.start.y=20};
    //printArray(array,1);
    //cout<<containsUpperCase("abcD aosdD ")<<endl;
    //cout<<isAscending(data, 4)<<endl;
//    shiftUp(data, 2);
//
//    reverse(data, 6);
//    for (int i=0; i<6; ++i) {
//        cout<<data[i]<<" ";
//    }
//    cout<<endl;
//    cout<<length(ciara)<<endl;
//    cout<<sumOfTwoNumbersFromConsole()<<endl;
    
//    int a=5;
//    CalculationInput in{10,2,Operation::DIVIDE};
//    if (calculate(&a, &in)==Result::FAILURE) {
//        cout<<"FAIL"<<endl;
//    }
//    else cout<<"SUCCESS"<<endl;
//    cout<<a<<endl;
//    Student *st=createStudent("Daniel", 3);
//    cout<<st->name<<endl;
    return 0;
}
