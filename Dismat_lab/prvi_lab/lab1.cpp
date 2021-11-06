#include <iostream>
#include <math.h>

using namespace std;

long double izracunaj_pomocu_formule(double l1, double l2, double a_0, double a_1, int n) {
    //karakteristicna jednadzba je (x ** 2) - lambda_1 * x - lambda_2 = 0
    long double rez;

    float d = pow(l1, 2) + 4 * l2;
    float x = ((float) l1) / 2;

    //provjeravamo je li diskriminanta jednaka 0, jer se onda drugacije racunaju koeficijenti
    if (d == 0) {
        //trazimo koeficijente c1 i c2, na papiru sam raspisao i dobio ovakvu formulu za pojedini koef.
        float c1 = a_0;
        float c2 = (a_1 - a_0 * x) / x;
        
        // racunamo a_n = c1 * (x ** n) + c2 * n * (x ** n)
        rez = c1 * pow(x, n) + c2 * n * pow(x, n);
    } else {
        if (d < 0) {
            cout << "Diskriminanta je manja od 0" << endl;
            return 0;
            }
        //u slucaju kad diskriminanta nije jednaka nuli,
        //imamo dvije nul-tocke za nasu karakteristicnu jednadzbu
        float x1 = x + sqrt(d)/2;
        float x2 = x - sqrt(d)/2;

        //formula za izracun koef. sam izveo na papiru
        float c2 = (a_0 * x1 - a_1)/(x1 - x2);
        float c1 = a_0 - c2;

        //rez racunamo preko a_n = c1 * (x1 ** n) + c2 * (x2 ** n)
        rez = c1 * pow(x1, n) + c2 * pow(x2, n);
    }
    //pretpostavlja se da su korijeni karakt. jedn. realni brojevi, inace bi bio potreban jos jedan uvjet

    return rez;
}

long double izracunaj_rekurzivno(double l1, double l2, double a_0, double a_1, int n, long double *arr, bool *was) {
    if (n == 0) return a_0;
    else if (n == 1) return a_1;
    else if (was[n] != 0) { //provjeravamo je li već izračunat član a_n, ako je iskoristi se njegova već izračunata vrijednost
        return arr[n];
    }
    else {
        arr[n] = l1 * izracunaj_rekurzivno(l1, l2, a_0, a_1, n - 1, arr, was) + l2 * izracunaj_rekurzivno(l1, l2, a_0, a_1, n - 2, arr, was);
        was[n] = 1; 
        return arr[n];
    }
}

int main(void) {
    double l1, l2; //l1 = lambda_1, l2 = lambda_2, samo sam pojednostavio izraze
    double a_0, a_1;
    int n;
    
    //upisivanje
    cout << "Unesite prvi koeficijent λ_1 rekurzivne relacije: ";
    cin >> l1;
    cout << "Unesite drugi koeficijent λ_2 rekurzivne relacije: ";
    cin >> l2;
    cout << "Unesite vrijednost nultog clana niza a_0: ";
    cin >> a_0;
    cout << "Unesite vrijednost prvog clana niza a_1: ";
    cin >> a_1;
    cout << "Unesite redni broj n trazenog clana niza: ";
    cin >> n;

    //inicijalizacija arr i was polja
    long double arr[n + 1] = {0};
    bool was[n + 1] = {0};

    if (n >= 0) { //provjerava se ispravnost unosa
        long double a_nf, a_nr;
        a_nf = izracunaj_pomocu_formule(l1, l2, a_0, a_1, n);
        cout << "Vrijednost n-tog clana niza pomocu formule: " << a_nf << endl;
    
        a_nr = izracunaj_rekurzivno(l1, l2, a_0, a_1, n, arr, was);
        cout << "Vrijednost n-tog clana niza iz rekurzije: " << a_nr;
    } 

    return EXIT_SUCCESS;
}

