#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string nm; 
    int cls,id; 
    char s; 
    float math_marks, eng_marks;
};
bool cmp(Student a, Student b){
    int a_total = a.math_marks + a.eng_marks;
    int b_total = b.math_marks + b.eng_marks;
    if((a_total)==(b_total)){
        return a.id < b.id;
    }else{
        return a_total > b_total;
    }
}
int main(){
    int n;
    cin>>n;
    Student *students = new Student[n];
    
    for(int i = 0; i < n; i++){
        cin>>students[i].nm>>students[i].cls>>students[i].s>>students[i].id>>students[i].math_marks>>students[i].eng_marks;
    }
    sort(students, students+n,cmp);
    for(int i = 0; i < n; i++){
        cout<<students[i].nm<<" "<<students[i].cls<<" "<<students[i].s<<" "<<students[i].id<<" "<<students[i].math_marks<<" "<<students[i].eng_marks<<" "<<endl;
    }
    return 0;
}