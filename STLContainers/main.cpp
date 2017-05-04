#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <iostream>

int main()
{
	
	//Conteneurs de séquences
	//Les conteneurs de séquences implémentent des structures de données qui peuvent être accédées de manière séquentielle. 
		
	// C style array
	double a1[4] = {1, 2, 3, 4};
	double* p1 = a1;
	
	int a2[] = {1, 2, 3};
	
	int* p2 = new int[10];
	
	for (int i = 0 ; i < 10 ; ++i)
	{
		p2[i] = i;
	}
	
	for (int i = 0 ; i < 10 ; ++i)
		std::cout << p2[i] << std::endl;
		
	// std::array (since C++11) static contiguous array
    std::array<int, 3> a3 = {1, 2, 3};
	
	for (const auto& v : a3)
		std::cout << v << std::endl;
   
   // vector dynamic contiguous array
   std::vector<double> v1 = {7, 5, 16, 8};  
   std::vector<int> v2(12);
   
   v2.push_back(14);
   
   for (const auto& v : v2)
	   std::cout << v << std::endl;
   
   for (std::vector<int>::iterator it = v2.begin() ; it != v2.end(); ++it)
       std::cout << ' ' << *it;
   std::cout << '\n';
   
   
   // deque : double-ended queue
   std::deque<int> d = {7, 5, 16, 8};
 
   // Add an integer to the beginning and end of the deque
   d.push_front(13);
   d.push_back(25);
 
   // Iterate and print values of deque
   for(int n : d) 
   {
        std::cout << n << '\n';
   }
   
   
   // forward_list : (since C++11) 	singly-linked list




   // list
   // 	doubly-linked list
   // std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient. 
	// Create a list containing integers
    std::list<int> l = { 7, 5, 16, 8 };
 
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }
 
    // Iterate and print values of the list
    for (int n : l) {
        std::cout << n << '\n';
    }

   // Associative containers
   // Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).
	
   // set
   // 	collection of unique keys, sorted by keys
	std::set<int> s1 = {12, 12, 12, 13 ,14, 15, 15};
	
	int myints[]= {10,20,30,40,50,50};
	std::set<int> s2(myints,myints+6); 
	
	std::cout << " " << std::endl;
	
    for (const auto& v : s1)
 	   std::cout << v << std::endl;
	
	std::cout << " " << std::endl;
	
    for (const auto& v : s2)
 	   std::cout << v << std::endl;

   // map
   // 	collection of key-value pairs, sorted by keys, keys are unique
	std::map<char,int> m1;

	  m1['a']=10;
	  m1['b']=30;
	  m1['c']=50;
	  m1['d']=70;
	  
	  m1.insert(std::make_pair('e', 80));
	  
	  std::map<int, double> m2 = {{0, 12}, {5, 14}};
	  
	  std::cout << " " << std::endl;
	  std::cout << m2.at(0) << std::endl;  // prints value associated with key 1 ,i.e nikhilesh
	  std::cout << m2.at(5) << std::endl;

	  std::cout << " " << std::endl;
	 
	  for (auto it : m2)
		  std::cout << it.second << std::endl;



   // multiset : collection of keys, sorted by keys
	  std::multiset<int> ms = {10,20,30,20,20};
	  
	  std::cout << " " << std::endl;
	  for (std::multiset<int>::iterator it = ms.begin() ; it != ms.end() ; ++it)
		  std::cout << *it << std::endl;


   // multimap : collection of key-value pairs, sorted by keys
	  std::multimap<char,int> mymm;

	    mymm.insert (std::make_pair('x',10));
	    mymm.insert (std::make_pair('y',20));
	    mymm.insert (std::make_pair('z',30));
	    mymm.insert (std::make_pair('z',40));
		mymm.insert({'u', 50});
	  
  	  std::cout << "multimap" << std::endl;
  	  for (std::multimap<char, int>::iterator it = mymm.begin() ; it != mymm.end() ; ++it)
  		  std::cout << it->second << std::endl;
		

   // Unordered associative containers
   // Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) amortized, O(n) worst-case complexity).
	  
   // unordered_set
   // 	collection of unique keys, hashed by keys

   // unordered_map
   // 	collection of key-value pairs, hashed by keys, keys are unique

   // unordered_multiset
   // 	collection of keys, hashed by keys

   // unordered_multimap
   // 	collection of key-value pairs, hashed by keys
	  
	  
   // Container adaptors
   // Container adaptors provide a different interface for sequential containers.
	  
   // stack
   // 	adapts a container to provide stack (LIFO data structure)
	  std::stack<int> st1;
	  
	  st1.push(1);
	  st1.push(2);
	  st1.push(5);
	  st1.pop();
	  st1.top() = 12;
	  
	  std::cout << "stack top " << st1.top() << std::endl;

   // queue
   // 	adapts a container to provide queue (FIFO data structure)

   // priority_queue
   // 	adapts a container to provide priority queue 
	
	return EXIT_SUCCESS;
}
