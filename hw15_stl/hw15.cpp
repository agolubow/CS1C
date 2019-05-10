// hw15.cpp
// to illustrate stl containers & iterators

/*************************************************************************
 * AUTHOR     : Alexander Golubow
 * HW15       : stl containers & iterators
 * CLASS      : CS 1C
 * SECTION    : tuesday-thursday 3:00pm-5:30pm
 *************************************************************************/

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

// function & class definitions go into hw15.cpp:

// hw15.cpp

namespace hw15 {
    
    //
    // list conainter, iterator example code adapted from Chapter 20.4
    // "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
    //
    
    //------------------------------------------------------------------------------
    
    template<typename Elem>
    struct Link
    {
        Link* prev;    // previous link
        Link* succ;    // successor (next) link
        Elem  val;     // the value
        Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : prev{p}, succ{s} ,val{v} { }
    };
    
    //--Q#3-------------------------------------------------------------------------
    
    template<typename Elem>
    class list
    {
        // representation and implementation details
    public:
        class iterator;         // forward declaration of member type: class iterator
        class const_iterator;   // forward declaration of member type: class const_iterator
        
        list() : first(new Link<Elem>()), last{first} { }
        ~list()
        {
            while (first != last)
            {
                Link<Elem> *next = first->succ;
                delete first;
                first = next;
            }
            delete last;
        }
        
        iterator begin();   // iterator to first element
        iterator end();     // iterator to one beyond last element
        
        
        // add missing const iterators begin, end here
        
        const_iterator begin() const; // constant iterator to first element
        const_iterator end() const;   // constant iterator to last element + 1
        
        iterator insert(iterator p, const Elem& v); // insert v into list after p
        iterator erase(iterator p);                 // remove p from the list
        
        void push_back(const Elem& v);  // insert v at end
        void push_front(const Elem& v); // insert v at front
        void pop_front();   // remove the first element
        void pop_back();    // remove the last element
        
        Elem& front();      // the first element
        Elem& back();       // the last element
        
        Link<Elem>* first;
        Link<Elem>* last;   // one-beyond-the-last link
    };
    
    //--Q#4-------------------------------------------------------------------------
    
    template<typename Elem>
    class list<Elem>::iterator // definition for class iterator
    {
        Link<Elem>* curr;   // current node
    public:
        iterator(Link<Elem>* p) : curr{p} { }
        iterator& operator++(){
            curr = curr->succ;
            return *this;            
        } // forward

        iterator& operator--() // backwards
        {
            curr = curr->prev;
            return *this;
        }
        Elem& operator*() // get value (dereference)
        {
            return curr->val;
        }
        
