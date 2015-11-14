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

int loop(int i){
	cout << i << " loop run!\n";
	for(int i = 0; i < 2000000000; i++);
	cout << i << " loop end!\n";
	return 0;
}

int main (int argc, char * argv[]){
	cout << "main run!\n";
  future<int> newsockfd[4];
  for(int i = 0; i < 4; i++){
		try{
			newsockfd[i] = async(launch::async , loop, i);
		}
		catch(exception& rEx){
			cout << endl << typeid(rEx).name() << " caught in Active: " << rEx.what();
			exit(1);
		}
  }
  //main loop
  cout << "testing async result!\n";
  int i = 0;
  while(i < 4){
    for(i = 0; i < 4; i++){
    	if(newsockfd[i].wait_for(chrono::seconds(0)) != future_status::ready) break;
    }
    this_thread::sleep_for(chrono::nanoseconds(1));
  }

  int total = 0;
  for(int i = 0; i < 4; i++){
  	total += newsockfd[i].get();
  }
  return total;
}
