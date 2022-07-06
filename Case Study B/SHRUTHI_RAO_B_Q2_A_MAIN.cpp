#include <bits/stdc++.h> 
using namespace std;
const int max_size=5;
const int pow_max_size=32;
//maxi is the probability of the most likely word
double maxi=0.0;
//Storing all the probabilities in arrays
double emiPr[5][2]={{0.10,0.30},{0.20,0.30},{0.30,0.15},{0.20,0.15},{0.2,0.1}};
double transPr[2][2]={{0.30,0.70},{0.60,0.40}};
double startPr[2]={0.60,0.40};

int arrRef[max_size];
char hold[max_size];
char ans[pow_max_size][max_size];
int nosols=0;
map <string,int> codes;
//Redirecting the words to a number using a map
void init (void){
	codes.insert(make_pair("Cojelo",0));
	codes.insert(make_pair("Con",1));
	codes.insert(make_pair("Take",2));
	codes.insert(make_pair("It",3));
	codes.insert(make_pair("Easy",4));
}
//creating a recursive function that calculates the probability of each language string
//index represents the position of the word, flag represents the language(E for true and S for false)
//size represents the number of words and temp will give the temporary probability 
void rec (int index, bool flag, int size, double temp){
    //First word in language string is multiplied by the start probability of the corresponding language
	if (index==0){
		if (flag==true) temp*=startPr[0];
		else temp*=startPr[1];
	}
	//multiplying each word by the corresponding probabilities given the language of the word
	if (flag==true){
		temp*=emiPr[arrRef[index]][0];
		hold[index]='E';
	}else{
		temp*=emiPr[arrRef[index]][1];
		hold[index]='S';
	}
    //multiplying each word by the transmission probability given the previous language
	if (index<size-1){
		if (flag==true){
			temp*=transPr[0][0];
			rec (index+1,true,size,temp);
			temp/=transPr[0][0];

			temp*=transPr[0][1];
			rec (index+1,false,size,temp);
			temp/=transPr[0][1];
		}else{
			temp*=transPr[1][0];
			rec (index+1,true,size,temp);
			temp/=transPr[1][0];

			temp*=transPr[1][1];
			rec (index+1,false,size,temp);
			temp/=transPr[1][1];
		}
	}else{
		if (temp>maxi){ //when we reach the end of the string, we use this to compare the probability with the previous maximum value
			maxi=temp;
			nosols=0;
			for (int i=0; i<size; i++) 
    			ans[nosols][i]=hold[i];
    		nosols++;
		}else if (temp==maxi)
		{
			for (int i=0; i<size; i++) ans[nosols][i]=hold[i];
			nosols++;
		}
	}
	return;
}

int main ()
{
	int cap=0;
	init ();
    //the input is taken as a string
	string s;
	getline(cin,s);
	//the words are redirected using a map and an array is created by the redirected values
	//the string help holds an individual word until it is redirected
	for (int i=0; i<s.size(); i++){
		string help="";
		while (i<s.size() && s[i]!=' '){
			help.push_back (s[i]);
			i++;
		}
		arrRef[cap++]=codes[help];
	}
	s.clear();
	//the recursive function is called twice for words starting with english and spanish
	rec (0,true,cap,1.0);
	rec (0,false,cap,1.0);
	//output is printed, after rounding off upto five decimal spaces, in the specified format asked
	for (int i=0; i<nosols; i++){
		for (int j=0; j<cap; j++)
		cout << ans[i][j] << " " ;
	    cout << ": " << fixed << setprecision(5) << maxi << endl;
	}
	codes.clear();
	return 0;
}