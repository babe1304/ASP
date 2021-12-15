#include <iostream>

using namespace std;

class vozilo {
    string model;
    int godina_proizvodnje;

    public:
        vozilo() {}
        vozilo(string model, int godina_proizvodnje) : model(model), godina_proizvodnje(godina_proizvodnje) {}
        int getGodina() {return godina_proizvodnje;}
        string getModel() {return model;}

        bool operator<(const vozilo &other) {
            if (this->model[0] < other.model[0]) return true;
            else if (this->model == other.model) {
                if (this->godina_proizvodnje > other.godina_proizvodnje) return true;
                else return false;
            } else return false;
        }
};

void Zamijeni(vozilo &prvi, vozilo &drugi) {
    vozilo temp = prvi;
    prvi = drugi;
    drugi = temp;
}

template <class T> void SelectionSort(T A[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) if (A[j] < A[min]) min = j;
        Zamijeni(A[min], A[i]);
    }
}

int main(void) {
    vozilo vozila[] = {{"Pauegot",1981}, {"Pauegot",1983}, {"Ranulet",1967}, {"Fait",1972}, {"BWM",1985}, {"Merdesec",1983}};
    for (int i = 0; i < 6; i++) cout << vozila[i].getModel() << " " << vozila[i].getGodina() << " ";
    cout << endl;
    SelectionSort(vozila, 6);
    for (int i = 0; i < 6; i++) cout << vozila[i].getModel() << " " << vozila[i].getGodina() << " ";

    return EXIT_SUCCESS;
}