        bool operator==(const iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
        {
            return (curr == rhs.curr);
        }

        bool operator!=(const iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
        {
            return (curr != rhs.curr);   
        }
    };
    
    //--Q#4-------------------------------------------------------------------------
    
    template<typename Elem>
    class list<Elem>::const_iterator // definition for class const_iterator
    {
        const Link<Elem>* curr;   // current node
        // node pointed to by curr is immutable (i.e. can't be changed)
        // fine to modify curr pointer itself (i.e. pointer value stored in curr)
        // refer to const correctness reading
    public:
        // add missing constructor, overloaded ++, --, *, ==, != operators here
        const_iterator(const Link<Elem>* p): curr(p) {};
        const_iterator& operator++() const {
        	curr = curr->next; 
        	return this;
        }
        const_iterator& operator--() const {
        	curr = curr->prev; 
        	return this;
        }
        const Elem& operator*() const {
        	return curr->val;
        }
        bool operator==(const const_iterator& rhs) const {
        	return (curr == rhs.curr);
        }
        bool operator!=(const const_iterator& rhs) const {
        	return (curr != rhs.curr);
        }
        
    };
    
    //------------------------------------------------------------------------------
    
    template<typename Elem>
    typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
    {
        return iterator(first);
    }
    
    //--Q#3-------------------------------------------------------------------------
    
    // constant iterator to first element
    template<typename Elem>
    typename list<Elem>::const_iterator list<Elem>::begin()const
    {
        return const_iterator(first);
    }

    //------------------------------------------------------------------------------
    
    template<typename Elem>
    typename list<Elem>::iterator list<Elem>::end() // iterator to one beyond last element
    {
        return iterator(last);
    }
    
    //--Q#3-------------------------------------------------------------------------
    
    // constant iterator to last element
    template<typename Elem>
    typename list<Elem>::const_iterator list<Elem>::end() const
    {
        return const_iterator(last);
    }
     
    //------------------------------------------------------------------------------
    
    template<typename Elem>
    void list<Elem>::push_front(const Elem& v) // insert v at front
    {
        first = new Link<Elem>(v,0,first);
    }
    
    //
    // low algorithms adapted from Chapter 20.1, 20.4
    // "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
    //
    
    //--Q#5-------------------------------------------------------------------------
    
    double* low_doubles(double* first, double* last)
    // return a pointer to the element in [first,last) that has the lowest value
    {
        double l = -1;
        double* low;
        for(double* p = first; p!=last; ++p)
            if (*p < l) { low = p; l = *p; }
        return low;
    }
    
    //--Q#5-------------------------------------------------------------------------
    
    // implement templated low algorithm here
    template<typename Type>
    Type low(Type first, Type last)
    {
	    for(Type i = first; i != last; ++i)
	        if(*i < *first){
	        	first = i;
	       	}
	    return first;
    }
    
    //------------------------------------------------------------------------------
    
} // hw15

//------------------------------------------------------------------------------

using namespace hw15;

//
// list conainter, iterator example code adapted from Chapter 20.4
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int main()
{
    // console header
    cout << endl;
    cout << "************************************** " << endl;
    cout << "*           Running HW15             * " << endl;
    cout << "*   Programmed by Alexander Golubow  * " << endl;
    cout << "*   Tuesday-Thursday 3:00pm-5:30pm   * " << endl;
    cout << "************************************** " << endl;
    cout << endl;
    
    // Q#3,4 - containters & iterators
    
    list<int> myList;
    int x;
    while (cin >> x){
    	myList.push_front(x);
    }
    cin.clear();
    cin.ignore(1000,'\n');
    // Q#5 - low_doubles algorithm
    
    double d[] = {1,2,3,4,5,-99.25,100,10,500.123,5};       // init array of doubles
    vector<double> v = {1,2,3,4,5,-99.25,100,10,500.123,5}; // init identical vector of doubles
    
    double* lowa = low_doubles(&d[0], &d[9]); // min of array
    cout << endl << "low_doubles alg: double array min value is " << *lowa << endl << endl;
    
    double* middle = &v[0] + v.size()/2;
    double* lowv1 = low_doubles(&v[0], middle);          // min of vector first half
    double* lowv2 = low_doubles(middle, &v[0]+v.size()); // min of vector second half
    cout << "low_doubles alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low_doubles alg: double vector min value second half is " << *lowv2 << endl << endl;
    
    // Q#5 - low algorithm
    
    // NOTE: uncomment code below once low algorithm definition is complete
    
    lowa = low(&d[0], &d[9]); // min of array
    cout << "low alg: double array min value is " << *lowa << endl << endl;
    
    lowv1 = low(&v[0], middle);          // min of vector first half
    lowv2 = low(middle, &v[0]+v.size()); // min of vector second half
    cout << "low alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low alg: double vector min value second half is " << *lowv2 << endl << endl;
    
    list<int>::iterator p = low(myList.begin(), myList.end()); // min of list
    if (p==myList.end())    // did we reach the end?
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << endl;
    
    
    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS


/* ----Q#1----
 	A STL container is a templated object that stores a collection of data
 	of a specific type. The STL containers manage storage and provide methods to
 	access and iterate through the data they hold. Some common STL containers are 
 	vector,stack, queue and list.

 	A STL iterator is a templated object that allows for easy iteration through the
 	contents of a container, regardless of type. Some examples are forward iterators,
 	Bidirectional iterators and random-access iterators.

 	A STL algorithm defines a collection of functions designed to be used on a wide
 	range of elements that can be accessed through iterators or pointers. the STL
 	Algorithms operate directly through iterators, which are decoupled from the containers, 
 	operating on the data directly and making them easy to use with any data type.
*/

/* ----Q#2----
	Iterator architecture makes it possible to decouple algorithms from containers because
	iterators do not depend on the container, rather they are a well defined interface for 
	working with any container. This is important because it allows for the programmer to 
	focus more on important parts of code, as well as not worrying about the underlying data
	types. It allows a great amount of flexibility between using the provided algorithms on
	a collection of any data type. It also allows the use of the algorithms in the STL, which
	are highly optimized for each compiler.
*/

/* ----Q#5----
	Some issues may arrise from the local variables in Low doubles due to the dereferencing
	of pointers and comparisons between dereferenced pointers and normal variables. Low and low_doubles
	are similar in the fact that their for loop structure is nearly identical, and they are supposed 
	to perform the same task. they differ in the fact that Low is a lot more flexible than low_doubles, 
	has less room for error, does not use local variables and is templated which allows it to be used 
	on multiple data types. The output is different between low and low_doubles because low is returning 
	the actual lowest value, Whereas low_doubles is returning an address.
*/