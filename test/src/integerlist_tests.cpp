#include <IntegerList.h>
#include "gtest/gtest.h"

class IntegerListTest : public ::testing::Test {

protected:
  
  IntegerList *listavazia = NULL;
  IntegerList *listacomumelemento = NULL;
  IntegerList *a_node = NULL;

  virtual void CriaListaComUmElemento(){
     listacomumelemento = NULL;
     insertElement(&listacomumelemento, 50);
  };

  virtual void SetUp() {
     a_node = createElement(10);
     CriaListaComUmElemento();
  };

  virtual void TearDown() {
  };

};


TEST_F(IntegerListTest, ListIsEmpty) {
  EXPECT_TRUE(isEmpty(listavazia));
}

TEST_F(IntegerListTest, SizeEmptyList) {
  EXPECT_EQ(size(listavazia),0);
}

TEST_F(IntegerListTest, SizeOneElementList) {
  CriaListaComUmElemento();
  EXPECT_EQ(size(listacomumelemento),1);
}

TEST_F(IntegerListTest, InsertFirstEmptySize) {
  IntegerList *lista = NULL;
  insertElement(&lista, 99);
  EXPECT_EQ(size(lista), 1);
}

TEST_F(IntegerListTest, InsertFirstEmptySearch) {
  IntegerList *lista = NULL;
  insertElement(&lista, 99);
  EXPECT_EQ(search(lista, 99), 1);
}

TEST_F(IntegerListTest, InsertNonEmptySize) {
  CriaListaComUmElemento();
  insertElement(&listacomumelemento, 200);
  EXPECT_EQ(size(listacomumelemento), 2);
}

TEST_F(IntegerListTest, InsertNonEmptySearch) {
  CriaListaComUmElemento();
  insertElement(&listacomumelemento, 200);
  EXPECT_EQ(search(listacomumelemento,200), 2);
}

TEST_F(IntegerListTest, RemoveFromEmptyList) {
  IntegerList *lista = NULL;
  int status = removeElement(&lista, 1);
  EXPECT_EQ(status, 0);
}

TEST_F(IntegerListTest, RemoveFromOneElementList) {
  IntegerList *lista = NULL;
  insertElement(&lista, 99);
  // EXPECT_EQ(search(lista, 99), 1);
  int status = removeElement(&lista, 1);
  EXPECT_EQ(search(lista, 99), 0);
  EXPECT_EQ(status, 1);
}

TEST_F(IntegerListTest, RemoveFromList) {
  IntegerList *lista = NULL;
  insertElement(&lista, 99);
  insertElement(&lista, 200);
  // EXPECT_EQ(search(lista, 200), 1);
  int status = removeElement(&lista, 2);
  EXPECT_EQ(search(lista, 200), 0);
  EXPECT_EQ(status, 1);
}


