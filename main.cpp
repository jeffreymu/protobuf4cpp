#include <iostream>
#include <vector>
#include <iterator>
#include <boost/timer.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
//#include "proto/example.pb.h"
#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"

using namespace std;

typedef vector<boost::shared_ptr<int>> vInt;

int main() {
    printf("Jeff poc application \n");
    boost::scoped_ptr<string> sp(new string("text"));
    cout << *sp << endl;
    cout << sp->size() << endl;

    vector<boost::shared_ptr<int> > v;
    v.push_back(boost::shared_ptr<int>(new int(1)));
    v.push_back(boost::shared_ptr<int>(new int(2)));
    for (auto it : v) {
        cout << *it << " ";
    }
    cout << endl;

    boost::ptr_vector<int> v1;
    v1.push_back(new int(11));
    v1.push_back(new int(22));
    cout << v1.size() << endl;
    for (auto ito : v1)
        cout << ito << endl;


//    example::Person msg;
//    msg.set_id(1234);
//    msg.set_name("John Doe");
//    msg.set_email("jdoe@example.com");

    printf("Terminal application \n");
    return 0;
}