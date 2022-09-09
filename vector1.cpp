
#include<iostream>
#include<vector>

using namespace std;

class VectorClass {
	private: 
		int totalNumber;
		vector<int> v;
		vector<int>::iterator it;
	public:
		VectorClass(int n);
		
		void takeInputVector(){
			for(int i=0;i<this->totalNumber;i++){
				int test;
				cin>>test;
				this->v.push_back(test);
			} 
		}
		
		void printVector(){
			 			
			for(it = this->v.begin();it!=this->v.end();it++){
				cout<<*it<<endl;
			}	
		}
		
		int countElement(int n){
			int countVar = 0;
			for(it = this->v.begin();it!=this->v.end();it++){
				if(*it == n){
					countVar++;
				}
			}
			return countVar;	
		}
};

VectorClass::VectorClass(int n){
	totalNumber = n;
	//vector<int> v(n, 0);
}




int main(){
	
   
    int n;
    cin>>n;
    VectorClass vc(n);
   
	vc.takeInputVector();
	
	std::vector<int> vector2(n, 0);
	
	
	
	
	//vc.printVector();
	int q;
	cin>>q;
	for(int i=0 ; i<q ;i++){
		int testCase;
		cin>>testCase;
		int countAns = vc.countElement(testCase);
		if(countAns == 0){
			cout<<"NOT PRESENT"<<endl;
		}else{
			cout<<countAns<<endl;
		}
	}
    
    return 0;
}
