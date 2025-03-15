#include <iostream>

using namespace std;

int Neighbors(int now[20][60], int i, int j);
void Life(int now[20][60]);
void Print(int now[20][60]);

int main(){
    int now[20][60]={0};
    int i, j;
    while (cin>> i>>j&& i!=-1&&j!=-1){
        now[i-1][j-1]=1;
    }
    int generation=0;
    cin >> generation;
    for (int i = 0; i < generation; i++) {
        Life(now);
    }
    Print(now);
    return 0;
}

int Neighbors(int now[20][60], int i, int j){
    int count=0;
    if (i > 0 && now[i-1][j] == 1) count++;
    if (i < 19 && now[i+1][j] == 1) count++;
    if (j > 0 && now[i][j-1] == 1) count++;
    if (j < 59 && now[i][j+1] == 1) count++;
    if (i > 0 && j > 0 && now[i-1][j-1] == 1) count++;
    if (i > 0 && j < 59 && now[i-1][j+1] == 1) count++;
    if (i < 19 && j > 0 && now[i+1][j-1] == 1) count++;
    if (i < 19 && j < 59 && now[i+1][j+1] == 1) count++;
    return count;
}

void Life(int now[20][60]){
    int next[20][60]={0};
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 60; j++) {
            int count = Neighbors(now, i, j);
            if (count==2) {
                next[i][j] = now[i][j];
            } else if (count==3){
                next[i][j] = 1;
            } else {
                next[i][j] = 0;
            }
        }
    }
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 60; j++) {
            now[i][j] = next[i][j];
        }
    }
}

void Print(int now[20][60]){
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 60; j++) {
            if (now[i][j] == 1) {
                cout << "*";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }
}