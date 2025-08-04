#include<iostream>
#include<list>
using namespace std;

int main()
{
    list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20); // push the element at last
    mylist.push_front(30);// push the element at first
    mylist.push_back(40); // push the element at last
    
    cout<<"Before dropping out the element from beginning"<<endl;
    for(list<int> ::iterator it = mylist.begin(); it!= mylist.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
     
    mylist.erase(mylist.begin()); // to erase the list from beginning
    
    // Insert element '15' at 3rd position from begining
    auto a = mylist.begin();
    advance(a, 2);  // Move iterator to 2nd position
    mylist.insert(a, 15);  // Insert 15 before position 2
    
    int n = 2; // Insert before 2nd node from the end
    auto b = mylist.end(); // Points after last element
    advance(b, -n); // Move backward n positions
    mylist.insert(b, 999); // Insert 999 before that node
    
    for(list<int> ::iterator it = mylist.begin(); it!= mylist.end(); it++)
    {
        cout<<*it<<" ";
    }cout<<endl;
}

/**Example  List Container */
#include <iostream>
#include<list>
using namespace std;

void displayRatings(const list<int>& playersRatings) 
{
    for (list<int>::const_iterator it = playersRatings.begin(); it != playersRatings.end(); it++) 
    {
        cout << "Player rating: " << *it << endl;
    }
}

void insertPlayerIntoOrderedList(int newPlayerRating, list<int>& playersByRating) {
    for (list<int>::iterator it = playersByRating.begin(); it != playersByRating.end(); it++) {
        if (*it > newPlayerRating) {
            playersByRating.insert(it, newPlayerRating);
            return;
        }
    }
    playersByRating.push_back(newPlayerRating);
}

int main()
{
    list<int> allPlayers = {2,9,6,7,3,1,4,8,3,2,9};

    list<int> beginners; //rating 1-5
    list<int> pros;//rating 6-10

    for (list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++) {
        int rating = *it;
        if (rating >= 1 && rating <= 5)
            insertPlayerIntoOrderedList(rating, beginners);
        else if (rating >= 6 && rating <= 10)
            insertPlayerIntoOrderedList(rating, pros);
    }
    
    cout << "Beginners:" << endl;
    displayRatings(beginners);
    cout << "Pros:" << endl;
    displayRatings(pros);

    cin.get();
}