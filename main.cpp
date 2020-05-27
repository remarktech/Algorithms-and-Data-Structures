#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
using namespace std;

struct bikes {
    // This will capture customer name, sequence ticket number and priority of each customer
    string cust_name;
    string seq_ticket;
    int priority;
    int seq_number;
    
    // this is used to initialize the variables of the class
    bikes(string cust_name, string seq_ticket ,int priority, int seq_number)
    : cust_name(cust_name), seq_ticket(seq_ticket), priority(priority), seq_number(seq_number)
    {
    }
};

//This is for sorting customer name according to prioirty of each bike
struct ComparePriority {
    bool operator()( const bikes&p1, const bikes&p2)
    {
        if(p1.priority != p2.priority)
        {
            return p1.priority > p2.priority;
        }
        else{
                return p1.seq_number > p2.seq_number;
        }
    }
};

class bikes_trans{
    public:
    // priority queue declaration for ebikes
    
    priority_queue<bikes, vector<bikes>, ComparePriority> Q;
    int seq_number = 0;
    
    int func_ebike(){
        for(int iter=0;iter<10000;iter++){
            // Take input from user whether user has input 1 or 2
            
            cout<<"\n(1) a new ebike repair order transaction\n";
            cout<<"(2) a “service” transaction\n";
            
            int i;
            cin>>i;
            
            // This is will convert the integer to ticket from 0000-9999
            
            string value;
            if (seq_number < 10)
                value = "000" + to_string(seq_number);
            
            else if (seq_number < 100)
                value = "00" + to_string(seq_number);
            
            else if (seq_number<1000)
                value = "0" + to_string(seq_number);
            
            // Checking user has given input as 1
            switch(i){
            case 1:{
                char new_ebike [100];
                long sum=0;
                
                // This will prompt error to user that queue is full.
                
                if(Q.size()>10){
                    cout<<"Error: queue is full"<<endl;
                }
                else{
                    cin>>new_ebike;
                    
                    // This will run when user inputs "end-of-file" in command prompt.
                    
                    if (strcmp(new_ebike, "end-of-file") == 0) {
                        // This will print total remaining orders in queue.
                        sum = Q.size();
                        cout<<"There are "<<sum<<" remaining repair orders in the queue.\n";
                        return 0;
                    }
                    
                    // this will split the input ebike
                    char delim[] = "-";
                    string ebike_details[3];
                    int j=0;
                    char *token = strtok(new_ebike,delim);
                    
                    while (token)
                    {
                        ebike_details[j] = token;
                        token = strtok(NULL,delim);
                        j++;
                    }
                    
                    // Checking if the ebike is in warranty then pushing priority as 1
                    
                    if(ebike_details[2]=="y")
                    {
                        Q.push(bikes(ebike_details[0],value,1,seq_number));
                    }
                    else{
                        // checking if the bike is less than 5 years taking 2018 as present year then pushing priority as 2
                        
                        if(ebike_details[1]>"2013")
                        {
                            Q.push(bikes(ebike_details[0],value,2,seq_number));
                        }
                        // this will run when ebike is not in warranty and year is more than 5 years, then pushing priority as 3
                        
                        else{
                            Q.push(bikes(ebike_details[0],value,3,seq_number));
                        }
                    }
                    seq_number++;
                }
                break;
            }
            // Checking user has given input as 2
            case 2:{
                if(Q.size()>0){
                    bikes p = Q.top();
                    Q.pop();
                    // Printing ticket number and cutomer name
                    cout<<p.seq_ticket<<endl;
                    cout<<p.cust_name<<endl;
                }
                // This will prompt error to user that queue is empty
                else{
                    cout<<"Error: queue is empty"<<endl;
                }
                    break;
            }
           default:{
                cout<<"Please enter a value input: 1 or 2"<<endl;
                continue;
            }
            
        }
        
    }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    bikes_trans obj1;
    obj1.func_ebike();
    return 0;
};
