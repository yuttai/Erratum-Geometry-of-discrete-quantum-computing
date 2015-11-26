/* This file is tested in GCC 4.9.3 in Cygwin64, and Visual Studio 2013.
 * */
#ifndef _GLIBCXX_USE_NANOSLEEP
#define _GLIBCXX_USE_NANOSLEEP
#endif
#include <future>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <vector> 
#include <functional>

using namespace std;

int cModp$(const int z, const int p){return [](const int m, const
int n, const int d){return d + (m - d) % n;}(z, p, ((1 + (-1 * p)) /
2));}

int loop(const int loopNum, const int time){
	if(loopNum >= 0) cout << loopNum << " loop run!\n";
	for(int j = 0; j < time; j++);
	if(loopNum >= 0) cout << loopNum << " loop end!\n";
	return 0;
}

int parallel(const int numberJobs, const int time, const bool echo, const bool test){
	cout << "parallel run with " << numberJobs << " of jobs. \n";
	vector<future<int>> jobs(numberJobs);
	for(int i = 0; i < numberJobs; i++){
		try{
			jobs[i] = async(launch::async , loop, (echo ? i : -1), time);
		}
		catch(exception& rEx){
			cout << endl << typeid(rEx).name() << " caught in Active: " << rEx.what();
			exit(1);
		}
  }

  if(test){
		//main loop
		cout << "testing async result!\n";
		int i = 0;
		while(i < numberJobs){
			for(i = 0; i < numberJobs; i++){
				if(jobs[i].wait_for(chrono::seconds(0)) != future_status::ready) break;
			}
			this_thread::sleep_for(chrono::nanoseconds(1));
		}
  }

  cout << "When finish\n";
  int total = 0;
  for(int i = 0; i < numberJobs; i++){
  	total += jobs[i].get();
  }
  cout << total << "\n";
  return total;
}

int main (int argc, char * argv[]){
/*	parallel(4, 2000000000, true, false);
	parallel(20000, 100000, false, false);*/
	cout << cModp$(0, 3) << " " << cModp$(1, 3) << " " << cModp$(2, 3);
	return 0;
}
