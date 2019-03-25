#include<iostream>

using namespace std;

class Czas{

private:
    int h;
    int m;
    int s;
    static int suma;
    
public:
    Czas();
    Czas(int h, int m, int s = 0);

    int getH() { return this->h; }
    int getM() { return this->m; }
    int getS() { return this->s; }

    void setH(int h) {
        if(h >=0 && h < 24) this->h = h; 
        else cout << "Wrong hour format" << endl;
    }

    void setM(int m) {
        if(m >=0 && m < 60) this->m = m;
        else cout << "Wrong minute format" << endl;
    }

    void setS(int s) {
        if(s >=0 && s < 60) this->s = s;
        else cout << "Wrong secund format" << endl;
    }

    void printTime(){
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }

    ostream& wypisz(ostream& out);
    istream& zapisz(istream& in);

    static int getSuma();
    bool equals(const Czas & time) const;
    void addS() { this->s++; }
};

int Czas::suma = 0;

Czas::Czas(){
    this->h = 12;
    this->m = 0;
    this->s = 0;
    Czas::suma = 3600 * 12;
};

Czas::Czas(int h, int m, int s){
    if(h >=0 && h < 24 && m >=0 && m < 60 && s >=0 && s < 60){
        this->h = h;
        this->m = m;
        this->s = s;
        Czas::suma = 3600 * h + 60 * m + s;
    }
    else{
        cout << "Wrong parameters" << endl;
    }
};

ostream& Czas::wypisz(ostream& out){
    out << this->h << ":" << this->m << ":" << this->s << endl;
    return out;
}

istream& Czas::zapisz(istream& in){
    char item;
    in >> h >> item >> m >> item >> s;
    return in;
}

int Czas::getSuma(){
    return suma;
}

bool Czas::equals(const Czas & time) const {
    return this->h == time.h && this->m == time.m && this->s && time.s;
}

int main(){
    
    cout << "Start test:" << endl;
    cout << "Create time1" << endl;
    Czas time1;
    cout << "time1.printTime(): ";
    time1.printTime();
    cout << endl;

    cout << "time1.wypisz(): ";
    time1.wypisz(std::cout);
    cout << endl;

    cout << "Set parameters: ";
    time1.setH(12);
    time1.setM(20);
    time1.setS(30);
    time1.wypisz(std::cout);
    cout << endl;

    cout << "Get Czas::time: ";
    cout << Czas::getSuma() << endl;

    cout << "time1.addS(): ";
    time1.addS();
    time1.wypisz(std::cout);
    cout << endl;

    cout << "Create time2" << endl;
    Czas time2(10, 11, 12);
    time2.wypisz(std::cout);

    cout << "Equals time1 == time2: " << time1.equals(time2) << endl;
    cout << "Hour: " << time1.getH() << endl;
    cout << "Insert time: ";
    time1.zapisz(std::cin);
    time1.wypisz(std::cout);

    return 0;
}
