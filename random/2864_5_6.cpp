#include <iostream>
#include <string>

using namespace  std;

int main() {
    string a, b;
    cin >> a >> b;
    string smalla = a, smallb = b, largea = a, largeb = b;
    
    for(int i = 0; i < a.size(); i++) {
        if(a.at(i) == '5') {
            largea.at(i) = '6';
        }
        if(a.at(i) == '6') {
            smalla.at(i) = '5';
        }
    }
    for(int i = 0; i < b.size(); i++) {
        if(b.at(i) == '5') {
            largeb.at(i) = '6';
        }
        if(b.at(i) == '6') {
            smallb.at(i) = '5';
        }
    }
    int sa, sb, la, lb;

    sa = atoi(smalla.c_str());
    sb = atoi(smallb.c_str());
    la = atoi(largea.c_str());
    lb = atoi(largeb.c_str());

    cout << sa + sb << " " << la + lb << endl;
    
    return 0;
}