#ifndef _GLIBCXX_USE_NANOSLEEP
#define _GLIBCXX_USE_NANOSLEEP
#endif
#include <thread>
#include <future>
#include <functional>
#include <chrono>
#include <iostream>
#include <stdlib.h>

using namespace std;

int loop(){
	cout << "loop run!\n";
	return 0;
}

int main (int argc, char * argv[]){
	cout << "main run!\n";
  future<int> newsockfd;
  try{
  	cout << "async run!\n";
    newsockfd = async(launch::async , loop);
  }
  catch(exception& rEx){
    cout << endl << typeid(rEx).name() << " caught in Active: " << rEx.what();
    exit(1);
  }
  //main client loop
  cout << "testing async result!\n";
  while(newsockfd.wait_for(chrono::seconds(0)) != future_status::ready){
    this_thread::sleep_for(chrono::nanoseconds(1));
  }

  return newsockfd.get();
}
