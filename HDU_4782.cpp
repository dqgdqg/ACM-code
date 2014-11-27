#include <iostream>
using namespace std;
const string end="</html>",start="<html>";
int main () {
	int T,c,k,flag,_flag,t,i;
	string temp;
	cin>>T;
	for (t=1;t<=T;t++){
		k=0;
		flag=0;
		_flag=0;
		cout<<"Case #"<<t<<":"<<endl;
		while ((c=getchar ())){
			if ((c==32||c==9||c==10)&&!flag){
				continue;
			}
			temp="";
			temp+=c;
			if (c=='<'){
				while ((c=getchar())!='>'){
					temp+=c;
				}
				temp+=c;
				if (flag){
					flag=0;
					cout<<endl;
				}
				if (temp==start){
					cout<<temp<<endl;
					k++;
					continue;
				}
				if (temp==end){
					cout<<temp<<endl;
					break;
				}
				if (temp[1]=='/'){
					k--;
					for (i=1;i<=k;i++){
						cout<<' ';
					}
					//cout<<k<<endl;
				}
				else if (temp[temp.size()-2]!='/'){
					for (i=1;i<=k;i++){
						cout<<' ';
					}
					k++;
				}
				else {
					for (i=1;i<=k;i++){
						cout<<' ';
					}
				}
				cout<<temp<<endl;
			}
			else {
				if (!flag){
					for (i=1;i<=k;i++){
						cout<<' ';
					}
					flag=1;
					_flag=0;
				}
				if (c==9||c==10||c==32){
					_flag=1;
					continue;
				}
				if (_flag){
					cout<<' ';
				}
				putchar (c);
				_flag=0;
			}
		}
	}
	return 0;
}	
