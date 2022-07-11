#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    short N;
    int X, jarak_terdekat = 99999;
    cin >> N >> X;
    int * kupon_terdekat;
    short data_count = 0;
    for (short i = 0; i < N; i++) {
        int kupon_tmp;
        cin >> kupon_tmp;
        int jarak_tmp = abs(X-kupon_tmp);
        if (jarak_tmp < jarak_terdekat) {
            jarak_terdekat = jarak_tmp;
            data_count = 1;
            kupon_terdekat = (int*)realloc(kupon_terdekat, sizeof(int) * data_count);
            kupon_terdekat[0] = kupon_tmp;
            continue;
        }
        if (jarak_tmp == jarak_terdekat) {
            kupon_terdekat = (int*)realloc(kupon_terdekat, sizeof(int) * (++data_count));
            kupon_terdekat[data_count-1] = kupon_tmp;
        }
    }

    sort(kupon_terdekat, kupon_terdekat+data_count);
    for (int i = 0; i < data_count; i++) {
        if (kupon_terdekat[i] < 10000) {
            unsigned int tmp = kupon_terdekat[i];
            while (tmp < 10000) {
                cout << 0;
                tmp *= 10;
            }
        }
        cout << kupon_terdekat[i] << endl;
    }
    free(kupon_terdekat);
    return 0;
}
