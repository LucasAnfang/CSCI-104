#include "alistint.h"
#include "gtest/gtest.h"

class AListTest : public testing::Test {
protected:
   AListTest(){
   
   }
   virtual ~AListTest(){
   
   }
   virtual void SetUp(){
   test.insert(0,1);
   test.insert(1,2);
   test.insert(2,3); 
   test.insert(3,4);
   
   }
   virtual void TearDown(){
   
   
   }
  
   AListInt test;
   
}; 
 
 TEST_F(AListTest, GetNominal) {
     for(int i = 0;i < test.size(); i ++)
     {
     EXPECT_EQ(test.get(i), i+1);
     EXPECT_EQ(test[i], i+1);
     EXPECT_EQ(test.size(),4);
     }      
  }  
   
  TEST_F(AListTest, Insert_Resize) {
     test.insert(0,111);
     EXPECT_EQ(test.get(0), 111);
     EXPECT_EQ(test.get(1), 1);
     EXPECT_EQ(test.size(),5);
     test.insert(2, 222);
     EXPECT_EQ(test.get(2), 222);
     EXPECT_EQ(test.get(3), 2);
     EXPECT_EQ(test.size(),6);
     test.insert(6, 333);
     EXPECT_EQ(test.get(6), 333);
     EXPECT_EQ(test.get(5), 4);
     EXPECT_EQ(test.size(),7);
  } 
  
  TEST_F(AListTest, Remove) {
     test.remove(0);
     EXPECT_EQ(test.get(0), 2);
     EXPECT_EQ(test.get(1), 3);
     EXPECT_EQ(test.size(),3);
     test.remove(1);
     EXPECT_EQ(test.get(1), 4);
     EXPECT_EQ(test.get(0), 2);
     EXPECT_EQ(test.size(),2);
     test.remove(0);
     EXPECT_EQ(test.get(0), 4);
     EXPECT_EQ(test.size(),1);
     test.remove(0);
     EXPECT_EQ(test.size(),0);
  }
  
  TEST_F(AListTest, Set) {
     test[0] = 111;
     EXPECT_EQ(test.get(0), 111);
     EXPECT_EQ(test.get(1), 2);
     EXPECT_EQ(test.size(),4);
     
     test[1] = 222;
     EXPECT_EQ(test.get(0), 111);
     EXPECT_EQ(test.get(1), 222);
     EXPECT_EQ(test.get(2), 3);
     EXPECT_EQ(test.size(),4);
     
     test[2] = 333;
     EXPECT_EQ(test.get(0), 111);
     EXPECT_EQ(test.get(1), 222);
     EXPECT_EQ(test.get(2), 333);
     EXPECT_EQ(test.get(3), 4);
     EXPECT_EQ(test.size(),4);
     
     test[3] = 444;
     EXPECT_EQ(test.get(0), 111);
     EXPECT_EQ(test.get(1), 222);
     EXPECT_EQ(test.get(2), 333);
     EXPECT_EQ(test.get(3), 444);
     EXPECT_EQ(test.size(),4);    
  }
 
  TEST_F(AListTest, Set_off) {
     EXPECT_EQ(test.get(-1), 1);
     EXPECT_EQ(test.get(50), 1);
  }
  
  TEST_F(AListTest, Addition) {
     AListInt test_other;
     test_other.insert(0,5);
     test_other.insert(1,6);
     test_other.insert(2,7); 
     test_other.insert(3,8);
     AListInt total;
     total = test + test_other;
     EXPECT_EQ(total.get(0), 1);
     EXPECT_EQ(total.get(1), 2);
     EXPECT_EQ(total.get(2), 3);
     EXPECT_EQ(total.get(3), 4);     
     EXPECT_EQ(total.get(4), 5);
     EXPECT_EQ(total.get(5), 6);
     EXPECT_EQ(total.get(6), 7);
     EXPECT_EQ(total.get(7), 8); 
     EXPECT_EQ(total.size(),8); 
  }
  
  
   TEST_F(AListTest, Equality) {
     AListInt total;
     total = test;
     EXPECT_EQ(total.get(0), 1);
     EXPECT_EQ(total.get(1), 2);
     EXPECT_EQ(total.get(2), 3);
     EXPECT_EQ(total.get(3), 4);      
     EXPECT_EQ(total.size(),4); 
  }
  
  

  

