//*********************************************************************
//
//                       Animal_Array_list.cpp
//       
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//
//  Author: Kevin Nguyen
//  Date: 4/13/21
//
//  Purpose: Defines functions Animal_Array_List,~Animal_Array_List, add, 
//  num_animals, animal_at, and print (descriptions of functions below)
//
//  Known bugs: animal_at function assumes index is within range. Inputting
//  anything outside of the range will most likely give a segmentation fault.
//
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"

//
// Default constructor
//
Animal_Array_List::Animal_Array_List()
{
        animals = new Animal[INITIAL_CAPACITY];
        m_num_animals = 0;
        m_capacity = INITIAL_CAPACITY;
}

//
// Destructor: Frees heap-allocated memory associated with arraylist
//
Animal_Array_List::~Animal_Array_List()
{
        delete [] animals;
}

//
// Adds a to the back of the list.
// Effects: may expand if necessary
//
void 
Animal_Array_List::add(Animal a)
{
        expand();
        animals[m_num_animals] = a;
        m_num_animals++;
}

//
// Returns the number of Animals currently stored
//
int
Animal_Array_List::num_animals()
{
        return m_num_animals;
}

//
// Returns the Animal located at position index  
// 
Animal 
Animal_Array_List::animal_at(int index)
{
        return animals[index];
}

//
// Doubles the capacity of the animals array
//
void
Animal_Array_List::expand()
{
        if (m_num_animals >= m_capacity)
        {
            Animal *new_animals = new Animal[(m_capacity * 2)];

            for (int i = 0; i < m_capacity; i++) 
            {
                    new_animals[i] = animals[i];
            }

            delete [] animals;
            animals = new_animals;
            m_capacity = m_capacity * 2;
        }
}


//
//                       print
//
//       Ask all the Animals in the list to print themselves
//
void
Animal_Array_List::print()
{
    for (int i = 0; i < m_num_animals; i++)
    {
        animals[i].print();
    }
}
