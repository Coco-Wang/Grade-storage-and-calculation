#include "grade.h"
using namespace std;

student::student()
{
        strcpy(lastname, " ");
        strcpy(firstname, " ");
        strcpy(major, " ");
}

student::student(char* lname, char* fname, char* mj)
{
        strcpy(lastname, lname);
        strcpy(firstname, fname);
        strcpy(major, mj);
}

char student::grade_calcu(double f)
{
        if (f > 100)
        {
                cout << "invalid grade";
                return 'i';
        }
        else if (f >= 90&& f<100)
                return 'A';
        else if (f >= 80 && f < 90)
                return 'B';
        else if (f >= 70 && f < 80)
                return 'C';
        else if (f >= 60 && f < 70)
                return 'D';
        else
                return 'F';
}

void student::summaryprint(string outname)
{
        ofstream fout;
        string Output = outname;
        fout.open(Output.c_str(), ios::app);

        fout << left << firstname << " " << lastname;
        int f = strlen(firstname) + strlen(lastname);
        for (int i = f; i < 29; i++)
                fout << " ";
}

biology::biology()
{
        strcpy(labgrade," ");
        strcpy(first_test," ");
        strcpy(second_test," ");
        strcpy(third_test," ");
        strcpy(final_exam," ");
}

biology::biology(char* lname, char* fname, char* mj, char* lab, char* first, char* second, char* third, char* final):student(lname, fname, mj)
{

        strcpy(labgrade, lab);
        strcpy(first_test, first);
        strcpy(second_test, second);
        strcpy(third_test, third);
        strcpy(final_exam ,final);
}

double biology::finalavg()
{
        double weighted;
        weighted = atoi(labgrade)*0.30 + atoi(first_test)*0.15 + atoi(second_test)*0.15 + atoi(third_test)*0.15 + atoi(final_exam)*0.25;
        return weighted;
}
void biology::summaryprint(string outname)
{
        student::summaryprint(outname);
        ofstream fout;
        string Output = outname;
        fout.open(Output.c_str(), ios::app);

        fout << setw(10)<<left<<final_exam;
        int oldprecision = fout.precision();
        fout << setw(10) << left << fixed<<showpoint<<setprecision(2)<<finalavg();
        fout.precision(oldprecision);
        fout << setw(10) << left << grade_calcu(finalavg());
        fout << "\n";
}
char* student::getmajor()
{
        return major;
}

char biology::calcu_grade()
{
        char b = grade_calcu(finalavg());
        return b ;
}
computerscience::computerscience()
{
    strcpy(first , " ");
        strcpy(second ," ");
        strcpy(third , " ");
        strcpy(fourth , " ");
        strcpy(fifth , " ");
        strcpy(sixth , " ");
        strcpy(test1 , " ");
        strcpy(test2 , " ");
        strcpy(finalexam , " ");
}

computerscience::computerscience(char* lname, char* fname, char*  mj, char*  P1, char*  P2, char*  P3, char*  P4, char*  P5, char*  P6, char*  t1, char*  t2, char*  fexam) :
                                  student(lname,fname,mj)
{
                strcpy(first, P1);
                strcpy(second, P2);
                strcpy(third, P3);
                strcpy(fourth, P4);
                strcpy(fifth, P5);
                strcpy(sixth, P6);
                strcpy(test1, t1);
                strcpy(test2, t2);
                strcpy(finalexam, fexam);

}

double computerscience::paverage_cal()
{
        double pro_avg;
        pro_avg = (atoi(first) + atoi(second) + atoi(third) + atoi(fourth) + atoi(fifth) + atoi(sixth)) /6.0;
        return pro_avg;
}

double computerscience::finalavg()
{
        double pro = paverage_cal();
    double ft;
        ft = pro*0.30 + atoi(test1)*0.20 + atoi(test2)*0.20 + atoi(finalexam)*0.30;
        return ft;
}

void computerscience::summaryprint(string outname)
{
        student::summaryprint(outname);
        ofstream fout;
        string Output = outname;
        fout.open(Output.c_str(), ios::app);

        fout << setw(10) << left << finalexam;
        int oldprecision = fout.precision();
        fout << setw(10) << left << fixed << showpoint<<setprecision(2) << finalavg();
        fout.precision(oldprecision);
        fout << setw(10) << left << grade_calcu(finalavg());
        fout << "\n";
}

char computerscience::calcu_grade()
{
        return grade_calcu(finalavg());
}
theater::theater()
{
    strcpy(participation," ");
        strcpy(midterm," ");
        strcpy(finalexam," ");
}
theater::theater(char* lname, char* fname, char* mj, char* ptcp, char* mdtm, char* final) :student(lname,fname,mj)
{
        strcpy(participation,ptcp);
        strcpy(midterm , mdtm);
        strcpy(finalexam , final);
}

double theater::finalavg()
{
        double fs;
        fs = atoi(participation)*0.40 + atoi(midterm)*0.25 + atoi(finalexam)*0.35;
        return fs;
}

void theater::summaryprint(string outname)
{
        student::summaryprint(outname);
        ofstream fout;             
        string Output = outname;
        fout.open(Output.c_str(), ios::app);

        fout << setw(10) << left << finalexam;
        int oldprecision = fout.precision();
        fout << setw(10) << left << fixed << showpoint << setprecision(2) << finalavg();
        fout.precision(oldprecision);
        fout << setw(10) << left << grade_calcu(finalavg());
        fout << "\n";
}

char theater::calcu_grade()
{
        return grade_calcu(finalavg());
}

