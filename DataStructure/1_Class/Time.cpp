#include <iostream>
using namespace std;

typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;

void SetTime(Time *t);
void PrintTime(Time t);
void IncreaseTime(Time *t);
int IsEqual(Time t1, Time t2);
int IsLessThan(Time t1, Time t2);

int main(){
    Time t1, t2;
    SetTime(&t1);
    SetTime(&t2);
    IncreaseTime(&t1);
    PrintTime(t1);
    PrintTime(t2);
    if (IsEqual(t1, t2)) {
        cout << "Equal" << endl;
    }
    else if (IsLessThan(t1, t2)) {
        cout << "t1 is less than t2" << endl;
    }
    else {
        cout << "t2 is less than t1" << endl;
    }
    return 0;
}

void SetTime (Time* t){
    cin >> t->hour >> t->minute >> t->second;
}

void PrintTime (Time t){
    cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}

void IncreaseTime (Time* t){
    if (t->second < 59) {
        t->second++;
    }
    else {
        if (t->minute < 59){
            t->minute++;
        }
        else{
            if (t->hour < 23){
                t->hour++;
            }
            else{
                t->hour = 0;
            }
            t->minute = 0;
        }
        t->second = 0;
    } 
}

int IsEqual(Time t1,Time t2){
    if (t1.hour == t2.hour && t1.minute == t2.minute && t1.second == t2.second) {
        return 1;
    }
    return 0;
}

int IsLessThan(Time t1,Time t2){
    if (t1.hour < t2.hour) {
        return 1;
    }
    else if (t1.hour == t2.hour) {
        if (t1.minute < t2.minute) {
            return 1;
        }
        else if (t1.minute == t2.minute) {
            if (t1.second < t2.second) {
                return 1;
            }
        }
    }
    return 0;
}
