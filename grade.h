#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#pragma warning(disable: 4996)
using namespace std;


class student
{
public:
        student();
        char* getmajor();
        virtual void summaryprint(string outname);
        virtual char calcu_grade()=0;
protected:
        student(char* lname, char* fname, char* mj);
        char grade_calcu( double f);
        char lastname[20];
        char firstname[20];
        char major[20];
        virtual double finalavg() = 0;

private:

};

class biology:public student
{
public:
        biology();
        biology(char* lname, char* fname, char* mj, char* lab, char* first, char* second, char* third, char* final);
        void summaryprint(string outname);
        char calcu_grade();
private:
        char labgrade[5];
        char first_test[5];
        char second_test[5];
        char third_test[5];
        char final_exam[5];
        double finalavg();
};
class computerscience :public student
{
public:
        computerscience();
        computerscience(char*  lname, char*  fname, char*  mj, char*  P1, char*  P2, char* P3, char*  P4, char* P5, char*  P6, char*  t1, char*  t2, char*  fexam);
        void summaryprint(string outname);
        char calcu_grade();

private:
        char  first[5];
        char  second[5];
        char  third[5];
        char  fourth[5];
        char  fifth[5];
        char  sixth[5];
        char  test1[5];
        char  test2[5];
        char finalexam[5];
    double paverage_cal();
        double finalavg();
};
class theater :public student
{
public:
        theater();
        theater(char* lname, char* fname, char* mj, char* ptcp, char* mdtm, char* final);
        void summaryprint(string outname);
        char calcu_grade();
private:
        char participation[5];
        char midterm[5];
        char finalexam[5];
        double finalavg();
};


