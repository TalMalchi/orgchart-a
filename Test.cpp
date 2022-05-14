#include <iostream>
using namespace std;
#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;





TEST_CASE("init Org_Chart") {
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_root("TAL"));
    CHECK_NOTHROW(org.add_sub("TAL", "AMIT"));
    CHECK_THROWS(org.add_sub("NETA", "YUVAL")); 
    CHECK_THROWS(org.add_sub("LINOY", "YUVAL"));
    CHECK_NOTHROW(org.add_root("NETA"));
    CHECK_NOTHROW(org.add_sub("NETA", "LINOY"));

    
}


TEST_CASE("Check Bad input"){

    OrgChart check;
    CHECK_NOTHROW(check.add_root("root"));
    CHECK_NOTHROW(check.add_sub("root","child"));
    CHECK_NOTHROW(check.add_sub("root","child2"));
    CHECK_NOTHROW(check.add_sub("root","child3"));
    CHECK_THROWS(check.add_sub("NOT_GOOD","child")); //parent not in the OrgChart
    CHECK_NOTHROW(check.add_root("root2"));
    CHECK_THROWS(check.add_sub("root2","child")); //child already in the OrgChart
    CHECK_THROWS(check.add_sub("root","child")); //child already in the OrgChart



}

TEST_CASE("Check iterator"){
    OrgChart org;
    CHECK_NOTHROW(org.add_root("TAL"));
    CHECK_NOTHROW(org.add_sub("TAL", "AMIT"));
    CHECK_NOTHROW(org.add_sub("TAL", "NETA"));
    CHECK_NOTHROW(org.add_sub("TAL", "LINOY"));
    //check the iteartor for level order//
    vector<string> level_order= {"TAL","AMIT","NETA","LINOY"};
    unsigned long i =0;
    for(auto it=org.begin_level_order();it!=org.end_level_order();++it){
        //equals iterator data to the vector
        CHECK_EQ(*it,level_order.at(i));
        i++;  
        
    }
    //check the iterator for reverse order
    vector<string> reverse_order= {"AMIT","NETA","LINOY","TAL"};
    unsigned long  x=0;
    for(auto it=org.begin_reverse_order();it!=org.reverse_order();++it){
        CHECK_EQ(*it,reverse_order.at(x));
        x++;
        
    }
    //check preorder
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
    vector<string> preorder= {"CEO","CTO","VP_SW","CFO","COO","VP_BI"};
    unsigned long j=0;
    for(auto it=organization.begin_preorder();it!=organization.end_preorder();++it){
        CHECK_EQ(*it,preorder.at(j));
        j++;
    }
    





}