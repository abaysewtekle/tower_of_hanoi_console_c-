#include<bits/stdc++.h>
#include<stack>
#include<cmath>
using namespace std;

void stack_to_vector(stack<int> b)
{
	vector<int> a;
	while(!b.empty())
	{
		a.push_back(b.top());
		b.pop();
	}
	reverse(a.begin(), a.end());
	for(auto it:a) cout<<it;
}
void current_stack(stack<int> a,stack<int> b,stack<int> c)
{
    cout<<"Current Stacks"<<endl;
	cout<<"Left Stack [";
	stack_to_vector(a);
	cout<<"]"<<endl;
	cout<<"Middle stack [";
	stack_to_vector(b);
	cout<<"]"<<endl;
	cout<<"Right Stack [";
	stack_to_vector(c);
	cout<<"]"<<endl<<endl;
}
char stack_to_move_from()
{
    char movefromchoice;
    cout<<"Which Stack Do you want to move from "<<endl;
	cout<<"L for Left"<<endl;
	cout<<"M for Middle"<<endl;
	cout<<"R for Right"<<'\n';
	cin>>movefromchoice;
	cout<<endl;
	return movefromchoice;
}

char stack_to_move_to()
{
    char movetochoice;
    cout<<"Which Stack Do you want to move to "<<endl;
	cout<<"L for Left"<<endl;
	cout<<"M for Middle"<<endl;
	cout<<"R for Right"<<endl;
	cin>>movetochoice;
	cout<<endl;
	return movetochoice;
}

int main()
{
	//Stack Definition
	stack<int> left;
	stack<int> middle;
	stack<int> right;
	stack<int> temp ;

	//Declarations
	int disc;
	int l,m,r;
	cout<<"_______________________________"<<endl;
	cout<<"// Lets Play Tower of Hanoi  //"<<endl;
	cout<<"_______________________________"<<endl;
	cout<<"How Many disc you want to play with"<<endl;
	cin>>disc;
	int maxtrial = (pow(2,disc)-1)+ 3;  /// Additional 3 trials
	int counter = 0;

	/// Push discs to the left stack
	for(int i=disc; i>=1; i--)
	{
		left.push(i);
	}
	temp = left; /// For Final Check
	current_stack(left,middle,right);
	cout<<endl<<endl;

	do{
        char fromchoice = stack_to_move_from();
        switch(fromchoice)
        {
			case 'L':
            case 'l':
				if(!left.empty())
				{
					l = left.top();
					left.pop();
				}
				else {
					l = 0;
					break;
				}
				break;
			case 'M':
                case 'm':
				if(!middle.empty())
				{
					m = middle.top();
					middle.pop();
				}
				else {
					m = 0;
					break;
				}
				break;

			case 'R':
			    case 'r':
				if(!right.empty())
				{
					r = right.top();
					right.pop();
				}
				else {
					r = 0;
					break;
				}
				break;
            default:
                cout<<"You Entered an Incorrect source rod "<<endl;
        }

        /// Increment counter by one since its chosen
        counter++;

        char tochoice = stack_to_move_to();
        switch(tochoice)
        {
        case 'L':
            case 'l':
            if(!left.empty())
				{
					l = left.top();
					left.pop();
				}
				else l = 0;

            ///From Left to Left
        	if(fromchoice == 'L' ||fromchoice == 'l'){
			   if(l)
			   left.push(l);
        	   cout<<"Invalid Move"<<endl<<endl;
        	   break;
        	}
        	///From Middle to Left
        	else if(fromchoice == 'M' || fromchoice == 'm') {
                if(m && l>m || l==0){
                    if(l) left.push(l);
					if(m) left.push(m);
					else cout<<"Invalid Move"<<endl;}
				else{
					left.push(l);
					if(m) middle.push(m);
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
			}
			///From right to left
			else{
                if(r && l>r || l==0){
                    if(l) left.push(l);
					if(r) left.push(r);
					else cout<<"Invalid Move"<<endl;}
				else{
                        left.push(l);
                        if(r) left.push(r);
                        if(r) right.push(r);   /// see
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
			}
        case 'M':
        case 'm':
            if(!middle.empty())
				{
					m = middle.top();
					middle.pop();
				}
				else m = 0;

				/// From Middle TO MIddle
            if(fromchoice == 'M' || fromchoice == 'm'){
				   if(m) // not zero and popped
                    middle.push(m);
            	   cout<<"Invalid Move"<<endl<<endl;
            	   break;
            	}
            	///From Left To Middle ///
        	else if(fromchoice == 'L' || fromchoice == 'l') {
                if(l && m>l || m==0){
                    if(m) middle.push(m);
					if(l) middle.push(l);
					else cout<<"Invalid Move"<<endl;}
				else{
					if(l) left.push(l);
					middle.push(m);
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
				}
				///From Right To Middle ///
        	else {
                if(r && m>r || m==0){
                    if(m) middle.push(m);
					if(r) middle.push(r);
					else cout<<"Invalid Move"<<endl;}
				else{
					right.push(r);
					middle.push(m);
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
			}
        case 'R':
            case 'r':
            if(!right.empty())
				{
					r = right.top();
					right.pop();
				}
				else r = 0;

            ///From Right To Right ///
            if(fromchoice == 'R' || fromchoice == 'r'){
				   if(r)
				       right.push(r);
            	   cout<<"Invalid Move"<<endl<<endl;
            	   break;
            	}
            ///From Left To Right
        	else if(fromchoice == 'L' || fromchoice == 'l') {
				if(l && r>l || r==0){
                    if(r) right.push(r);
					if(l) right.push(l);
					else cout<<"Invalid Move"<<endl;}
				else{
					if(l) left.push(l);
					right.push(r);
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
			}
			///From Middle to Right
        	else {
				if(m && r>m || r==0){
					if(r) right.push(r);  /// Push Back the popped value again
					if(m) right.push(m);
					else cout<<"Invalid Move"<<endl;} /// both empty case
				else{
					if(m) middle.push(m);
					if(r) right.push(r);
					cout<<"Invalid Move"<<endl<<endl;
				}
				break;
			}
        }
        current_stack(left,middle,right);

		if(temp ==  right){
			cout<<"Fantastic, You win with "<<counter<<" Moves ";
			break;
		}
	} while(counter <= maxtrial);
	if(counter > maxtrial)
		cout<<"You Tried "<<counter<<" Times and You Lose This Time May be Try another time"<<endl;
	return 0;
}
