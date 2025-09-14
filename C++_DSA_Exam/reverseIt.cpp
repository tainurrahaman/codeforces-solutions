#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string nm; 
    int cls; 
    char s; 
    int id;
};
int main(){
    int n;
    cin>>n;
    Student *students = new Student[n];
    char *sections = new char[n];
    for(int i = 0; i<n; i++){
        cin>>students[i].nm>>students[i].cls>>students[i].s>>students[i].id;
        sections[i] = students[i].s;
    }
    for(int i = 0; i < n; i++){
        students[i].s = sections[n-1-i];
    }
    for(int i = 0; i<n; i++){
        cout<<students[i].nm<<" "<<students[i].cls<<" "<<students[i].s<<" "<<students[i].id<<" "<<endl;
    }
    delete[] students;
    delete[] sections;
    return 0;
}