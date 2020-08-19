// Code for Project 1
// Fake news results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
  int postsReviewed;
  int fakePosts;
  int realPosts;

  cout << "How many internet posts were reviewed? ";
  cin >> postsReviewed;
  cout << "How many of these posts were fake news items? ";
  cin >> fakePosts;
  cout << "How many of these posts were real news items? ";
  cin >> realPosts;

  double pctFake = 100.0 * fakePosts / postsReviewed;
  double pctReal = 100.0 * realPosts / postsReviewed;

  cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
  cout.precision(1);

  cout << endl;
  cout << pctFake << "% were fake." << endl;
  cout << pctReal << "% were real." << endl;

  if (pctFake > pctReal)
     cout << "It was more fake than real." << endl;
  else
     cout << "It was more real than fake." << endl;
  return( 0 );
}