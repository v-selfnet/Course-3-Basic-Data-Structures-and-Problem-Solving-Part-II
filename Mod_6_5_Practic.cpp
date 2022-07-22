#include<bits/stdc++.h>
using namespace std;

class Student{
private:
    string pass;

protected:
    int eng_mark; 

public:
    string name;
    char sec;
    int roll;
    
    void setPassword(string p){
        pass = p;
    }
    void setMark(int mark){
        eng_mark = mark;
    }
    string getPassword(){
        return "***";
    }
    int getMark(){
        return eng_mark;
    }
    void printData(Student st[], int n){
        cout<<endl<<"\tName"<<"\t\tSection"<<"\t\tRoll"<<"\t\tMarks"<<"\t\tPassword"<<endl<<endl;
        for(int i=0; i<n; i++){
            cout<<i+1;
            for(int j=i; j<i+1; j++){ 
                cout<<"\t"<<st[j].name
                <<"\t\t"<<st[j].sec
                <<"\t\t"<<st[j].roll
                <<"\t\t"<<st[j].getMark()
                <<"\t\t"<<st[j].getPassword()
                <<endl; 
            }
            cout<<endl;
        }
    }
    void updateMark(string p, int up_mark){
        if(pass == p){
            setMark(up_mark);
        }
        else{
            cout<<"Password did'nt match";
        }     
    }
};

int main(){

    int n;
    cin>>n;
    Student st[n];
    //name, sec, roll, mark, pass
    for(int i=0; i<n; i++){
        string pass;
        int mark;
        cin>>st[i].name>>st[i].sec>>st[i].roll
        >>mark>>pass;
        st[i].setMark(mark);
        st[i].setPassword(pass);
    }
    st[n].printData(st, n);
 
    /* Searching ..... */
    int roll;
    int mark;
    string pass;
    cout<<"For update the mark"<<endl<<"Please enter the Roll, Mark & Password: ";
    cin>>roll>>mark>>pass;
    bool found = false;
    for(int i=0; i<n; i++){
        if(st[i].roll == roll){
            found = true;
            st[i].updateMark(pass, mark);
            st[i].printData(st, n);
        }
    }
    if(!found){
        cout<<"Student not found";
        return 0;
    }
    return 0;
}