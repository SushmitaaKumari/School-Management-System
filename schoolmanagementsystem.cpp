#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

class Student{
private:
    int rollno,age;
    string name;
    int a;
public:
    Student(int stdRollno, string stdName, int stdAge){
        rollno = stdRollno;
        name = stdName;
        age = stdAge;
    }
    void setRollno(int stdRollno){
        rollno = stdRollno;
    }

    int getRollno(){
        return rollno;
    }

    void setName(string stdName){
        name = stdName;
    }

    string getName(){
        return name;
    }

    void setAge(int stdAge){
        age = stdAge;
    }

    int getAge(){
        return age;
    }

    void displayStudent(){
        cout<<"\n\n Roll no:"<<rollno<<endl;
        cout<<" Name:"<<name<<endl;
        cout<<" Age:"<<age<<endl;
    }
};

void DisplayAllStudent(vector<Student>& students){

    system("cls");
    cout<<"\n\n\t\t\t\t *** DISPLAY STUDENT *** "<<endl;
    if(students.empty()){
        cout<<"\t\t No Student Found "<<endl;
        return;
    }
    for(int i=0; i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }

}

void addNewStudent(vector<Student> &students){

    system("cls");
    cout<<"\n\n\t\t\t\t *** ADD NEW STUDENT ***"<<endl;

    int rollno,age;
    string name;
    cout<<"\n\n Enter Rollno :";
    cin>>rollno;

    for(int i=0; i<students.size(); i++){
        if(students[i].getRollno()==rollno){
            cout<<"Student already exists"<<endl;
            return;
        }
    }
    cout<<"\n\n Enter Name :";
    cin.ignore();
    getline(cin,name);

    cout<<"\n\n Enter Age :";
    cin>>age;

    Student newStudent(rollno,name, age);
    students.push_back(newStudent);

    cout<<"\n\n \t\t *** Student added successfully *** "<<endl;
    return;

}

void searchStudent(vector<Student>& students){

    system("cls");
    cout<<"\n\n\t\t\t *** SEARCH STUDENT *** "<<endl;
    int rollno;
    cout<<"\n\n Enter Rollno:";
    cin>>rollno;


    for(int i=0;i<students.size();i++){
        if(students[i].getRollno()== rollno){
            cout<<"\n\n \t\t-------Student Found-------"<<endl;
            students[i].displayStudent();
            return;
        }
    }
}


    int c,p,ch,m,e,total,avg,per;

    void calculateAvgScore(){

    cout<<"\n\n\t\t\t\t *** Calculate Average Score *** "<<endl;

    cout<<"\n\n Enter the marks of Computer:";
    cin>>c;
    cout<<"\n\n Enter the marks of Physics:";
    cin>>p;
    cout<<"\n\n Enter the marks of Chemistry:";
    cin>>ch;
    cout<<"\n\n Enter the marks of Maths:";
    cin>>m;
    cout<<"\n\n Enter the marks of English:";
    cin>>e;

    total = c+p+ch+m+e;
    cout<<"\n\n Total marks:"<<total<<endl;
    avg = total/5.0;
    per = (total*100)/500;

    cout<<"\n\n Average:"<<avg<<endl;
    cout<<"\n\n Percentage:"<<per<<"%"<<endl;

    }

    char grade;
    void Grades() {

    system("cls");
    cout<<"\n\n\t\t\t\t *** Show grade *** "<<endl;

    if(per>=80 && per<=100)
    cout<<"\n\n Grade A"<<endl;
    else if(per>=70 && per<80)
    cout<<"\n\n Grade B"<<endl;
    else if(per>=60 && per<70)
    cout<<"\n\n Grade C"<<endl;
    else if(per>=50 && per<60)
    cout<<"\n\n Grade D"<<endl;
    else if(per>=33 && per<50)
    cout<<"\n\n Grade E"<<endl;

    }


int main(){

    vector<Student> students;
    

    p:
    int choice;

    cout<<"\n\n\t\t---------------------------------------"<<endl;
    cout<<"\t\t School Management System"<<endl;
    cout<<"\t\t---------------------------------------"<<endl;
    cout<<"\t\t 1. Add New Student"<<endl;
    cout<<"\t\t 2. Display All Students"<<endl;
    cout<<"\t\t 3. Search Student"<<endl;
    cout<<"\t\t 4. Calculate Average Score"<<endl;
    cout<<"\t\t 5. Assign Grades"<<endl;
    cout<<"\t\t 6. Exit"<<endl;

    cout<<"\n\n \t\t Enter your choice : ";
    cin>>choice;

    switch(choice){
    case 1:
        addNewStudent(students);
        break;

    case 2:
        DisplayAllStudent(students);
        break;

    case 3:
        searchStudent(students);
        break;

    case 4:
        calculateAvgScore();
        break;

    case 5:
        Grades();
        break;

    case 6:
        cout<<"\n Exiting School Management System.Thankyou!"<<endl;

    default:
        cout<<"\n\n *** Invalid Choice ***";
    }
    getch();
    goto p;


    return 0;

}


