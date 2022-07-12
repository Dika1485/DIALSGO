// m = (y2-y1) / (x2-x1)//
// y = mx + c
// c = y1 - (m * x1)

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double x,y; // posisi iron man
    cin>>x>>y;
    int n; // jml ultron
    cin>>n;
    double ultron[n][2];
    for(int i=0;i<n;i++){
        cin>>ultron[i][0]>>ultron[i][1];
    }
    int k; // jml sisi bangunan
    cin>>k;
    double sisi[k][4];
    for (int i = 0; i < k; i++)
        cin >> sisi[i][0] >> sisi[i][1] >> sisi[i][2] >> sisi[i][3];

    int counter = 0;
    for (int i = 0; i < n; i++) {
        // mencari persamaan garis lurus ironman-ultron dengan mencari nilai m dan c
        double p = ultron[i][0];
        double q = ultron[i][1];

        int flag = 1;

        // menentukan apakah berpotongan dengan sisi
        if (p == x) { // apabila garis lurus vertikal
            for (int j = 0; j < k; j++) {
                double a = sisi[j][0];
                double b = sisi[j][1];
                double c = sisi[j][2];
                double d = sisi[j][3];
                
                if (a == c) {
                    if (x == a && min(y,q) <= min(b,d) && max(y,q) >= max(b,d)) {
                        flag = 0;
                        break;
                    }
                } else if (b == d) {
                    if (p <= max(a,c) && p >= min(a,c) && b <= max(y,q) && b >= min(y,q)) {
                        flag = 0;
                        break;
                    }
                } else {
                    double m_sisi = (d-b) / (c-a);
                    double c_sisi = b - (m_sisi * a);
                    double x_sisi = p;
                    double y_sisi = (m_sisi * x_sisi) + c_sisi;
                    if (y_sisi <= max(b,d) && y_sisi >= min(b,d) && y_sisi <= max(y,q) && y_sisi >= min(y,q)) {
                        flag = 0;
                        break;
                    }
                }
            }
        } else if (q == y) { // apabila garis lurus horizontal
            for (int j = 0; j < k; j++) {
                double a = sisi[j][0];
                double b = sisi[j][1];
                double c = sisi[j][2];
                double d = sisi[j][3];

                if (b == d) {
                    if (y == b && min(x,p) <= min(a,c) && max(x,p) >= max(a,c)) {
                        flag = 0;
                        break;
                    }
                } else if (a == c) {
                    if (q <= max(b,d) && q >= min(b,d) && a <= max(x,p) && a >= min(x,p)) {
                        flag = 0;
                        break;
                    }
                } else {
                    long double m_sisi = (d-b) / (c-a);
                    double c_sisi = b - (m_sisi * a);
                    double y_sisi = q;
                    double x_sisi = (y_sisi - c_sisi) / m_sisi;
                    if (x_sisi <= max(a,c) && x_sisi >= min(a,c) && x_sisi <= max(x,p) && x_sisi >= min(x,p)) {
                        flag = 0;
                        break;
                    }
                }
            }
        } else {
            double m_ult = (q-y) / (p-x);
            double c_ult = y - (m_ult * x);

            for (int j = 0; j < k; j++) {
                double a = sisi[j][0];
                double b = sisi[j][1];
                double c = sisi[j][2];
                double d = sisi[j][3];

                if (a == c) { // apabila sisi vertikal
                    double x_ult = a;
                    double y_ult = (m_ult * a) + c_ult;
                    if (y_ult <= max(b,d) && y_ult >= min(b,d)) {
                        flag = 0;
                        break;
                    }
                } else if (b == d) { // apabila sisi horizontal
                    double y_ult = b;
                    double x_ult = (y_ult - c_ult) / m_ult;
                    if (x_ult <= max(a,c) && x_ult >= min(a,c)) {
                        flag = 0;
                        break;
                    }
                } else {
                    double m_sisi = (d-b) / (c-a);
                    double c_sisi = b - (m_sisi * a);

                    double tmp1 = m_ult + (m_sisi * -1);
                    double tmp2 = c_sisi + (c_ult * -1);
                    double xp = tmp2 / tmp1;
                    double yp = (m_ult * xp) + c_ult;
                    if (xp <= max(a,c) && xp >= min(a,c) && yp <= max(b,d) && yp >= min(b,d)) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) counter++;
    }
    cout << counter << endl;
}
