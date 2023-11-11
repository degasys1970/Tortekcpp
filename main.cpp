#include <iostream>

using namespace std;

int lnko(int a, int b){
    if (a==b) return a;
    if (a<b) return lnko(a,b-a);
    if (a>b) return lnko(a-b,b);
}

int lkkt(int a, int b){
    return a*b/lnko(a,b);
}

void egyszerusit(int szaml, int nev){
    cout << " = ";
    if (szaml % nev == 0) cout << szaml/nev;
    else cout << szaml/lnko(szaml,nev) << '/' << nev/lnko(szaml,nev);
    cout << endl;
}

int main()
{
    int x1, x2, y1, y2, koznev, osszegsz, oszto, szorzatsz, szorzatn, kulombsegsz, osztsz, osztn;
    cout << "az első tört számlálója: " ;
    cin >> x1;
    cout << "" ;cout << "az első tört nevezője: " ;
    cin >> y1;
    cout << "" ;
    cout << "a második tört számlálója: " ;
    cin >> x2;
    cout << "" ;
    cout << "a második  tört nevezője: " ;
    cin >> y2;
    cout << "" ;
    koznev = lkkt(y1,y2);
    osszegsz = x1 * koznev / y1  + x2 * koznev / y2;
    kulombsegsz = (x1 * koznev / y1) - (x2 * koznev / y2) ;
    szorzatsz = x1 * x2 ;
    szorzatn = y1 * y2 ;
    osztsz = x1 * y2;
    osztn = y1 * x2;
    cout << x1 << " / " << y1 << " + "  << x2 << " / " << y2 ;
    cout << " = " << osszegsz << " / " << koznev << "= " ;
    egyszerusit(osszegsz , koznev);
    cout << x1 << " / " << y1 << " - "  << x2 << " / " << y2 ;
    if (kulombsegsz >0 ){
    cout << " = " << kulombsegsz << " / " << koznev << "=" ;
    egyszerusit(kulombsegsz , koznev);}
    else{
        cout << " = " << kulombsegsz << " / " << koznev << "\n " ;
    }
    cout << x1 << " / " << y1 << " * "  << x2 << " / " << y2 ;
    cout << " = " << szorzatsz << " / " << szorzatn << "= " ;
    egyszerusit(szorzatsz , szorzatn);
    cout << x1 << " / " << y1 << " : "  << x2 << " / " << y2 ;
    cout << " = " << x1 << " / " << y1 << " * "  << y2 << " / " << x2 ;
    cout << " = " << osztsz << " / " << osztn << "= " ;
    egyszerusit(osztsz , osztn);
    return 0;
}
