
#include <iostream>
#include <vector>
#include <random> 
#include <ctime>
using namespace std;
void F5(vector <int> data, int len, int dn, int& c1) {
    int c2 = 1;
    int c3 = 0;
    for (int i = 0; i < len; i++) {
        if (data[i] == dn) {
            c2 = 0;
            c3 += 1;
        }
    }
    if (c2 == 1) {
        c1 = 1;
    }
    else {
        c1 = 0;
    }
}
void F1(vector <int>& data, int len, int con = 0) {
    if (con == 0) {
        for (int i = 0; i < len; i++) {
            int r = rand();
            r = r % len;
            if (r != 0) {
                i -= 1;
                data.push_back(r);
            }
        }
    }
    if (con == 1) {
        int i = 0;
        int c1 = 3;
        while (i < len) {
            int r = rand() % 10;
            int c2 = data.size();
            F5(data, c2, r, c1);
            if (r != 0 && c1 == 1) {
                i++;
                data.push_back(r);
            }
        }
    }
}
void F2(vector <int> data, int len) {
    for (int i = 0; i < len; i++) {
        cout << data[i]<<endl;
    }
}
void F3(vector <vector <int>>& data, int x, int max) {// k^2
    for (int i = 0; i < x; i++) {
        vector <int> d1;
        for (int i2 = 0; i2 < x; i2++) {
            int r = rand() % max;
            if (r != 0) {

                i2 -= 1;
                d1.push_back(r);
            } 
        }
        data.push_back(d1);
    }
}
void F4(vector <vector<int>> data, int k2) {
    cout << "======"<<endl;
    for (int i = 0; i < k2; i++) {
        int k3 = data[i].size();
        for (int i2 = 0; i2 < k3; i2++) {
            if(data[i][i2] == 0){
                cout<<"_ ";
            }
            else{
                cout << data[i][i2]<<" ";
            }
        }
        cout << endl;
    }
    cout << "======"<<endl;
}
void F6(vector <vector <int>>& data, int x, int max) {
    vector <int> d1;
    int len_d1 = 0;
    int c = 8;
    int c1 = 1;
    for (int i = 0; i < x; i++) {
        vector <int> d2;
        int i1 = 0;
        while (i1 < x) {
            int r = rand() % max;
            F5(d1, len_d1, r, c);
            if ((c1 == 1 && r != 0 ) || (c == 1 && r != 0)  ) {
                c1 = 0;
                len_d1++;
                i1++;
                d2.push_back(r);
                d1.push_back(r);
            }
        }
        data.push_back(d2);
    }
}
// Block 2
void F7(vector<vector <int>>& data) {
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            for (int i2 = 0; i2 < 6; i2++) {
                data[i].push_back(0);
            }
        }
    }
}
void F8(vector<vector<int>>& data, int z1) {
    for (int i = 0; i < z1; i++) {
        vector<int> d1(9);
        /*for (int i2 = 0; i2 < 9; i2++) {
            d1.push_back(0);
        }*/
        data.push_back(d1);
    }
}
void F9(vector<vector<int>>& data, int stb) {
    vector <int> d1;
    int len = data.size();
    for (int i = 0; i < len; i++) {
        if (data[i][stb] != 0) {
            d1.push_back(data[i][stb]);
        }
    }
    F1(d1, 6, 1);
    //F2(d1, d1.size());
    for (int i = 0; i < len; i++) {
        data[i][stb] = d1[i];
    }
}
// Block 3
void F10_1(vector <vector<int>>& data, int i,int i2,int ra, int con = 0) {
    int len = data.size();
    int slice = 3;
    for (int s = 0; s < slice; s++) {
        if (con == 0) {
            data[i][i2 + s] = data[i + ra][s];
        }
        if (con == 1) {
            data[i][i2 + s] = data[i - ra][s];
        }
    }
}
void F10(vector <vector<int>>& data, int con = 0) {
    int len = data.size();
    for (int i = 0; i < len; i++) {
        for (int i2 = 0; i2 < len; i2+=3) {
            if (i2 == 3 && i == 0) {
                F10_1(data, i, i2,2); 
            }
            if (i2 == 3 && i == 1) {
                F10_1(data, i, i2,1,1);
            }
            if (i2 == 3 && i == 2) {
                F10_1(data, i, i2,1,1);
            }
            if (i2 == 6 && i == 0 && con == 0) {
                F10_1(data, i, i2, 1);
            }
            if (i2 == 6 && i == 1 && con == 0) {
                F10_1(data, i, i2, 1);
            }
            if (i2 == 6 && i == 2 && con == 0) {
                F10_1(data, i, i2, 2, 1);
            }
        }
    }
}
void F10_center(vector <vector<int>>& data) {
    int len = data.size();
    for (int i = 0; i < len; i++) {
        for (int i2 = 0; i2 < len; i2 += 3) {
            if (i2 == 3 && i == 3) {
                F10_1(data, i, i2, 2);
            }
            if (i2 == 3 && i == 4) {
                F10_1(data, i, i2, 1, 1);
            }
            if (i2 == 3 && i == 5) {
                F10_1(data, i, i2, 1, 1);
            }
        }
    }
}
void T1(vector<vector<int>>& data) {
    vector<vector<int>> data2;
    int t = 0;
    int len = data.size();
    while (t < len) {
        vector<int> dt;
        for (int i = 0; i < len; i++) {
            dt.push_back(data[i][t]);
        }
        data2.push_back(dt);
        t++;
    }
    //F4(data2, 9);
    data = data2;
}
void T2(vector<vector<int>>& data) {
    vector<vector<int>> data2;
    int t = data.size() - 1;
    while (t >= 0) {
        vector<int> dt;
        for (int i = 0; i < data.size(); i++) {
            dt.push_back(data[i][t]);
        }
        data2.push_back(dt);
        t -= 1;
    }
    data = data2;
}
void Test(vector<vector<int>> data, int con = 1) {
    if (con == 1) {
        for (int i = 0; i < data.size(); i++) {
            int sum = 0;
            for (int i2 = 0; i2 < data.size(); i2++) {
                sum += data[i][i2];
            }
            cout << "T1 => " << sum << endl;
        }
    }
    if (con == 2) {
        int len = data.size();
        int i = 0;
        while (i < len) {
            int sum = 0;
            for (int i2 = 0; i2 < len; i2++) {
                sum += data[i][i2];
            }
            cout << "T2 => " << sum << endl;
            i += 1;
        }
    }
}
void Sydoky(vector<vector<int>>& A, int seed = time(0)) {
    srand(seed);
    vector<vector<int>> a2 = A;
    F6(a2, 3, 10);
    F1(a2[0], 6, 1);

    F7(a2);
    F8(a2, 6);
    F9(a2, 0);

    F10(a2);
    T1(a2);
    F10(a2);
    T2(a2);
    F10(a2);
    T2(a2);
    F10(a2, 1);
    F10_center(a2);
    F4(a2, 9);
    A = a2;
    
}

void S_dop(vector<vector<int>>& data, int r) {
    srand(time(0));
    while (r >= 0) {
        r -= 1;
        int x = rand() % 9;
        int y = rand() % 9;
        data[x][y] = 0;

    }


}







int main()
{
    vector<vector<int>> a3;
    Sydoky(a3);
    S_dop(a3, 60);
    F4(a3, 9);
    double time1 = (double) clock() / ((double) CLOCKS_PER_SEC);
    cout<<"Time end - "<<time1<<endl;
    cout <<endl<< "The end!\n";
}
