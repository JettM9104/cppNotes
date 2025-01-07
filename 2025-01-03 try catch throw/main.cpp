#include <iostream>

using namespace std;

class new_exception : public exception {
virtual const char* what() const noexcept {
  return "my exception"; // what e.what will reurn
}
};
int main() {
  string x = "this is a string";

  try { // Code in here will run normally unless there is an exception
    //cout << x.at(20); // This is purpously made so the index is out of range
    //throw new_exception(); // with regular exceptions, the text inside the parentheses are what e.what() returns.
    throw 20; // throwing is not limited to exceptions, you can throw values
    // even if throw statements are in functinos, it will "store" it until the next catch statemetn
  }
  catch (out_of_range& e) { 
    // out_of_range specifies the error type and it creates a refrence named e
    cout << "if this is printing this indicates\nthat an exception was thrown inside the try\nblock and this part caught it.\n\ne.what specifies " << e.what();
  }
  catch (exception& e) {
    // (exception& e) specifies that the exception thrown can be any exception, we can specify this., check the higherarchy https://en.cppreference.com/w/cpp/error/exception
    cerr << "other exception and e.what() returns " << e.what(); // cerr is similar to cout bit i=automatically buffers. In some outputs it may be red
    return 1; // Return an exit code: 0 is ending the code which is means the code ran normally, any other value can be an error code that can be identified
    // Most likely 0 for successful and 1 for unseccssful, in some compilers, -1 is better
  }
  catch (int code) {
    cout << "code is " << code;
  }
  catch (...) {
    cout << "this is the last resort if nothing \nbefore it is caught; it catches anyhtning";
  }
}