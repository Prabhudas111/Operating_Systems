#include <bits/stdc++.h>
using namespace std;

struct sjf{
    
    int id,at,bt,ct=0,tat,wt;
   bool visited;
};

bool cmp(sjf a,sjf b){
  if(a.at == b.at){
      if(a.bt<b.bt && (!a.visited) && (!b.visited)){
          return true;
      }
  
}
return a.at<b.at;
}

bool cmp1(sjf const &a, sjf const &b) {
    if(a.bt < b.bt ){
        return true;
    }
    return false;
}



int main(){
    
    int n;
    cout<<"No. of Processes: ";
    cin>>n;
    vector<sjf> process(n);
     
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
    vector<sjf> p;
    sjf s;
    s.id = process[0].id;
    s.at = process[0].at;
    s.bt = process[0].bt;
    s.ct = s.bt+s.at;
    s.tat = s.ct - s.at;
    s.wt = 0;
    p.push_back(s);
    vector<sjf>::iterator it = process.begin();
    process.erase(it);
    sort(process.begin(),process.end(),cmp1);
    int k=0,l=0;
   
     double avg_tat=p[0].tat,avg_wt=p[0].wt;
     int min_at = p[0].at;
     int max_ct = p[0].ct;
    while(process.size()!=0){
        
        if(process[l].at <= p[k].ct){
            
    s.id = process[l].id;
    s.at = process[l].at;
    s.bt = process[l].bt;
    s.ct =s.bt + max(p[k].ct, s.at);
    s.tat = max(s.ct - s.at ,0);
    s.wt = max(s.tat - s.bt , 0);
    
       if(s.at < min_at){
            min_at = s.at;
        }
        if(s.ct > max_ct){
            max_ct = s.ct;
        }
        
        avg_wt+=s.wt;
        avg_tat+=s.tat;
    p.push_back(s);
    it = process.begin() + l;
    process.erase(it);
    k++;
    l=0;
        }else{
            
            l++;
        }
        
    }
    
 
    cout<<"\t  Average WT  :: "<<(avg_wt/n)<<endl;
    return 0;
}
