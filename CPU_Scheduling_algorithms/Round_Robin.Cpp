#include <bits/stdc++.h>
using namespace std;
struct Round_Robin{
    int index;
    int AT;
    int BT;
    
};
bool cmp(Round_Robin &a ,Round_Robin &b){
   
       return a.AT<b.AT;
}
int main(){
   int n;
   cout<<"Enter No. of processes: ";
   cin>>n;
   
   vector<Round_Robin>Times(n);
   unordered_map<int,int> BT;
   unordered_map<int,int> AT;
   int x, y;
   cout<<endl<<"**Enter details**"<<endl<<endl;
   cout<<"P_id: AT BT "<<endl;
   for(int i = 0 ;i< n;i++){
       Times[i].index = i+1;
       cout<<i+1<<"   : ";
       cin>> Times[i].AT;
       cin>> Times[i].BT;
       BT[i+1]=Times[i].BT;
       AT[i+1]=Times[i].AT;
   }
   int q;
   cout<<"Enter Quantum Time: ";
   cin>>q;
   
   sort(Times.begin(),Times.end(),cmp);
 
       
       int CurrentTime = 0;
       int k = n;
       bool flag = 0;
       int i =0;
       double wt = 0,tat=0;
       
       cout<<endl<<"process id:\tBT\tTAT\tWT"<<endl;
       while(k!=0){
           if(Times[i].BT<= q && Times[i].BT>0){
               CurrentTime+=Times[i].BT;
               Times[i].BT=0;
               flag = 1;
           }
           else if(Times[i].BT>0){
               Times[i].BT=Times[i].BT - q;
               CurrentTime+=q;
           }
           if(Times[i].BT== 0 && flag ){
               k--;
            cout<<"P_id : "<<i+1<<"\t"<<BT[Times[i].index]<<"\t"<<CurrentTime-AT[Times[i].index]<<"\t"<<CurrentTime-BT[Times[i].index]<<endl;
            wt+=CurrentTime-AT[Times[i].index]-BT[Times[i].index];
            
            tat+=CurrentTime-AT[Times[i].index];
            flag=0;
          
          
           }
           
           if(i == n -1 ) i =0;
           else if(Times[i+1].AT<=CurrentTime)  i++;
           else i = 0;
       }
       
   cout<<endl<<"Average waiting Time: "<<wt/n<<endl;
   cout<<"Average Turn around Time: "<<tat/n<<endl;
    return 0;
}
