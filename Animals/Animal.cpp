//*********************************************************************
//
//                       Animal.cpp
//       
//        Member function and constructor implementations for 
//        the Animal class.
//
//  Author: Kevin Nguyen
//  Date: 4/13/21
//
//  Purpose: Defines functions Animal constructor and member funcitons: name, 
//  origin, diet, ear_size, classification, and print), and print.
//
//  Known bugs: None so far!
//
//  Testing performed: See written.text
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"

//
//                        Animal::Animal
//
//       This no arguments constructor is called, among other situations
//       when an array of Animals is created.
//
Animal::Animal()
{
        m_name           = "UNINITIALIZED";
        m_origin         = "UNINITIALIZED";
        m_diet           = "UNINITIALIZED";
        m_ear_size       = "UNINITIALIZED";
        m_classification = "UNINITIALIZED";
}


// -------------------------------------------------------------------------
//                          REQUIRED STUDENT CODE
//
//     Fill in the body of this constructor to initialize all
//     Animal data members from the supplied file.
// -------------------------------------------------------------------------

Animal::Animal(ifstream& input_file)
{
         input_file >> m_name >> m_origin >> m_diet >> m_ear_size
         >> m_classification;
}


// *************************************************************************
//                   Accessor functions
// *************************************************************************

string Animal::name()
{
        return m_name;
}

string Animal::origin()
{
        return m_origin;
}

string Animal::diet()
{

        return m_diet;
}

string Animal::ear_size()
{
        return m_ear_size;
}

string Animal::classification()
{
        return m_classification;
}

//
//                        Animal::print
//
//       Print all information about the animal to cout
//
//
void Animal::print()
{
        cout << "name=" << m_name 
             << " origin=" << m_origin
             << " diet=" << m_diet
             << " ear_size=" << m_ear_size
             << " classification=" << m_classification
             << endl;
}
