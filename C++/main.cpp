#include "BST.h"

int main()
{
  try {
      cout<<"Building a Tree"<<endl;

      BST<char,int> b0{}; //Default constructor

      b0.insertNode(pair<char,int>{'A',4});
      b0.insertNode(pair<char,int>{'B',4});
      b0.insertNode(pair<char,int>{'C',4});

      cout<<"Tree b0:"<<endl;
      cout<<b0;

      BST<int,int> b1{pair<int,int>{4,4}};

      b1.insertNode(pair<int,int>{5,5});
      b1.insertNode(pair<int,int>{3,3});
      b1.insertNode(pair<int,int>{3,2}); // Replacement of a node
      b1.insertNode(pair<int,int>{1,1});
      b1.insertNode(pair<int,int>{6,6});
      b1.insertNode(pair<int,int>{7,7});

      cout<<"Tree b1:"<<endl;
      cout<<b1;

      BST<int,int> b2{}; //Default constructor

      b2.insertNode(pair<int,int>{1,4});
      b2.insertNode(pair<int,int>{2,5});
      b2.insertNode(pair<int,int>{3,6});

      cout<<"Tree b2:"<<endl;
      cout<<b2;

      BST<int,int> b3{b2}; // Copy constructor
      cout<<"Tree b3 after copying b2 using copy constructor:"<<endl;
      cout<<b3;

      b3 = b1; // Copy assignmnet
      cout<<"Tree b3 after copy assignment of b1:"<<endl;
      cout<<b3;

      BST<int,int> b4{move(b1)}; // Move constructor
      cout<<"Tree b4 after copying b1 using move constructor:"<<endl;
      cout<<b4;

      b4 = move(b2); // Move assignment
      cout<<"Tree b4 after move assignment of b2:"<<endl;
      cout<<b4;

      cout<<"Trying to print the moved tree b1:"<<endl;
      cout<<b1;

      cout<<"Height of the tree b3 before balancing="<<b3.height(b3.head)<<endl;
      b3.balanceTree();
      cout<<"Height of the balanced b3 tree="<<b3.height(b3.head)<<endl;

      cout<<"Searching for a node in Tree b3:"<<endl;
      if(b3.findNode(3) == b3.end())
        cout<<"Not found"<<endl;
      else {
        cout<<"Found"<<endl;
        cout<<"3:"<<b3.findNode(3).value()->data.second<<endl;
      }

      // non - const [] operator
      cout<<"b3[3]:"<<b3[3]<<endl;
      cout<<"b3[5]:"<<b3[5]<<endl;
      cout<<"b3[11]:"<<b3[11]<<endl;

      // const [] operator
      const BST<int,int> b5{b3};
      cout<<"b5[3]:"<<b5[3]<<endl;
      cout<<"b5[2]:"<<b5[2]<<endl;

      b1.clearTree(b1.head);
      b2.clearTree(b2.head);
      b3.clearTree(b3.head);
      b4.clearTree(b4.head);
  }
  catch(char const* msg) {
    cout<<msg<<endl;
  }
}
