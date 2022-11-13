//FCFS


#include <bits/stdc++.h>
using namespace std;

struct fcfs{
    
    int id,at,bt,ct=0,tat,wt;
  
};
bool cmp(fcfs a,fcfs b){
  if(a.at == b.at){
      if( a.id>b.id){
          return false;
      }else {
          return true;
      }
  }
  return a.at<b.at;
}
int main(){
    
    int n;
    cout<<"No. of Processes: ";
    cin>>n;
    vector<fcfs> process(n);
     
    cout<<endl<<"P :AT"<<" BT"<<endl;
    for(int i = 0 ;i<n;i++){
        int at,bt;
        cout<<"p"<<i+1<<":";
        process[i].id=i+1;
        cin>>at;
        process[i].at=at;
        cin>>bt;
        process[i].bt=bt;
        
        
    }
    
    sort(process.begin(),process.end(),cmp);
    process[0].ct=process[0].at+process[0].bt;
    process[0].tat = process[0].ct -process[0].at;
    process[0].wt=0;
    
     double avg_tat=process[0].tat,avg_wt=process[0].wt;
     int min_at = process[0].at;
     int max_ct = process[0].ct;
    for(int i = 1;i<n;i++){
        process[i].ct = max(process[i].ct+process[i-1].ct+process[i].bt,process[i].at+process[i].bt);
        process[i].tat = max (process[i].ct - process[i].at , 0);
        process[i].wt = max (process[i].tat - process[i].bt , 0);
        
        if(process[i].at < min_at){
            min_at = process[i].at;
        }
        if(process[i].ct > max_ct){
            max_ct = process[i].ct;
        }
        
        avg_wt+=process[i].wt;
        avg_tat+=process[i].tat;
    }
    
    cout<<endl<<"\t\t*FCFS*"<<endl;
    cout<<"------------------------------------------"<<endl;
    
  cout<<"process"<<"\tAT"<<"\tBT"<<"\tCT"<<"\tTAT"<<"\tWT"<<endl;
   cout<<"------------------------------------------"<<endl;

     for(int i = 0 ;i<n;i++){
        cout<<"p"<<process[i].id<<": \t"<<process[i].at<<"\t"<<process[i].bt<<"\t"<<process[i].ct<<"\t"<<process[i].tat<<"\t"<<process[i].wt<<endl;
        
    }
      
       cout<<endl<<"\t  Average TAT :: "<<(avg_tat/n)<<endl;
    cout<<"\t  Average WT  :: "<<(avg_wt/n)<<endl;
    cout<<"\t  Total completion time  :: "<<(max_ct - min_at)<<endl;
    cout<<"\t  Throughput  :: "<<((float)n/(max_ct - min_at))<<endl;
    return 0;
}
