#include <iostream>
using namespace std;
#include "OrgChart.hpp"

namespace ariel{
    ostream &operator<<(ostream &os, const OrgChart &org){return os;}
    OrgChart &OrgChart::add_root(const string &name){return  *this;}                       // add a root to the org chart, if there is a root already, he will be replaced
    OrgChart &OrgChart::add_sub(const string &parent, const string &child){return *this;} // child is under parent in the org chart. if parent not in the org chart, it will be added, throws an exception if child already in the org chart

    OrgChart::Iterator OrgChart::begin_level_order(){return Iterator(root,level);}
    OrgChart::Iterator OrgChart::end_level_order(){return Iterator(nullptr,level);}
    OrgChart::Iterator OrgChart::begin_reverse_order(){return Iterator(root, reverse);}
    OrgChart::Iterator OrgChart::reverse_order(){return Iterator(nullptr,reverse);}
    OrgChart::Iterator OrgChart::begin_preorder(){return Iterator(root,preorder);}  
    OrgChart::Iterator OrgChart::end_preorder(){return Iterator(nullptr,preorder);}//
}