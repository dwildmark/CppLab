#include <iostream>
#include <string>
#include <iostream>
#include <cassert>
#include <utility>
#include <stdlib.h>
#include "String.h"

using namespace std;

int myOwnTest();
bool tM(bool test);

void TestPushBackReallocation() {
    String str("hej");
    auto internalBuf = str.InternalRep();
    auto cap = str.capacity();
    auto siz = str.size();
    assert(siz + 1 < cap); //Meaningless to check if to little difference
    int i;
    for (i = siz + 1; i <= cap; ++i) {
        str.push_back(char(i) + 'a');
        assert(internalBuf == str.InternalRep());
        assert(cap == str.capacity());
        assert(i == str.size());
    }
    str.push_back(char(i));
    assert(internalBuf != str.InternalRep());
    assert(cap < str.capacity());
    assert(i == str.size());
}

void TestForGodkantString() {
    //-	String()
    String str0;	assert(str0 == "");

    //-	String(Str�ng str�ng)
    String s1("foo"); assert(s1 == "foo");
    String str(s1); assert(str == "foo");
    String s3("bar");  assert(s3 == "bar");

    //-	~String() Kom ih�g destruktorn!
    delete new String("hej");

    //	-	operator =(Str�ng str�ng)
    assert((str = s3) == s3);
    assert((str = str) == s3);	//self assignment


    String str1("foo"), str2("bar"), str3("hej");
    str3 = str = str1;
    assert(str3 == str);
    assert(str1 == str);

    //-	operator==
    //testas �verallt!


    //-	operator[](int i) som indexerar utan range check.
    str = "bar";
    str[-1]; str[1000];	//No error
    assert(str[1] == 'a');
    str[1] = 'y';
    assert(str[1] == 'y');

    const String sc(str);
    assert(sc[1] == 'y');
    assert(std::is_const<std::remove_reference< decltype(sc[1])>::type>::value); //Kolla att det blir en const resultat av indexering

    //-	push_back(char c) l�gger till ett tecken sist.
    str = "bar";
    str.push_back('a');
    assert(str == "bara");

    //-	size(), capacity() and reloccation test;
    TestPushBackReallocation();

    cout << String("hej\n");
    cout << "Om det står hej på föregående rad så är TestFörGodkänt klar\n";

}

void TestForValGodkantString() {
#ifdef VG
    String str("bar");

	//-	at(int i) som indexerar med range check
	try {
		str.at(-1);
		assert(false);
	}
	catch (std::out_of_range&) {};
	try {
		str.at(3);
		assert(false);
	}
	catch (std::out_of_range&) {};

	//- at indexerar

	//-	at(int i)
	str = "bar";
	assert(str.at(1) == 'a');
	str.at(1) = 'y';
	assert(str.at(1) == 'y');

	const String strC(str);
	assert(strC.at(1) == 'y');
	assert(std::is_const<std::remove_reference< decltype(strC.at(1))>::type>::value); //Kolla att det blir en const resultat av indexering


//	reserve()
	auto internalBuf = str.InternalRep();
	auto cap = str.capacity();
	auto siz = str.size();

	str.reserve(cap);
	assert(internalBuf == str.InternalRep());
	assert(cap == str.capacity());
	assert(siz == str.size());

	str.reserve(cap+1);
	assert(internalBuf != str.InternalRep());
	assert(cap+1 == str.capacity());
	assert(siz == str.size());

	/////////////////
	//-	operator+=(Str�ng str�ng) som tolkas som konkatenering.
	//foo, bar, hej
	String str1("foo"), str2("bar"), str3("hej");
	((str="xyz")  += str1) += (str3 += str1);
	assert(str3 == "hejfoo" && str == "xyzfoohejfoo" && str1 == "foo");

	//+= som f�r plats;
	str = "bar"; str.reserve(10);
	str += "foo";
	assert(str == "barfoo");

	//+= som inte f�r plats;
	str.reserve(10);
	str = "";
	int i;
	for (i = 0; str.size() < str.capacity(); ++i)
		str.push_back('0' + i);
	str1 = "bar";
	str += str1;
	for (int k=0;k<i;++k)
		assert(str[k] == '0'+k);
	assert(str[i] == 'b');
	//+= Sj�lv assignment	//Borde testa med att capacity tar slut!
	str = "foo";
	str += str;
	assert(str == "foofoo");

	//-	operator+
	str = "bar";
	assert(str + "foo" == "barfoo");

	cout << "\nTestFörVälGodkänt klar\n";
#endif //VG
}

#define FULL_TEST 1
int main() {
//    locale::global(locale("swedish"));
    //TestUnsigned();
#if FULL_TEST
    TestForGodkantString();
    TestForGodkantString();
    cin.get();
#else
    myOwnTest();
#endif
}

int myOwnTest() {
    String str = String("Hej");
    String str2 = String("Hej");
    bool test1 = str == str2;
    tM(test1);
    String str3 = str2;
    bool test2 = str3 == "Hej";
    tM(test2);
    str3.push_back('e');
    bool test3 = str3 == "Heje";
    tM(test3);
}

bool tM(bool test) {
    if(test) {
        cout << "Japp" << endl;
    } else{
        cout << "Nope" << endl;
    }
}