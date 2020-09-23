#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

class complex_num
{
    double real,imaginary; //private data

    public:
        complex_num()               //Constructor
        {
            this->real=0;
            this->imaginary=0;
        }
        ~complex_num()              //De-constructor
        {
            this->real=0;
            this->imaginary=0;
        }

        void print_cplx();  //Function print

        void read_cplx_num();   //Function read

        double mod();   //Get module

        complex_num operator + (complex_num a)              //Function add
        {
            complex_num result;
            result.real= this->real+a.real;
            result.imaginary= this->imaginary+a.imaginary;
            return result;
        }

        complex_num operator - (complex_num a)              //Function sub
        {
            complex_num result;
            result.real= this->real-a.real;
            result.imaginary= this->imaginary-a.imaginary;
            return result;
        }

        complex_num operator * (complex_num a)              //Function mul
        {
            complex_num result;
            result.real= this->real*a.real-this->imaginary*a.imaginary;
            result.imaginary= this->imaginary*a.real+this->real*a.imaginary;
            return result;
        }

        complex_num operator / (complex_num a)              //Function div
        {
            complex_num result;
            if (a.mod()!=0)
            {
                double k = a.mod()*a.mod(); //a2^2+b2^2
                result.real= (this->real*a.real+this->imaginary*a.imaginary)/k;
                result.imaginary= (this->imaginary*a.real-this->real*a.imaginary)/k;
                return result;
            }
            else cout << "num2 = 0, can't divide";
        }
};

void complex_num::print_cplx()
{
    if (imaginary>0) {cout<<real<<" + "<<imaginary<<"i\n";} //form a+bi
    else if (imaginary==0) {cout<<real<<"\n";}  //form a
    else {cout<<real<<" "<<imaginary<<"i\n";}   //form a-bi
}

void complex_num::read_cplx_num()
{
    cout<<"Enter real part: ";
    cin >> real;
    cout<<"Enter imaginary part: ";
    cin >> imaginary;
}

double complex_num::mod()
{
    return sqrt(real*real+imaginary*imaginary);
}

int main()
{
    cout << setprecision(3) << fixed;

    complex_num num1,num2,result;

    //read 2 complex numbers
    cout<<"enter 1st complex number: \n";
    num1.read_cplx_num();
    cout<<"enter 2nd complex number: \n";
    num2.read_cplx_num();

    //print 2 complex numbers
    cout<<"Your 1st number: ";  num1.print_cplx();
    cout<<"Your 2nd number: ";  num2.print_cplx();

    cout<<"Result is aproximate - rounded to the 3rd decimal place\n";

    //add 2 complex numbers
    cout<<"num1 + num2 = ";
    result=num1+num2;
    result.print_cplx();

    //subtraction
    cout << "num1 - num2 = ";
    result=num1-num2;
    result.print_cplx();

    //mul 2 complex numbers
    cout << "num1 * num2 = ";
    result=num1*num2;
    result.print_cplx();

    //module
    cout<< "|num1| = " << num1.mod() << "\n";
    cout<< "|num2| = " << num2.mod() << "\n";

    //divide
    cout << "num1 / num2 = ";
    result=num1/num2;
    result.print_cplx();

    return 0;
}
