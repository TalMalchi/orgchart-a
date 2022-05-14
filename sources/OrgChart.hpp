#include <iostream>
using namespace std;
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

namespace ariel
{
    

    class OrgChart
    {

    public:

        class Iterator;
        
        OrgChart() :root(nullptr){};
        ~OrgChart(){delete root;}

        friend ostream &operator<<(ostream &os, const OrgChart &org);
        OrgChart &add_root(const string &name);                       // add a root to the org chart, if there is a root already, he will be replaced
        OrgChart &add_sub(const string &parent, const string &child); // child is under parent in the org chart. if parent not in the org chart, it will be added, throws an exception if child already in the org chart

        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

    private:
        struct Node
        {
            string data;
            Node *parent;
            vector<Node> *children;

            Node(const string &v, Node *n, vector<Node> *children)
                : data(v), parent(n), children(children) {}
        };

       Node *root;

        // find if a node in the OrgChart
        Node *find_node(const string &name);

        //--------------Inner Class---------------

        enum iterator_type
    {
        level,
        reverse,
        preorder
    };
    public:
        class Iterator
        {
            // friend class OrgChart;

        private:
            Node *root;
            iterator_type it_type;

        public:
           //Iterator(Node* p=nullptr) : pointer_to_current_node(p) {}
            Iterator(Node* p ,iterator_type type) : root(p), it_type(type) {};
            ////prefix- the value increase and then returns
            Iterator &operator++(){
                root = root->parent;
                return *this;
  
        }
        // //postfix -the value return and then increase  
            Iterator operator++(int){
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            //equality operator
            bool operator==(const Iterator &other) const{
                return root == other.root;
            }
            bool operator!=(const Iterator &other) const{
                return !(*this == other);
            }
            //acssess to the current node
            string  &operator*(){
                return root->data;
            }
            //access to the value of the current node//
            string *operator->(){
                return &root->data;
            }
        };
    };

};
