#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student
{
	public:
		int id;
		string name;
    	int age;
    	string phone;
}st;

void  insert_student()
{

    fstream stud;
    stud.open("student.txt", ios::app);
    cin.ignore();
    cout<<" \n Student Name   ---> ";
    getline(cin,st.name);
	cout<<" \n Id             ---> ";
    cin>>st.id;
    cout<<" \n Phone Number ---> ";
    cin>>st.phone;
    cout<<" \n Age            ---> ";
    cin>>st.age;
     stud.write((char*)&st,sizeof(st));
    stud.close();
}


void search_student()
{
    fstream stud;
    stud.open("student.txt",ios::in);
    int x;
    int a;
    {
		    cout<<" \n Enter the ID to Search about it : ";
		    cin.ignore();
		    cin>>a;
		    x=0;
		    cout<<"\nID \t\tStudent Name \tAge \t\tPhone Number"<<endl;
		    cout<<"\n"<<endl;
		    while(!stud.eof())
		    {
		    	stud>>st.id;
		    	stud>>st.name;
		    	stud>>st.phone;
		    	stud>>st.age;
		    	if(st.id==a)
				{

					cout<<st.id<<"\t\t"<<st.name<<"\t\t"<<st.age<<"\t\t"<<st.phone<<endl;
		            x=1;

		        }
		    }
	}
	if(x==0)
    {
        cout<<"\n ---> Not Found <--- \n";
    }
    stud.close();
}


void display_all()
{
    fstream stud;
    stud.open("student.txt",ios::in);
    cout<<"ID \t\tStudent Name \tAge \t\tPhone Number"<<endl;
    cout<<"\n"<<endl;
    while(!stud.eof())
    {
    stud>>st.id;

		stud>>st.name;

		stud>> st.age;
		stud>>st.phone;

		cout<<st.id<<"\t\t"<<st.name<<"\t\t"<<st.phone<<"\t\t0"<<st.age<<endl;

    }
}



void delete_student()
{

    fstream stud;
    fstream temp;
	int a;
    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    cin.ignore();
    cout<<" \n\t Enter the ID number to delete  : ";
    cin>>a;
    while(!stud.eof())
    {
    	stud>>st.id;
		stud>>st.name;
		stud>>st.phone;
		stud>>st.age;

        if(st.id==a)
        {
            continue;
        }
        else
        {
            temp<<'\n'<<st.id<<' '<<st.name<<' '<<st.phone<<' '<<st.age;
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
    	temp>>st.id;
		temp>>st.name;
		temp>>st.phone;
		temp>>st.age;

        stud<<'\n'<<st.id<<' '<<st.name<<' '<<st.phone<<' '<<st.age;
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n ---> Done <--- \n";
}


void update_student()
{
    fstream stud;
    fstream temp;

    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    int a,q;
    cin.ignore();
    cout<<" \n\t Enter the ID number to update : ";
    cin>>a;
    while(!stud.eof())
    {
    	stud>>st.id;
		stud>>st.name;
		stud>>st.phone;
		stud>>st.age;

        if(st.id == a)
        {
        	cout<<"What is the part to updata"<<endl;
        	cout<<"\n"<<endl;
        	cout<<"-->  1  <----> ID"<<endl;
			cout<<"-->  2  <----> NAME"<<endl;
			cout<<"-->  3  <----> PHONE"<<endl;
			cout<<"-->  4  <----> AGE"<<endl;
			cout<<"\n"<<endl;
			cout<<"You Select -->";
        	cin>>q;
        	switch(q)
        	{
        		case 1:
            		cout<<" \n ID : ";
            		cin>>st.id;
            		break;

            		case 2:
            		cout<<" \n name : ";
           			cin>>st.name;
           			break;

           			case 3:
            		cout<<" \n phone : ";
            		cin>>st.phone;
            		break;

            		case 4:
            		cout<<" \n age : ";
            		cin>>st.age;
            		break;
        	}
            temp<<'\n'<<st.id<<' '<<st.name<<' '<<st.phone<<' '<<st.age;
        }
        else
        {
            temp<<'\n'<<st.id<<' '<<st.name<<' '<<st.phone<<' '<<st.age;
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
    	temp>>st.id;
        temp>>st.name;
        temp>>st.phone;
        temp>>st.age;

        stud<<'\n'<<st.id<<' '<<st.name<<' '<<st.phone<<' '<<st.age;
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n ---> Done <--- \n";
}


int main()
{
	char f;
	bool flag1=true;

    while (flag1)
    {
		bool flag2=true;
    	cout<<"\t\t\t--> Wellcome To Our Program <--"<<endl;
		cout<<"\t\t----------------------------------------------\n\n"<<endl;
		cout<<"Introduction"<<endl;
		cout<<"--------------------\n"<<endl;
		cout<<"Our Program Insert , Search , Display , Update and Delete Information of Student\n"<<endl;
		cout<<"**************************************************************************\n\n"<<endl;

		cout<<"-->  1  <----> INSERT"<<endl;
		cout<<"-->  2  <----> SEARCH"<<endl;
		cout<<"-->  3  <----> DISPLAY"<<endl;
		cout<<"-->  4  <----> UPDATA"<<endl;
		cout<<"-->  5  <----> DELETE"<<endl;
		cout<<"\n"<<endl;
		cout<<"You Select -->";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
        	cout<<"-----------------------------------------------------"<<endl;
            insert_student();
            break;
        case 2:
        	cout<<"-----------------------------------------------------"<<endl;
            search_student();
            break;
        case 3:
        	cout<<"-----------------------------------------------------"<<endl;
            display_all();
            break;
        case 4 :
        	cout<<"-----------------------------------------------------"<<endl;
            update_student();
            break;
       case 5 :
       		cout<<"-----------------------------------------------------"<<endl;
            delete_student();
            break;
        default :
            cout << " \n Select The Right Number \n";
        }
        cout<<"-----------------------------------------------------"<<endl;
        while(flag2)
        {

        	cout<<"\nContinue  -----> [Y/N] \n";
        	cout<<"You Select  --->";
	        cin>>f;
	        if(f=='n' || f=='N') 	{flag1=false; flag2=false;}
	        else if(f=='y' || f=='Y') 	{flag2=false; flag1=true;}
	        else
			{
				cout<<"---------------------------------------------------------------------------\n"<<endl;
				cout<<"<--------------Wrong Choose------------Again--------------->  \n"<<endl;
				flag2=true;
			}
	    }
    }





	return 0;
}

